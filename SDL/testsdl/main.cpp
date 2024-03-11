#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include <random>

// Define constants
const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;
const int LANE_WIDTH = 100;
const int ROAD_WIDTH = 300;
const int MARKER_WIDTH = 10;
const int MARKER_HEIGHT = 50;
const int PLAYER_SPEED = 5;
const int VEHICLE_SPEED = 2;

// Vehicle class
class Vehicle {
public:
    Vehicle(SDL_Texture* tex, int x, int y) : texture(tex), posX(x), posY(y) {}

    void moveDown() {
        posY += VEHICLE_SPEED;
    }

    SDL_Rect getRect() {
        return { posX, posY, width, height };
    }

    void render(SDL_Renderer* renderer) {
        SDL_Rect dstRect = { posX, posY, width, height };
        SDL_RenderCopy(renderer, texture, NULL, &dstRect);
    }

private:
    SDL_Texture* texture;
    int posX, posY;
    int width = 50; // Adjust the width of the vehicle as needed
    int height = 100; // Adjust the height of the vehicle as needed
};

int main(int argc, char* args[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("Car Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Load player texture
    SDL_Surface* playerSurface = IMG_Load("car.png");
    SDL_Texture* playerTexture = SDL_CreateTextureFromSurface(renderer, playerSurface);
    SDL_FreeSurface(playerSurface);

    // Load vehicle textures
    std::vector<SDL_Texture*> vehicleTextures;
    vehicleTextures.push_back(SDL_CreateTextureFromSurface(renderer, IMG_Load("pickup_truck.png")));
    vehicleTextures.push_back(SDL_CreateTextureFromSurface(renderer, IMG_Load("semi_trailer.png")));
    vehicleTextures.push_back(SDL_CreateTextureFromSurface(renderer, IMG_Load("taxi.png")));
    vehicleTextures.push_back(SDL_CreateTextureFromSurface(renderer, IMG_Load("van.png")));

    // Load crash texture
    SDL_Surface* crashSurface = IMG_Load("crash.png");
    SDL_Texture* crashTexture = SDL_CreateTextureFromSurface(renderer, crashSurface);
    SDL_FreeSurface(crashSurface);

    // Set up game variables
    bool quit = false;
    int playerX = SCREEN_WIDTH / 2;
    int playerY = SCREEN_HEIGHT - 100;
    int score = 0;
    std::vector<Vehicle> vehicles;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> laneDist(0, 2);
    std::uniform_int_distribution<> vehicleDist(0, vehicleTextures.size() - 1);

    while (!quit) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        if (playerX > LANE_WIDTH)
                            playerX -= PLAYER_SPEED;
                        break;
                    case SDLK_RIGHT:
                        if (playerX < SCREEN_WIDTH - LANE_WIDTH)
                            playerX += PLAYER_SPEED;
                        break;
                }
            }
        }

        // Move vehicles
        for (auto& vehicle : vehicles) {
            vehicle.moveDown();
            if (vehicle.getRect().y > SCREEN_HEIGHT) {
                vehicles.erase(vehicles.begin());
                score++;
            }
        }

        // Add new vehicle
        if (vehicles.empty() || vehicles.back().getRect().y > SCREEN_HEIGHT / 4) {
            int lane = laneDist(gen) * LANE_WIDTH + LANE_WIDTH / 2;
            SDL_Texture* vehicleTexture = vehicleTextures[vehicleDist(gen)];
            vehicles.emplace_back(vehicleTexture, lane, -50);
        }

        // Check collision
        for (auto& vehicle : vehicles) {
            if (SDL_HasIntersection(&vehicle.getRect(), &(SDL_Rect{ playerX, playerY, 50, 100 }))) {
                quit = true; // Collision occurred
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        // Draw road
        SDL_SetRenderDrawColor(renderer, 0x80, 0x80, 0x80, 0xFF);
        SDL_Rect roadRect = { (SCREEN_WIDTH - ROAD_WIDTH) / 2, 0, ROAD_WIDTH, SCREEN_HEIGHT };
        SDL_RenderFillRect(renderer, &roadRect);

        // Draw markers
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
        for (int i = LANE_WIDTH / 2 - MARKER_WIDTH / 2; i <= SCREEN_WIDTH - LANE_WIDTH / 2; i += LANE_WIDTH) {
            SDL_Rect markerRect = { i - MARKER_WIDTH / 2, 0, MARKER_WIDTH, MARKER_HEIGHT };
            SDL_RenderFillRect(renderer, &markerRect);
        }

        // Draw vehicles
        for (auto& vehicle : vehicles) {
            vehicle.render(renderer);
        }

        // Draw player
        SDL_Rect playerRect = { playerX, playerY, 50, 100 };
        SDL_RenderCopy(renderer, playerTexture, NULL, &playerRect);

        // Display score
        SDL_Color textColor = { 0xFF, 0xFF, 0xFF };
        SDL_Surface* scoreSurface = TTF_RenderText_Solid(scoreFont, ("Score: " + std::to_string(score)).c_str(), textColor);
        SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
        SDL_FreeSurface(scoreSurface);
        SDL_Rect scoreRect = { 20, 20, 100, 30 };
        SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);
        SDL_DestroyTexture(scoreTexture);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(playerTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
