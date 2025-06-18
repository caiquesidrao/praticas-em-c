#include <stdio.h>


// int max_of_four(int a, int b, int c, int d){
//     int arr[] = {a,b,c,d};
//     int maior = a;
//     for(int c =0; c < 4; c++) {
//         if(arr[c] > maior){
//             maior = arr[c];
//         }
//     }

//     return maior;
// }

int max_of_four(int a, int b, int c, int d){
    int maior = a;
    if(maior < b){
        maior = b;
    }
    if(maior < c) {
        maior = c;
    }
    if(maior < d){
        maior = d;
    }

    return maior;
}


int main() {    
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}