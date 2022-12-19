#include <iostream>
#include <cmath>
using namespace std;

int abs(int x) {
    if (x < 0) x = -x;
    return x;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int intlen(int n){
    float i = 1.0;
    while (1) {
        if (pow(10.0, i) > n) {
            return (int)i;
        }
        i++;
    }
}

int sparcle(int x, int y) {
    int max;
    if (abs(x) > abs(y)) {
        max = abs(x);
    } else {
        max = abs(y);
    }

    if (y == max) {
        return (2*max+1)*(2*max+1) + x - max;
    } else if (-x == max) {
        return (2*max+1)*(2*max+1) - 2*max + y - max;
    } else if (-y == max) {
        return (2*max+1)*(2*max+1) - 4*max - x - max;
    } else if (x == max) {
        return (2*max+1)*(2*max+1) - 6*max - y - max;
    }
}

int main() {
    int r1,c1,r2,c2;

    cin >> r1 >> c1 >> r2 >> c2;

    int m = max(max(intlen(sparcle(c1, r1)), intlen(sparcle(c2, r1))), max(intlen(sparcle(c1, r2)), intlen(sparcle(c2, r2))));

    for (int i = r1; i <= r2; i++)
    {
        for (int j = c1; j <= c2; j++)
        {
            if (j != c1)
            {
                cout << " ";
            }
            int r = sparcle(j, i);
            for (int x = 0; x < (m - intlen(r)); x++)
            {
                cout <<  " ";
            }
            cout << r;
        }
        if (i != r2) {
            cout << endl;
        }
    }
    return 0;
}