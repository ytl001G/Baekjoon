#include <iostream>
using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    int ans = 0;
    int start;
    while (1)
    {
        if (m & 1) {
            if (n % m == 0) {
                // n = 6, m = 3 => 1,2,3
                // 0,1,2 n = 3 m = 3
                if (n / m - m / 2 >= 0) {
                    ans = 1;
                    start = n / m - m / 2;
                }
                break;
            }
        } else {
            if (n % m * 2 == m) {
                // n = 6, m = 4 => 0,1,2,3
                if (n / m - m / 2 + 1 >= 0) {
                    ans = 1;
                    start = n / m - m / 2 + 1;
                }
                break;
            }
        }

        m++;
        if (m > 100) break;
    }

    if (ans) {
        for (int i = start; i < start + m; i++)
        {
            cout << i << " ";
        }
    } else cout << -1;

    return 0;
}