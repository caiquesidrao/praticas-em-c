#include <stdio.h>

void maxMin(){
    printf("MAXIMO E MINIMO");
    long long int numero, maiorNum, menorNum;
    for(int i=0; i < 5; i++){
        printf("Digite um numero inteiro:\n");
        scanf("%lld", &numero);
        if(i==0){
            maiorNum = numero;
            menorNum = numero;
        } else {
            maiorNum = (maiorNum<numero?numero:maiorNum);
            menorNum = (menorNum>numero?numero:menorNum);
        }
    }
    printf("\nMaior numero: %lld", maiorNum);
    printf("\nMenor numero: %lld\n", menorNum);
}

long long int fatorial(){
    printf("CALCULO DE FATORIAL\n");
    unsigned long long numero, fatorial = 1 ,i = 1;
    printf("Digite um numero: "); // Recebe um número
    scanf("%lld", &numero);
    do{
        fatorial *= i;
        i++;
    }while(i <= numero); // realiza o fatorial do número
    return fatorial;
}

int main() {
    //maxMin();
    printf("FATORIAL: %lld\n", fatorial());
    return 0;
}