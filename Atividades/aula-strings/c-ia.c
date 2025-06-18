#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *s = malloc(1024 * sizeof(char)); // Aloca memória inicial para a string de entrada

    // Lê a entrada do usuário
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1); // Ajusta o tamanho da memória para o tamanho exato da string

    char **names = NULL; // Array de ponteiros para armazenar as palavras
    int m = 0; // Contador de palavras

    char *name = malloc(1); // Aloca memória inicial para a palavra atual

    int size = 0; // Tamanho da palavra atual

    for (int i = 0; i <= strlen(s); i++) { // Inclui o caractere '\0' no final
        if (s[i] == ' ' || s[i] == '\0') {
            // Final da palavra encontrada
            name = realloc(name, (size + 1) * sizeof(char)); // Ajusta o tamanho da palavra
            
            name[size] = '\0'; // Adiciona o terminador de string

            // Adiciona a palavra ao array de strings
            m++;
            names = realloc(names, m * sizeof(char *)); // Realoca o array de ponteiros

            names[m - 1] = malloc((strlen(name) + 1) * sizeof(char)); // Aloca memória para a palavra

            strcpy(names[m - 1], name); // Copia a palavra para o array

            // Reinicia a palavra atual
            size = 0;
            free(name);
            name = malloc(1);
            if (name == NULL) {
                fprintf(stderr, "Erro ao alocar memória.\n");
                return 1;
            }
        } else {
            // Continua construindo a palavra
            size++;
            name = realloc(name, size * sizeof(char));
            name[size - 1] = s[i];
        }
    }

    // Imprime as palavras armazenadas
    for (int i = 0; i < m; i++) {
        printf("%s\n", names[i]);
        free(names[i]); // Libera a memória de cada palavra
    }

    free(names); // Libera o array de ponteiros
    free(name);  // Libera a última palavra
    free(s);     // Libera a string original

    return 0;
}