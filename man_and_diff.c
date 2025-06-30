#include <stdio.h>
#include <string.h>

void Manchester(char* data){
    for(int i=0;i<strlen(data);i++){
        if(data[i]=='0')
        printf(" 01 ");
    else 
     printf(" 10 ");
    }
    printf("\n");
}

void diff_man(char*data){
    int previous=1;
    for(int i=0;i<strlen(data);i++){
        if(data[i]=='0'){
        previous=!previous;
        printf(" %d%d ",previous,!previous);
    }
    else {
     printf(" %d%d ",previous,!previous);
    }
    previous=!previous;
    }
}






int main(){

    char data[100];

    printf("Enter binary data:"); 
   scanf("%s",data); 
   Manchester(data); 
   diff_man(data); 
    return 0;

}
