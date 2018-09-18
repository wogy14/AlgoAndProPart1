#include <stdio.h>

int main(){
    int sum = 0;
    
    for(int i = 199;i > 0;i -= 2){
        sum += i;
    }
    
    printf("Sum: %d\n",sum);
    return 0;
}
