#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int A[1000000], B[1000000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
 
    string DNA;
    cin >> DNA;
    
    if (DNA[0] == 'A'){
        B[0] = 1;
    } else {
        A[0] = 1;
    }
    
    for (int i = 1; i < n; i++){
        if (DNA[i] == 'A'){
            A[i] = A[i-1];
            B[i] = min(B[i-1]+1, A[i-1]+1);
        } else {
            B[i] = B[i-1];
            A[i] = min(B[i-1]+1, A[i-1]+1);
        }
    }
    
    cout << A[n-1];

    return 0;
}
