#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;
    
    int x, y;
    for (int i = 0; i < T; i++){
        cin >> x >> y;
        int delta = y-x;
        double root = sqrt(static_cast<double>(delta-1));
        int integer_part = static_cast<int>(root);
        
        if (delta <= integer_part * integer_part + integer_part){
            cout << 2*integer_part << '\n';
        } else {
            cout << 2*integer_part+1 << '\n';
        }
    }
    return 0;
}