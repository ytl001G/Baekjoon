#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define ll long long

struct Register {
    int d1, d2, d3, d4;
    
    Register() : d1(0), d2(0), d3(0), d4(0) {}
    
    Register(int value) {
        d1 = value / 1000;
        value %= 1000;
        d2 = value / 100;
        value %= 100;
        d3 = value / 10;
        value %= 10;
        d4 = value;
    }
    
    int value() {
        return 1000 * d1 + 100 * d2 + 10 * d3 + d4;
    }
    
    Register D() {
        return Register((value() * 2) % 10000);
    }
    
    Register S() {
        return Register((value() - 1 + 10000) % 10000);
    }
    
    Register L() {
        return Register((value() % 1000) * 10 + value() / 1000);
    }
    
    Register R() {
        return Register((value() % 10) * 1000 + value() / 10);
    }
};

void find_route(int init, int fin) {
    queue<Register> q;
    bool visited[10000] = {0};
    pair<int, char> parent[10000];
    char act[4] = {'D', 'S', 'L', 'R'};
    
    Register A = Register(init);
    string ans = "";
    
    q.push(A);
    visited[A.value()] = true;
    
    while (!q.empty()) {
        Register current = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            Register next;
            if (i == 0) {
                next = current.D();
            } else if (i == 1) {
                next = current.S();
            } else if (i == 2) {
                next = current.L();
            } else if (i == 3) {
                next = current.R();
            }

            if (!visited[next.value()]) {
                parent[next.value()].first = current.value();
                parent[next.value()].second = act[i];

                q.push(next);
                visited[next.value()] = true;
            }
            
            if (next.value() == fin) {
                int current_value = next.value();
                while (current_value != init) {
                    ans = parent[current_value].second + ans;
                    current_value = parent[current_value].first;
                }
                
                cout << ans << endl;
                return;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int i, f;
    for (int _ = 0; _ < n; _++) {
        cin >> i >> f;
        find_route(i, f);
    }
}