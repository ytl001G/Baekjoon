#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef ll pattern[50];

void intersect(pattern p1, pattern p2, pattern p) {
    for (int i = 0; i < 50; i++) {
        p[i] = p1[i] & p2[i];
    }
}

void makePattern(string str, pattern p) {
    ll len = str.size();
    for (int i = 0; i < len; i++) {
        char now = str[i];
        if (now == '?') {
            p[i] = -1;
        } else {
            p[i] = 1 << (now - 'a');
        }
    }
}

ll findStr(pattern p, ll len) {
    ll ans = 1;
    for (int i = 0; i < len; i++) {
        if (p[i] == -1) {
            ans *= 26;
            ans %= 1000003;
        } else if (p[i] == 0) {
            return 0;
        }
    }
    return ans;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    
    pattern patterns[15];
    for (int i = 0; i < 15; i++) {
        memset(patterns[i], 0, 50);
    }
    string temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        makePattern(temp, patterns[i]);
    }
    ll patternLength = temp.size();
    
    // k, ... , n까지 계산. +-+-+-+-
    struct Node {
        ll value;
        ll layer;
        pattern p;
    };    

    Node curr; //value, layer, pattern
    curr.value = 0;
    curr.layer = 0;
    for (int i = 0; i < 50; i++) {
        curr.p[i] = -1;
    }
    queue<Node> q;
    bool visited[1 << 15] = {0};
    ll layerVlaue[16] = {0};
    q.push(curr);

    while(!q.empty()) {
        curr = q.front();
        q.pop();
        
        for (int i = 0; i < n; i++) {
            if (!(curr.value & (1 << i)) && !visited[curr.value | (1 << i)]) {
                Node next;
                next.value = curr.value | (1 << i);
                next.layer = curr.layer + 1;
                intersect(curr.p, patterns[i], next.p);
                layerVlaue[next.layer] += findStr(next.p, patternLength);
                layerVlaue[next.layer] %= 1000003;
                // cout << layerVlaue[next.layer] << '\t' << next.layer << '\t' << next.value << endl;
                q.push(next);
                visited[next.value] = true;
            }
        }
    }

    ll comp[16][16] = {0};
    comp[0][0] = 1;
    for (int i = 1; i < 16; i++) {
        comp[i][0] = 1;
        comp[i][i] = 1;
        for (int j = 1; j < i; j++) {
            comp[i][j] = (comp[i-1][j-1] + comp[i-1][j])%1000003;
        }
    }
    
    ll mult[16] = {0};
    for (int i = n; i >= k; i--) {
        mult[i] = layerVlaue[i];
        if (i != n) {
            for (int j = 0; j < n-i; j++) {
                mult[i] -= comp[n-j][n-i-j] * mult[n-j];
                mult[i] %= 1000003;
            }
        }
        // cout << layerVlaue[i] << '\t' << i << '\t' << mult[i] << endl;
    }

    cout << (mult[k] + 1000003) % 1000003;
    return 0;
}