#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define iin(i) int i; cin >> i;
#define loop(n) int x = n; while(x--)

using namespace std;

void comb(vector<vector<int>> &storage, vector<int> now, int n, int k){
    if (k == 0){
        storage.push_back(now);
    }

    if (n < k || n <= 0 || k <= 0){
        return;
    }

    comb(storage, now, n-1, k);
    now.push_back(n-1);
    comb(storage, now, n-1, k-1);

}

int main() {
    FASTIO;

    iin(n);
    loop(n){
        vector<vector<int>> points;
        iin(m)
        loop(m){
            iin(x); iin(y);
            vector<int> now;
            now.push_back(x);
            now.push_back(y);

            points.push_back(now);
        }

        vector<vector<int>> halfs;
        vector<int> start;
        comb(halfs, start, m, m/2);

        long double min = 1e100;
        long double dist;
        FOR(i,0,halfs.size()){
            ll x = 0, y = 0;

            FOR(j,0,m){
                if(find(halfs[i].begin(), halfs[i].end(), j) != halfs[i].end()) {
                    x += points[j][0];
                    y += points[j][1];
                } else {
                    x -= points[j][0];
                    y -= points[j][1];
                }
            }

            dist = sqrt(static_cast<double>(x*x + y*y));
            if (dist < min) min = dist;
        }

        cout << std::fixed;
        cout.precision(12);
        cout << min << "\n";
    }

    return 0;
}