#include <stdio.h>

int main(){
    int num;
    printf("Digite um inteiro: ");
    scanf("%d", &num);
    int uni = num % 10;
    int dez = (( num % 100 ) - uni)/10;
    int cent = (( num % 1000) - uni - dez)/100;
    int milhar = (( num % 10000 - uni - dez - cent))/1000;
    int dezMilhar = (( num % 100000) - uni - dez - cent - milhar)/10000;
    int soma = uni+dez+cent+milhar+dezMilhar;
    printf("%d", soma);
    return 0;
}