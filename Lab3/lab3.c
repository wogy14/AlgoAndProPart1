#include <stdio.h>
#include <math.h>

long long fact(int numb){
    long long i = 1;
    for(int j = 1;j <= numb;j++){
        i *= j;
    }
    return i;
}

int main(){
    double y, sum, sum2, el;    
    int n = 0;
    
    for(double x = 0.1;x <= 1;x += 0.1){
        sum = 0;
        sum2 = 0;
        y = sin(x);
        
        for(int n = 0; n < 10;n++){
            double el;
            el = pow((-1),n) * pow(x,(2*n + 1)) / fact(2 * n + 1);
            sum += el;
        }
        n = 0;
        
        do{
            el = pow((-1),n) * pow(x,(2*n + 1)) / fact(2 * n + 1);
            sum2 += el;
            n++;
        }while(el > 0.0001);
        
        printf("X =  %e | Y = %e | SN = %e | SE = %e\n",x,y,sum,sum2);
           
    }
    return 0;
}

