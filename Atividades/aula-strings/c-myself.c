#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    char **names = NULL;
    int m = 0;
    int size = 0;
    char *name;
    for(int i = 0; i < strlen(s)+1;i++){
        size++;
        name = realloc(name, (size)*sizeof(char));
        if(s[i] == ' ' || i == strlen(s)){
            m++;
            names = realloc(names, m*sizeof(char *));
            name[size-1] = '\0';
            names[m-1] = malloc(strlen(name)+1);
            for(int c = 0; c < size; c++){
                names[m-1][c] = name[c];
            } 
            
            size = 0;
        } else {
            name[size-1] = s[i];
        }
        
        
        
    }
    for(int i = 0; i < m; i++){
        printf("%s\n", names[i]);
        free(names[i]);
    }

    free(names);
    free(s);
    free(name);

    return 0;
}