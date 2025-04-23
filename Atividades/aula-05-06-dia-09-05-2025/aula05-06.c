#include <stdio.h>

#define FALSE 0
#define TRUE 1

int main(){
    char texto[100];
    printf("%u\n",sizeof(texto));
    if(sizeof(texto)){
        printf("Macarena");
    } else {
        printf("Vai corinthias!!");
    }
    return 0;
}