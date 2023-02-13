#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int A[1000], B[1000], C[1000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    A[0]=0;
    A[1]=0;
    A[2]=2;
    
    B[0]=0;
    B[1]=1;
    B[2]=2;
    
    C[0]=0;
    C[1]=0;
    C[2]=1;
    
    for (int i = 3; i <= 1000; i++){
        A[i] = B[i-2] + (A[i-2] + B[i-2] + C[i-2])*2;
        B[i] = A[i-1] + 2*B[i-1] + C[i-1];
        C[i] = A[i-2] + B[i-2] + 2*C[i-2];
    }
    
    int T;
    cin >> T;
    while (T--){
        int t;
        cin >> t;
        cout << A[t]+B[t]+C[t] << endl;
    }
    
    return 0;
}
