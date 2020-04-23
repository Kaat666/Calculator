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
    FILE *input , *output;
    input = fopen("input.txt","r" );
    output = fopen("output.txt","w" );
    next_time = 'y';
    while (next_time == 'y'){ // Цикл на повторение программы неколько раз
        fscanf(input," %c", &operation);
        fscanf(input,"%i", &mode);
        if (mode == 1){
            fscanf(input,"%f", &first_var);
            g = first_var ;
            if (operation == '+') { // Сложение двух чисел
                fscanf(input,"%f", &second_var);
                result = first_var + second_var ;
            }else if (operation == '-') {   // Разность
                fscanf(input,"%f", &second_var);
                result = first_var - second_var ;
            }else if (operation == '*') {    // Произведение
                fscanf(input,"%f", &second_var);
                result = first_var * second_var ;
            }else if (operation == '/') {   // Деление
                fscanf(input,"%f", &second_var);
                result = first_var / second_var ;
            }else if (operation == '^') {   // Возведение в степень
                fscanf(input,"%f", &second_var);
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
            fprintf(output,"%f" , result );    // Выводим результат
            fscanf(input," %c", &next_time);
        }
            else if(mode == 2){
            fscanf(input,"%i", &size);
            vec1 = calloc(size,sizeof(float));
            for (int i=0; i<size; i++){
                fscanf(input,"%f", &vec1[i]); }
            vec2 = calloc(size,sizeof(float));
            for (int i=0; i<size; i++){
                fscanf(input,"%f", &vec2[i]); }
            switch(operation){
            case '+':
               for (int i = 0; i < size; i++){
               fprintf(output,"%f", vec1[i] + vec2[i]);}
               break;
            case '-':
               for (int i = 0; i < size; i++){
               fprintf(output,"%f", vec1[i] - vec2[i]);}
               break;
            case '*':
                for (int i = 0; i < size; i++){
                result += vec1[i] * vec2[i];}
                fprintf(output,"Result: %f\n", result);
                break;
            }
            fscanf(input," %c", &next_time);
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}
