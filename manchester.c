#include <stdio.h>
#include <string.h>

void Manchester(char *data){
    printf("Manchester Encoding:\n"); 
      for(int i=0;i<strlen(data);i++){
        if(data[i]=='0')
        printf(" 10 ");
       else printf(" 01 ");
            
      }
      printf("\n");
}

int main(){

    char data[100];

    printf("Enter binary data:"); 
   scanf("%s",data); 
   Manchester(data); 
    return 0;

}
