#include <stdio.h>
#include <math.h>
 int main()
 {
    double a,b,f;
    
    printf("Task 1\n");
    
    printf("a:");
    scanf("%lf",&a);
    printf("b:");
    scanf("%lf",&b);
    
    f = (pow((a + b),3) - (pow(a,3) - 3*pow(a,2)*b))/(3*a*pow(b,2) + pow(b,3));
    
    printf("Result: %lf\n",f);
    return 0;
 }
