#include <iostream>
#include <string>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define iin(i) int i; cin >> i;
#define loop(n) FOR(i,0,n)

using namespace std;

char toCap(char c){
    if ('a' <= c && c <= 'z'){
        return c - 'a' + 'A';
    }
    else return c;
}

int main() {
    FASTIO;

    int count[26] = {0,};

    string str;
    cin >> str;

    int max = 0;
    FOR(i,0,str.size()){
        char c = toCap(str[i]);
        count[c-'A'] += 1;

        if (max < count[c-'A'])
            max = count[c-'A'];
    }

    char maxAlpha = 0;
    FOR(i,0,26){
        if (max == count[i]){
            if (maxAlpha == 0)
                maxAlpha = i + 'A';
            else {
                cout << '?';
                return 0;
            }
        }
    }

    cout << maxAlpha;

    return 0;
}