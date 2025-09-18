#include <iostream>
using namespace std;
#define ll long long

int main()
{
    // (x1 + (x2-x1)t, y1 + (y2-y1)t)
    // (x3 + (x4-x3)s, y3 + (y4-y3)s)
    // (x2-x1)t - (x4-x3)s = x3-x1
    // (y2-y1)t - (y4-y3)s = y3-y1
    //
    // d -b e
    // -c a f
    
    ll x1,x2,x3,x4;
    ll y1,y2,y3,y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    
    ll a, b, c, d, e, f;
    a = x2-x1;
    b = -(x4-x3);
    c = y2-y1;
    d = -(y4-y3);
    e = x3-x1;
    f = y3-y1;
    
    ll det = a*d - b*c;
    
    if(det == 0) {
        cout << 0;
    }
    
    if(det > 0) {
        cout << (0 <= d*e-b*f && d*e-b*f <= det && 0 <= -c*e+a*f && -c*e+a*f <= det);
    }
    
    if(det < 0) {
        cout << (0 >= d*e-b*f && d*e-b*f >= det && 0 >= -c*e+a*f && -c*e+a*f >= det);
    }
}