#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    char *resultado = strtok(s, " ");
    while(resultado != NULL){
        printf("%s\n", resultado);
        /* Segunda chamada, função utiliza fonte anterior
        e parte do ponteiro final adicionado anteriormente */
        resultado = strtok(NULL, " ");
    }
    return 0;
}