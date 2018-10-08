#include <stdio.h>
#include <stdlib.h>

void rand_matrix(int **parr,int m,int n){
    int *p_array=(int*)parr; 
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            p_array[j*m + i] = rand() % 5;            
        }        
    }
}
void print_matrix(int **parr,int m,int n){
    int *p_array=(int*)parr;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){            
            printf("%d ",p_array[j*m + i]);
        }
        printf("\n");
    }
}
void matrix_sum(int **parr,int **parr2,int **sumarr,int m,int n){
    int *p_array = (int*)parr;
    int *p_array2 = (int*)parr2;
    int *p_sumarr = (int*)sumarr;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){            
            p_sumarr[j*m + i] = p_array[j*m + i] + p_array2[j*m + i];
        }        
    }
}
void matrix_transp(int **parr,int **transp,int m,int n){
    int *p_array = (int*)parr; 
    int *p_transp = (int*)transp;      
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){            
            p_transp[j*n + i] = p_array[i*m + j];            
        }           
    }
}
int main(){
    int x,y;
    printf("Put rows of matrix: ");
    scanf("%d", &x);
    printf("Put columns of matrix: ");
    scanf("%d", &y);
    int arr[x][y], arr2[x][y], sumarr[x][y],transp[y][x];    
    rand_matrix((int**) arr,x,y);
    rand_matrix((int**) arr2,x,y);
    matrix_sum((int**)arr,(int**)arr2,(int**)sumarr,x,y);
    matrix_transp((int**) sumarr,(int**) transp,x,y);
    printf("Matrix 1\n");
    print_matrix((int**) arr,x,y);
    printf("Matrix 2\n");
    print_matrix((int**) arr2,x,y);
    printf("Sum of matrixs\n");
    print_matrix((int**) sumarr,x,y);
    printf("Transp\n");
    print_matrix((int**) transp,y,x);
    return 0;
}
