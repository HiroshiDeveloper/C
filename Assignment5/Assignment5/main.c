//
//  main.c
//  Assignment5
//
//  Created by Hiroshi Tokutomi on 2017-02-04.
//  Copyright © 2017 Hiroshi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FULLNAME 126

struct number{
    int num1;
    int num2;
};

//*** problem1 ***
void problem1();

//*** problem2 ***
void problem2();

//*** problem3 ***
void problem3();

//*** problem4 ***
void problem4();

//*** problem5 ***
void problem5();
char charAtPosition(int position, char *fullName);

//*** problem6 ***
void problem6();
struct number swap(int num1, int num2);

//*** bonus problem ***
void bonusProblem();

int main(int argc, const char * argv[]) {
    //*** problem1 ***
    // problem1();
    
    //*** problem2 ***
    //problem2();
    
    //*** problem3 ***
    //problem3();
    
    //*** problem4 ***
    //problem4();
    
    //*** problem5 ***
    //problem5();
    
    //*** problem6 ***
    problem6();

    return 0;
}

//**********************
// Problem1
//**********************
void problem1(){
    // number1-1, 2
    int typeInt;
    char typeChar;
    long typeLong;
    float typeFloat;

    // number1-3, 4
    int *pointerInt = &typeInt;
    char *pointerChar = &typeChar;
    long *pointerLong = &typeLong;
    float *pointerFloat = &typeFloat;
    
    printf("The address of typeInt is %p\n", pointerInt);
    printf("The address of typeChar is %p\n", pointerChar);
    printf("The address of typeLong is %p\n", pointerLong);
    printf("The address of typeFloat is %p\n", pointerFloat);
    
    // number1-5, 6
    *pointerInt = 3;
    *pointerChar = 'T';
    *pointerLong = 123;
    *pointerFloat = 1234567;
    
    printf("[pointerInt] value : %d, address :%p\n", *pointerInt, pointerInt);
    printf("[pointerChar] value : %c, address :%p\n", *pointerChar, pointerChar);
    printf("[pointerLong] value : %ld, address :%p\n", *pointerLong, pointerLong);
    printf("[pointerFloat] value : %f, address :%p\n", *pointerFloat, pointerFloat);
}

//**********************
// Problem2
//**********************
void problem2(){
    // number1-1,2
    char word1[] = "Hello";
    char *word2 = "World";
    printf("word1 is %s\n", word1);
    printf("word2 is %s\n", word2);
    
    // number1-3, 4, 5, 6
    word2 = "I am not world";
    printf("word1 is %s\n", word1);
    printf("word2 is %s\n", word2);
    word2 = word1;
    printf("word 1 is %s\n", word1);
    printf("word 2 is %s\n", word2);
    
    // number1-7
    //word1 = word2;        // Error
    printf("word 1 is %s\n", word1);
    printf("word 2 is %s\n", word2);
}

//**********************
// Problem3
//**********************
void problem3(){
    // number1-1, 2
    char word[] = "World";
    printf("The beginning address of the array is at address %p\n", word);
    printf("W is at address %p\n", &(word[0]));
    printf("O is at address %p\n", &(word[1]));
    printf("R is at address %p\n", &(word[2]));
    printf("L is at address %p\n", &(word[3]));
    printf("D is at address %p\n", &(word[4]));
    
    // number1-3
    int numbers[] = {10, 20, 30, 40};
    printf("The begginning address of the array is at address %p\n", numbers);
    printf("10 is at address %p\n", &(numbers[0]));
    printf("20 is at address %p\n", &(numbers[1]));
    printf("30 is at address %p\n", &(numbers[2]));
    printf("40 is at address %p\n", &(numbers[3]));
}

//**********************
// Problem4
//**********************
void problem4(){
    int array[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++){
        printf("The value array[%d] is %d\n", i, *(&array[i]));
    }
}

//**********************
// Problem5
//**********************
// number1-1, 2, 4
void problem5(){
    char *first = "Hiroshi";
    char *last = "Developer";
    char *fullName;
    
    fullName = malloc(strlen(first) + strlen(last));
    strcpy(fullName, first);
    strcat(fullName, last);
    for(int i = 0; i < strlen(fullName); i++){
        printf("%c ", fullName[i]);
    }
    printf("\n");
    
    int index = 7;
    char letter = charAtPosition(index, fullName);
    printf("The character at position %d is %c\n", index, letter);
}

// number1-3
char charAtPosition(int position, char *fullName){
    return fullName[position];
}

//**********************
// Problem6
//**********************
void problem6(){
    int num1 = 10;
    int num2 = 20;
    struct number swapNumber = swap(num1, num2);
    printf("num1 is %d\n", swapNumber.num1);
    printf("num2 is %d\n", swapNumber.num2);
}

struct number swap(int num1, int num2){
    struct number swapNumber;
    swapNumber.num1 = num2;
    swapNumber.num2 = num1;
    
    return swapNumber;
}
