#include <stdio.h>
#include <string.h>


void nrzL(char *data) {
    printf("NRZ-L Encoding:\n");
    for(int i=0;i<strlen(data);i++){
        if(data[i]=='1')
        printf(" HIGH ");
    else
    printf(" LOW ");
    }
    printf("\n");
}

void nrzI(char *data) {
    printf("NRZ-I Encoding:\n");
    int level=0;
    for(int i=0;i<strlen(data);i++){
        if(data[i]=='1')
        level=!level;
    printf(" %c (%s)",data[i],level? "HIGH ": "LOW");
    }
    printf("\n");
}


int main() {
    char binary[100];
    printf("Enter binary data (e.g., 110010): ");
    scanf("%s", binary);

    nrzL(binary);
    nrzI(binary);

    return 0;
}