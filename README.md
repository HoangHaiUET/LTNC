[[English]](README_en.md)

# Try Catch - HoangHaiUET

- Thử nghiệm game: [............................](.......)

# Giới thiệu game

Try_Catch là 1 game thuộc thể loại game thiếu nhi . Nhiệm vụ của bạn là điều khiển chú mèo máy Doraemon tới những vị trí thích hợp để nhặt được những chiếc bánh đồng thời né tránh những quả bom gây nguy hiểm cho Doraemon . Hãy cố gắng hết sức để đem về số điểm cao nhất  

- [0. Cách tải game](#0-cách-tải-game)
    * [ Bao gồm code và có thể biên dịch.](#bao-gồm-code-và-có-thể-biên-dịch)
- [1. Bắt đầu game](#1bắt-đầu-game)
- [2. Các thành phần trong game:](#2-các-thành-phần-trong-game)
- [3. Cách chơi](#3-cách-chơi)
- [4. Kết thúc game](#4-kết-thúc-game)
- [Về đồ họa của game:](#về-đồ-họa-của-game)
- [Về source code game](#về-source-code-game)

# 0. Cách tải game

## Bao gồm code và có thể biên dịch.

**Bước 1:** Clone repo này về . <br/>
Hoặc Chọn Code -> Download Zip 

![image](resources/preview/download.123)

- Tất cả code đều nằm trong thư mục src.<br/>
- Có thể nhảy đến bước 5 để chơi luôn.

**Bước 2:** Vào thư mục Debug tìm đến thư mục `GameSDLCppDemo.exe` .<br/>


# 1. Bắt đầu game

Chờ một chút rồi click vào nút “PLAY GAME” để bắt đầu chơi game.
<div style="text-align: center;">

![ezgif com-video-to-gif](resources/preview/menu.png)




Và người chơi sẽ ngay lập tức nhìn thấy mèo máy Doraemon 
<div style="text-align: center;">

![image](resources/preview/object.png)

</div>

# 2. Các thành phần trong game:

-    Bánh doyaki ![image](resources/preview/doyaki.png)
     : là 1 loại bánh trong game

-    Bánh ngọt ![image](resources/preview/cake.png)
     : là 1 loại bánh trong game

-   Bánh takoyaki ![image](resources/preview/takoyaki.png)

-  Ngôi sao (Star) ![image](resources/preview/star.png)
<div style="text-align: center;">


- Bomb : Là mối nguy trong game , khi chạm phải bạn sẽ thua cuộc

<div style="text-align: center;">

![image](resources/preview/bom.png)
</div>

- Thanh điểm (mark bar): Là thanh bạn có thể theo dõi để xem điểm số bạn tích luỹ sau khi nhặt được những chiếc bánh

<div style="text-align: center;">

![image](resources/preview/mark_bar.jpg)
</div>
- Thanh mạng (heart bar): là thanh mạng của bạn nếu hết mạng thì bạn thua
<div style="text-align: center;">

![image](resources/preview/heart_bar.jpg)
</div>

- Bố cục game cơ bản:

<div style="text-align: center;">

![image](resources/preview/first_game.jpg)
</div>

 

# 3. Cách chơi

Dựa vào nút di chuyển -> hoặc <- để di chuyển Doraemon của bạn tới những vị trí thích hợp để nhặt những chiếc bánh.<br/>

# 4. Chiến thắng và thất bại

- Bạn sẽ thất bại nếu va chạm với quả bom hoặc hết 3 mạng mặc định

<div style="text-align: center;">

![image](resources/preview/bkexit.png)
</div>

---

### Về đồ họa của game:

[[Google - Canva]]

### Về source code game:

- Folder SDL Lib:<br/>
    * Chứa các thư viện SDL : SDL_image, SDL_Ttf, SDL_Mixer,SDL ,DLL<br/>
- Folder Debug: Chứa tất cả các thành phần của game:<br/>
    * Chứa các tài nguyên của game : Hình ảnh , thư viện , font chữ trong game <br/>
- Folder GameSDLCPPDemo: Chứa các file header và file cpp <br/>
    *`BaseObject.h` và `BaseObject.cpp`:<br/>
        + File khởi tạo các đối tượng chung trong game : Nhân vật , các loại bánh <br/>
        + Khởi tạo hàm Show ảnh của đối tượng trên BackGround game <br/>
        + Cài đặt vị trí của các đối tượng thông qua `SDL_Rect` <br/>
        + Các hàm Set và Get `SDL_Rect` <br/>
    *`CakeObject.h` và `CakeObject.cpp`: <br/>
        + Khởi tạo các Cake (có thể coi là các threat trong game)<br/>
        + Hàm di chuyển các `Cake` <`HandleMove`> dựa vào `y_val` và có thể set trong main.cpp 
    *`Common_Function.h` và `Common_Function.cpp`:<br/>
        + Đây là file nguồn chứa tất cả các thư viện và các hàm chung cơ bản nhất được sử dụng trong tất cả các đối tượng <br/>
        + Khởi tạo màn hình Game < Window > cài đặt kích thước cửa sổ , quản lý tên các đối tượng trong project<br/>
        + Khởi tạo các hàm `LoadImage` , `CleanUp` , `CheckCollision` < Xử lí va chạm> , `ShowMenu`<br/>
    *`ExplosionObject.h` và  `ExplosionObject.cpp` : Cài đặt hình ảnh khi va chạm (Cụ thể là bom nổ) <br/>
    *`MainObject.h` và `MainObject.cpp` : <br/>
        + Khởi tạo nhân vật của game , cài đặt các thuộc tính cho nhân vật <br/>
        + Hàm xử lý bắt sự kiện từ bàn phím `SDL_Event`<br/>
    *`PlayerPower.h` và `PlayerPower.cpp` : Khởi tạo các heart (mạng của nhân vật) , xử lí hình ảnh khi thêm , bớt<br/>
    *`TextObject.h`và `TextObject.cpp` : Cài đặt Font chữ trong game và các đối tượng cần hiện Text<br/>
    *`main.cpp` : Xử lý chung trong game<br/>
        + Khởi tạo cửa sổ màn hình <br/>
        + Khởi tạo nhân vật , bánh , bom (threats) <br/>
        + Khởi tạo các Text<br/>
        + Load các hình ảnh : BackGround , human_object , Cake_object , Menu , Exit<br/> 
        + Load các Text , load Explosion <br/>
        + Xử lí luật chơi : Khi va chạm sẽ được tăng điểm trên thanh điểm , khi va chạm phải bomb hoặc hết mạng thì sẽ bị tính là thua cuộc <br/>
        + Khi va chạm , các Cake_Object sẽ được Reset <br/>
        + Xử lí bộ nhớ sau khi thoát game <br/>

`Luật chơi`<br/>
        *   Di chuyển Doraemon tới những chiếc bánh và tránh xa những quả bomb<br/>
        *   Khi va chạm phải quả bomb hoặc hết mang bạn sẽ thua <br/>
        *   Bắt được 1 chiếc bánh sẽ được 30 điểm , 50 điểm nhưng khi để rơi 1 chiếc bánh sẽ mất 1 mạng <br/>
        *   Khi không bắt được ngôi sao hy vọng bạn sẽ không bị trừ mạng
        *   Ngôi sao hi vọng sẽ chỉ mang về cho bạn 10 điểm nhưng tích đủ 10 ngôi sao sẽ hồi phục 1 mạng <br/>
        *   Việc đột ngột di chuyển ngược chiều sẽ khiến Doraemon bị đứng lại do `quán tính` <br/>
        *  Thua cuộc trong trạng thái đang di chuyển sẽ khiến Doraemon gặp trục trặc về bộ nhớ ở vòng chơi sau , bạn cần giữ nút di chuyển và thả nút di chuyển để Doraemon tỉnh lại <br/>