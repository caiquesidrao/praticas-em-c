#include <stdio.h>

int main(){
    int num1, num2;
    printf("Digite um numero maior que 0:\n");
    scanf("%d%d", &num1,&num2);
    for(num1; num1<=num2; num1++){
        if(num1 >= 1 && num1<=9){
            switch(num1){
                case 1:
                    printf("one\n");
                    break;
                case 2:
                    printf("two\n");
                    break;
                case 3:
                    printf("three\n");
                    break;
                case 4:
                    printf("four\n");
                    break;
                case 5:
                    printf("five\n");
                    break;
                case 6:
                    printf("six\n");
                    break;
                case 7:
                    printf("seven\n");
                    break;
                case 8:
                    printf("eight\n");
                    break;
                case 9:
                    printf("nine\n");
                    break;
            }
    
        } else if(num1%2 == 0){
            printf("even\n");
        } else{
            printf("odd\n");
        }
    }
    
}