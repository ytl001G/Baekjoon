#include <iostream>
using namespace std;

int main()
{
    int N, r, c;
    cin >> N >> r >> c;
    
    int up, left, half;
    int ans, addans;
    ans = 0;
    
    while (N >= 1) {
        half = 1 << (N-1);
        addans = half * half;
        up = r < half;
        left = c < half;
        
        if (up && left) {
        } else if (up && !left) {
            ans += addans;
            c -= half;
        } else if (!up && left) {
            ans += addans * 2;
            r -= half;
        } else {
            ans += addans * 3;
            r -= half;
            c -= half;
        }
        
        N -= 1;
    }

    cout << ans;
    return 0;
}