#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define endl "\n"

using namespace std;

char **window;

void printspace(int n, int x, int y){
    if (n == 3){
        FOR(i,0,3){
            FOR(j,0,3){
                window[x+j][y+i] = ' ';
            }
        }
        return;
    }

    printspace(n/3,x+0,y+0);
    printspace(n/3,x+n/3,y+0);
    printspace(n/3,x+n/3*2,y+0);
    printspace(n/3,x+0,y+n/3);
    printspace(n/3,x+n/3,y+n/3);
    printspace(n/3,x+n/3*2,y+n/3);
    printspace(n/3,x+0,y+n/3*2);
    printspace(n/3,x+n/3,y+n/3*2);
    printspace(n/3,x+n/3*2,y+n/3*2);
}

void print(int n, int x, int y){
    if (n == 3){
        FOR(i,0,3){
            FOR(j,0,3){
                window[x+j][y+i] = (i == 1 && j == 1) ? ' ' : '*';
            }
        }
        return;
    }

    print(n/3,x+0,y+0);
    print(n/3,x+n/3,y+0);
    print(n/3,x+n/3*2,y+0);
    print(n/3,x+0,y+n/3);
    printspace(n/3,x+n/3,y+n/3);
    print(n/3,x+n/3*2,y+n/3);
    print(n/3,x+0,y+n/3*2);
    print(n/3,x+n/3,y+n/3*2);
    print(n/3,x+n/3*2,y+n/3*2);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    window = new char *[n];
    FOR(i,0,n){
        window[i] = new char[n];

        FOR(j,0,n){
            window[i][j] = 0;
        }
    }

    print(n,0,0);

    FOR(i,0,n){
        FOR(j,0,n){
            cout << window[j][i];
        }
        cout << endl;
    }

    return 0;
}