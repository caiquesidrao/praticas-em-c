// #include <stdio.h>



// int marks_summation(int* marks, int number_of_students, char gender) {
//     int sum;
//     if(gender == 'b'){
//        for(int i = 0; i < number_of_students; i++){
//            sum += i%2==0? marks[i]:0;
//        }
//     } else if (gender == 'g') {
//        for(int i = 0; i < number_of_students; i++){
//            sum += i%2!=0? marks[i]:0;
//        }
//     }
//     return sum;
// } 


// int main(){
//     int num_student;
//     scanf("%d", &num_student);
//     int marks[num_student];
//     for(int i =0; i <= num_student; i++){
//         scanf("%d", &marks[i]);
//     }
//     char gender;
//     scanf("%c", &gender);
//     printf("%d", marks_summation(marks, num_student, gender));
//     return 0;
// }

#include <stdio.h>

int marks_summation(int* marks, int number_of_students, char gender) {
    int sum = 0;
    int i = (gender == 'b') ? 0 : 1;
    
    for (i; i < number_of_students; i += 2) {
        sum += marks[i];
    }

    return sum;
}

int main() {
    int num_student;
    scanf("%d", &num_student);

    int marks[num_student];
    for (int i = 0; i < num_student; i++) {
        scanf("%d", &marks[i]);
    }

    char gender;
    scanf(" %c", &gender);  // Espaço ignora o newline pendente

    printf("%d\n", marks_summation(marks, num_student, gender));

    return 0;
}
