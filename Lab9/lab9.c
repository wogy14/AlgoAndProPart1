#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void write_file(FILE *F,int num){
    char temp[257];
    printf("Put %d strings to fill F1.txt:\n",num);    
    for(int i = 0; i < num;i++){
        fgets(temp,255,stdin);
        if (temp[strlen(temp)-1]!='\n') {
            temp[strlen(temp)]='\n';
            temp[strlen(temp)+1]='\0';
        }
        fputs(temp,F);
    }
    rewind(F);
}
void print_file(FILE *F){
    char temp[257];
    int count = 1;
    fgets(temp,256,F);
    do{
        printf("%d. %s",count++,temp);
        fgets(temp,256,F);        
    }while(!feof(F));
    rewind(F);
}
void copy_file(FILE *f1,FILE *f2){
    char temp[257];   
    fgets(temp,256,f1);
    do{
        if(temp[strlen(temp) - 2] == temp[0]){
            fputs(temp,f2);
        }
        fgets(temp,256,f1);        
    }while(!feof(f1));
    rewind(f2);
    rewind(f1);
}
int count_chars(FILE *f){
    char temp[257]; 
    int count = 0;
    fgets(temp,256,f);
    do{
        count += strlen(temp) - 1;
        fgets(temp,256,f);
    }while(!feof(f));
    rewind(f);
    return count;
}
int main(){
    FILE *f1,*f2;
    if ((f1=fopen("F1.txt", "w+"))==NULL || (f2=fopen("F2.txt", "w+"))==NULL){
        printf("Error reading file!");
        exit(2);
    }
    write_file(f1,3);
    printf("F1.txt:\n");
    print_file(f1);
    copy_file(f1,f2);
    printf("F2.txt:\n");
    print_file(f2);
    printf("Count chars in F2.txt: %d\n",count_chars(f2));
    fclose(f1);
    fclose(f2);
    return 0;
}
