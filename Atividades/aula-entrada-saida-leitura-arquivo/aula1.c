#include <stdio.h>




int main(){
    FILE* arquivo = fopen("dados.txt","w");
    if(arquivo == NULL) return 1;
    fputs("Caique\n1.9\n18", arquivo);
    fclose(arquivo);
    arquivo = fopen("dados.txt","r");
    if(arquivo == NULL){
        printf("ERRO");
        return 1;
    };
    int idade;
    char nome[255];
    float altura;
    while(fscanf(arquivo, "%s %f %d", nome, &altura, &idade)==3){
        printf("%s\n%d\n%f", nome, idade,altura);
    }
    fclose(arquivo);    
}