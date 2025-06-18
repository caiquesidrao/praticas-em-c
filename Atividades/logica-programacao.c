#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *num;
    num = malloc(1024 * sizeof(char));
    scanf("%[^\n]", num);
    num = realloc(num, strlen(num)+1);
    int soma = 0;
    for(int i = 0; num[i] != '\0'; i++){
        soma += (int)(num[i]-'0');
    }
    printf("%d", soma);
    return 0;

}