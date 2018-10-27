#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *fill_arr(int count){
    srand(time(NULL));
    int *arr = (int*)malloc(count * sizeof(int));
    for(int i = 0;i < count;i++){
        *(arr + i*sizeof(int)) = rand() % 10;
    }
    return arr;
}
void print_arr(int *arr,int count){
    for(int i = 0;i < count;i++){
        printf("%d ",*(arr + i*sizeof(int)));
    }
    printf("\n");
}
int *delete_els(int *arr,int count,int start,int c_del){
    int c = 0;
    int temp[count - c_del];
    for(int i = 0;i < count;i++){
        if(i == start){
            c = 1;
        }
        temp[i] = *(arr + (i + c_del*c)*sizeof(int));        
    }    
    if((arr = realloc(arr,(count - c_del)*sizeof(int))) == NULL){
        return NULL;
    }
    for(int i = 0;i < count -c_del;i++){
        *(arr + i*sizeof(int)) = temp[i];
    }
    return arr;
}
int *add_element(int *arr,int count,int key,int el){
    int temp[count + 1];
    int c = 0;
    for(int i = 0;i < count;i++){
        if(key == i){            
            temp[i] = el;
            c=1;
        }
        temp[i + 1*c] = *(arr + i*sizeof(int));
    }
    if((arr = realloc(arr,(count + 1)*sizeof(int))) == NULL){
        return NULL;
    }
    for(int i = 0;i < count + 1;i++){
        *(arr + i*sizeof(int)) = temp[i];
    }
    return arr;
}
int main(){   
    int count,id,temp;
    printf("Put count of elements:");scanf("%d",&count);
    int *arr = fill_arr(count);
    print_arr(arr,count);
    printf("Put first element`s id to delete:");scanf("%d",&id);
    printf("Put count of elements to delete:");scanf("%d",&temp);
    arr = delete_els(arr,count,id,temp);
    count -= temp;
    print_arr(arr,count);
    printf("Put id to add element:");scanf("%d",&id);
    printf("Put value of element to add:");scanf("%d",&temp);
    arr = add_element(arr,count,id,temp);
    count += 1;
    print_arr(arr,count);
    free(arr);
    return 0;
}
