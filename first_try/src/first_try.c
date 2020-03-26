/*
 ============================================================================
 Name        : first_try.c
 Author      : Cat
 Version     :
 Copyright   : mya
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int size , mode;
float first_var, second_var , result , g;
float *vec1 , *vec2;
char operation, next_time;
int main(int argc , char *argv[] ) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    next_time = 'y';
    while (next_time == 'y'){ // Цикл на повторение программы неколько раз
        puts("select a mode number operation - 1 vector operation - 2 ");
        scanf("%i", &mode);
        if (mode == 1){
            puts("enter the first var ");
            scanf("%f", &first_var);
            puts("enter your operation  ");
            scanf(" %c", &operation);
            g = first_var ;
            if (operation == '+') { // Сложение двух чисел
                puts("enter the second  var ");
                scanf("%f", &second_var);
                result = first_var + second_var ;
            }else if (operation == '-') {   // Разность
                puts("enter the second  var ");
                scanf("%f", &second_var);
                result = first_var - second_var ;
            }else if (operation == '*') {    // Произведение
                puts("enter the second  var ");
                scanf("%f", &second_var);
                result = first_var * second_var ;
            }else if (operation == '/') {   // Деление
                puts("enter the second  var ");
                scanf("%f", &second_var);
                result = first_var / second_var ;
            }else if (operation == '^') {   // Возведение в степень
                puts("enter the second  var ");
                scanf("%f", &second_var);
                while (second_var >1){
                    first_var = first_var * g;
                    second_var = second_var - 1;
                   }
                result = first_var ;
            }else if (operation == '!') {    // Вычисление факториала
                while (g > 1 ){
                    g = g - 1;
                    first_var = first_var *g ;
                }
                result = first_var;
            }
            printf("%f" , result );    // Выводим результат
            puts(" repeat it? (enter \"y\" to continue)"); // Спрашиваем о перезапуске программы
            scanf(" %c", &next_time);
        }
            else if(mode == 2){
            printf("Enter the size of the vectors: ");
            scanf("%i", &size);
            vec1 = calloc(size,sizeof(float));
            for (int i=0; i<size; i++){
                printf("Enter the first vector: ");
                scanf("%f", &vec1[i]); }
            vec2 = calloc(size,sizeof(float));
            for (int i=0; i<size; i++){
                printf("Enter the second vector: ");
                scanf("%f", &vec2[i]); }
            printf("Select the sign(+-*):");
            scanf(" %c", &operation);
            switch(operation){
            case '+':
               for (int i = 0; i < size; i++){
               printf("%f", vec1[i] + vec2[i]);}
               break;
            case '-':
               for (int i = 0; i < size; i++){
               printf("%f", vec1[i] - vec2[i]);}
               break;
            case '*':
                for (int i = 0; i < size; i++){
                result += vec1[i] * vec2[i];}
                printf("Result: %f\n", result);
                break;
            }
            printf("%f" , result );
            puts(" repeat it? (enter \"y\" to continue)"); // Спрашиваем о перезапуске программы
            scanf(" %c", &next_time);
        }
    }
    return 0;
}
