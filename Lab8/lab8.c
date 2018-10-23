#include <stdio.h>
#define COUNT_ROWS 5
typedef struct{
    char name [40];
    char capital [40];
    float population;
    float square;
}state;
state fill_state(){
    state el;
    printf("name="); scanf("%s",el.name);
    printf("capital="); scanf("%s",el.capital);
    printf("population="); scanf("%f",&el.population);
    printf("square="); scanf("%f",&el.square);
    return el;
}
void delete(int id,state arr[COUNT_ROWS],int count){
    state arr2[COUNT_ROWS + 1]; 
    int checker = 0;
    for(int i = 0;i < count - 1;i++){        
        if(i == id){
            checker = 1;
        }
        arr2[i] = arr[i + checker];
    }
    for(int i = 0;i<count - 1;i++){
        arr[i] = arr2[i];
    }
}
int write_to_file(state arr[COUNT_ROWS],int count,char* file){
    FILE *f;    
    if ((f=fopen(file, "wb"))==NULL) return -1;
    for(int i = 0; i < count;i++) fwrite(&(arr[i]), sizeof(state),1,f);
    fclose(f);
    return 1;
}
void add(int id,state el,state arr[COUNT_ROWS],int count){
    state arr2[COUNT_ROWS]; 
    int checker = 0;
    for(int i = 0;i < count;i++){
        arr2[i + checker] = arr[i];
        if(i == id){
            checker = 1;
            arr2[i+1] = el;
        }
    }
    for(int i = 0;i<count + 1;i++){
        arr[i] = arr2[i];
    }
}
int read_file(state arr[COUNT_ROWS],char* file){
    FILE *f; 
    int i = 0;
    if ((f=fopen(file, "rb"))==NULL) return -1;
    while(!feof(f)&&i<=COUNT_ROWS) {  
        fread(&arr[i],sizeof(state),1,f); 
        i++; 
    } 
    fclose(f);
    return i - 1;
}
int search_to_delete(state arr[COUNT_ROWS],int value,int count){
    int counter = 0;
    for(int i = 0;i < count;i++){
        if(arr[i].population < value){
            delete(i,arr,count - counter);
            counter++;
        }
    }
    return counter;
}
int main(){
    state arr[COUNT_ROWS],el;
    int i,id_for_add,counter = 0,population;
    for(i=0; i<COUNT_ROWS;i++)
    {
        printf("\nCountry:\n");
        arr[i] = fill_state();             
    }
    printf("Min population: ");
    scanf("%d",&population);
    printf("Put index of row to add: ");
    scanf("%d",&id_for_add);
    printf("\nPut new elements:\n");
    el = fill_state();
    counter = search_to_delete(arr,population,COUNT_ROWS);
    add(id_for_add,el,arr,COUNT_ROWS - counter);
    write_to_file(arr,COUNT_ROWS - counter + 1,"states.dat");
    int count = read_file(arr,"states.dat");
    for(int i = 0;i < count;i++){
        printf("name= %s | ",arr[i].name);
        printf("capital= %s | ",arr[i].capital); 
        printf("population= %f | ",arr[i].population); 
        printf("square= %f | ",arr[i].square); 
        printf("\n");
    }
    return 0;
}
