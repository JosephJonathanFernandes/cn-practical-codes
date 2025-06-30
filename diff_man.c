#include <stdio.h>
#include <string.h>

void diff_man(char *data){
printf("Differential Manchester Encoding:\n");
int previous=1;
for(int i=0;i<strlen(data);i++){
    if(data[i]=='0') { 
        previous=!previous;
    printf(" %d%d ",previous,!previous);
    
    }
    else{
        printf(" %d%d ", previous,!previous); 
    }
    previous=!previous;
}
printf("\n");
}


int main(){

    char data[100];

    printf("Enter binary data:"); 
   scanf("%s",data); 
   diff_man(data); 
    return 0;

}
