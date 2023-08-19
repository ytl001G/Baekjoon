#include <stdio.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int A[10001] = {0};
    
    for(int i = 0; i < n; i++){
        int p;
        scanf("%d", &p);
        A[p]++;
    }
    
    for(int i = 1; i < 10001; i++){
        for(int j = 0; j < A[i]; j++){
            printf("%d\n", i);
        }
    }

    return 0;
}
