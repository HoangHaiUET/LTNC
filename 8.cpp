#include <bits/stdc++.h>
using namespace std;

int a[1000001];
int thaotac[100001];

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    // Read the elements of array 'a[]'
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Initialize all elements of thaotac[] to 1
    fill_n(thaotac, m+1, 1);

    // Process 'm' operations (not implemented in the current code)
    while (m--) {
        int l, r, d;
        cin >> l >> r >> d;
        // Perform operation here
    }

    // Perform 'k' repetitions of operations
    while (k--) {
        int x, y;
        cin >> x >> y;
        for (int i = x; i <= y; i++) {
            thaotac[i]++;
        }
    }

    // Print the number of times each operation was performed
    for (int i = 1; i <= m; i++) {
        cout << thaotac[i] << " ";
    }

    return 0;
}

