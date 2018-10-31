#include <stdio.h>
#include <stdlib.h>
typedef struct dint{
    int value;
    struct dint * next;
}dint;
dint* make_dint( int n){
    dint *first;
    first=NULL;
    for (int i=n - 1;i>=0;i--){
        dint *p = malloc(sizeof(dint));
        p->value=i;
        p->next=first;
        first=p;
    }
    return first;
}
dint *print_dint(dint * first){    
    if (first==NULL){
        printf("The list is empty!");
        return NULL;    
    }
    dint*p=first;
    while(p!=NULL)
    {
        printf("%d ",p->value);
        p=p->next;
    }
    printf("\n");
    return first;
}
dint *free_dint(dint*first){    
    dint*p=first;
    while(p!=NULL)
    {
        p=p->next;
        free(p);
    }
    free(p);  
    return NULL;
}
dint *search(dint * first,int id){
    if (first==NULL)return NULL;
    if(id < 0)return NULL;
    dint*p=first;
    int i = 0;
    while(p != NULL){
        if(id == i){
            return p;
        }
        p = p->next;
        i++;
    }
    return NULL;
}
dint *add_dint(dint * first,int value,int id){
    if(id < 0) return NULL;
    dint *new = malloc(sizeof(dint));
    new->value = value;
    if(id == 0){
        new->next = first;
        return new;
    }
    dint*pre = search(first,id - 1),*next = search(first,id);
    if(pre ==NULL || next == NULL)return NULL;
    pre->next = new;
    new->next = next;
    return first;
}
dint *del_dint(dint * first,int id){
    if(id < 0) return NULL;
    if(id == 0){
        dint *f = first->next;
        free(first);
        return f;
    }
    dint*pre = search(first,id - 1),*el = search(first,id),*next = search(first,id+1);
    if(pre == NULL || next == NULL || el == NULL)return NULL;
    pre->next = next;
    free(el);
    return first;
}
dint *del_elements(dint*first,int id,int k){    
    dint *p = first;
    for(int i = 0; i < k;i++){
        p = del_dint(first,id + i);    
    }
    return p;
}
int write_to_file(dint *first){
    FILE *f;
    if (first==NULL)return -2;
    if ((f=fopen("file11.txt", "wb"))==NULL) return -1;    
    dint*p=first;
    while(p!=NULL)
    {
        fprintf(f, "%d\n", p->value);
        p=p->next;
    }
    fclose(f);
    return 1;
}
dint *overturn(dint* first){
    dint*p=first;  
    dint*prev = NULL;
    dint*temp;  
    while(p != NULL){
        temp = p->next;
        p->next = prev;
        prev = p;
        p = temp;
    }
    return prev;
}
dint* read_file(){
    FILE *f; 
    if ((f=fopen("file11.txt", "rb"))==NULL) return NULL;  
    dint *first = NULL;
    char s[15];
    char *end;
    fgets(s,12,f);
    do {        
        dint *p = malloc(sizeof(dint));        
        p->value = strtol (s, &end, 10);
        p->next=first;
        first=p;
        fgets(s,12,f);
    }while(!feof(f));
    fclose(f);
    return overturn(first);
}

int main(){
    dint *arr = make_dint(12);
    if((arr = add_dint(arr,100,2)) == NULL){
        printf("Error! Unable to add element!");
        exit(1);
    }
    if((arr = del_elements(arr,0,4)) == NULL){
        printf("Error! Unable to delete elements!");
        exit(2);
    }
    print_dint(arr);
    if(write_to_file(arr) != 1){
        printf("Error! Unable to write to file!");
        exit(3);
    }
    arr = free_dint(arr);
    if((arr = read_file()) == NULL){
        printf("Error! Unable create list!");
        exit(4);
    }
    print_dint(arr);
    free_dint(arr);    
    return 0;
}
