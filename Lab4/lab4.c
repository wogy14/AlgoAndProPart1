#include <stdio.h>
#include <stdlib.h>

void printarr(int arr[],int count){
    for(int i = 0; i < count;i++){
        printf("%d ",arr[i]);
    }
    
}
void arrnull(int arr[], int count){
    for(int i = 0; i < count; i++){
        arr[i] = 0;
    }
}
int main(){
    int count,n,arr[100],arr2[100],b,i; 
    do{
        printf("Put count elements of array: ");
        scanf("%d",&count);
    }while(count < 0 || count > 100);
    
    for(i = 0;i < count;i++){               
        arr[i]= rand() % 10;
    }
    
    printf("Elements of array: ");
    printarr(arr,count); 
    printf("\n");  
    n = 0;
    for(i = 0; i < count; i++){
        if(arr[i] == 0){            
            n++;
            continue;
        }           
        arr2[i - n] = arr[i];          
    }
    count -= n;
    
    arrnull(arr, 100);
    b = 0;
    for(i = 0; i < count + 1; i++){
        if(b == 0){
            if(arr2[i] % 2 == 0 && i != 0){
                arr[i] = arr2[i - 1] + 2;
                b = 1;
            }
            else{
                arr[i] = arr2[i];
            }
        }
        else{
            arr[i] = arr2[i - 1];
        }
    }
    printf("Elements of changed array: ");
    printarr(arr,count + 1);
    printf("\n");  
    return 0;
}
