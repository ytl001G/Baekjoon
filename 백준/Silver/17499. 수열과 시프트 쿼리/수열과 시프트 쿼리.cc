#include <iostream>
#include <vector>

using namespace std;

int numbers[200000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    int op, x, y;
    int p = 0;
    for (int i = 0; i < q; i++)
    {
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            numbers[(p+x-1)%n] += y;
        } else if (op == 2) {
            cin >> x;
            p = (p + n - x)%n;
        } else if (op == 3) {
            cin >> x;
            p = (p + x)%n;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << numbers[(p+i)%n] << " ";
    }
    
    return 0;
}