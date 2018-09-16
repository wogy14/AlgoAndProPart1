#include <stdio.h>

int main()
{
    int n,m,res1,res2,res3;
    
    printf("n:");
    scanf("%d",&n);
    printf("m:");
    scanf("%d",&m);
    
    res1 = n---m;
    res2 = m-- < n;
    res3 = n++ > m;
    
    printf("Result 1: %d\nResult 2: %d\nResult 3: %d\n",res1,res2,res3);
    
    return 0;
}
