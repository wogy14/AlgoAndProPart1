#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
int is_letter(char c){
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
        return 1;
    }
    return 0;
}
int is_loud(char c){    
    int arr[6] = {97,101,105,111,117,121},i = 0;      
    c = tolower(c);
    for(i = 0; i < 6;i++){
        if(c == arr[i]){
            return 1;
        }
    }
    return 0;
}
int main(){
    char *text;    
    int i = 0,start_w,sw,count = 0;   
    printf("Put the string: ");
    text = GetString();   
    while(text[i] != 46){
        if(is_letter(text[i])){                    
            start_w = i;
            sw = 1;                       
            while(text[i] != 32 && text[i] != 46){   
                if(is_loud(text[i])){                    
                    sw = 0;                                      
                }  
                i++;               
            }            
            if(sw == 1){
                count++;
                printf("%d. ",count);
                while(text[start_w] != 32 && text[start_w] != 46){
                    printf("%c",text[start_w]);
                    start_w++;
                }
                printf("\n");
            }
        }
        else{
            i++;
        }       
    }
    
    return 0;
}
