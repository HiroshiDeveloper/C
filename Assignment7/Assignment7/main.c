//
//  main.c
//  Assignment7
//
//  Created by Hiroshi Tokutomi on 2017-02-07.
//  Copyright © 2017 Hiroshi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INTSIZE 10
#define STORECSIZE 10
#define CHARSIZE 256
#define PROBLEM4SIZE 5
#define DYNAMICSIZE 10

//*** problem1 ***
void problem1();

//*** problem2 ***
void problem2();

//*** problem4 ***
void problem4();
int fixedLines(char arr[][CHARSIZE], int length);
int semiFixedLines(char *arr[], int length);
int dynamicLines(char **arr, int length);

int main(int argc, const char * argv[]) {
    //*** problem1 ***
    printf("*** problem1 ***\n");
    problem1();

    //*** problem2 ***
    printf("\n*** problem2 ***\n");
    problem2();
    
    //*** problem4 ***
    printf("\n*** problem4 ***\n");
    problem4();
    
    return 0;
}

//**********************
// Problem1
//**********************
void problem1(){
    int positive = 0;
    int flg = 1;
    int *bigNumber = malloc(sizeof(int) * INTSIZE);
    *bigNumber = positive;
    
    while(flg){
        printf("Enter a positive number\n");
        scanf("%d", &positive);
        
        // error check (the number must be bigger than 0)
        if(positive <= 0){
            printf("Error. Enter a number which is bigger than 0\n");
            flg = 0;
        }else if(*bigNumber < positive){
            *bigNumber = positive;
        }
    }
    
    // if the number is not updated
    if(*bigNumber != 0){
        printf("The biggest Number is %d\n", *bigNumber);
    }
    free(bigNumber);
}

//**********************
// Problem2
//**********************
void problem2(){
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i = 0;
    
    while(i < 10){
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

//**********************
// Problem4
//**********************
void problem4(){
    // number1
    char storeA[5][CHARSIZE];
    // number2
    char *storeB[5];
    // number3
    char **storeC;
    int counter = 0, check = 0;
    int flg = 1;
    
    // number1
    printf("A : Type numbers 5 times\n");
    for(int i = 0; i < PROBLEM4SIZE; i++){
        fgets(storeA[i], CHARSIZE, stdin);
    }
     
    // number4
    int longest1 = fixedLines(storeA, 5);
    printf("(Number4) The longest lengh is %d\n", longest1);
    
    // number2
    printf("B : Type numbers 5 times\n");
    for(int j = 0; j < PROBLEM4SIZE; j++){
        storeB[j] = malloc(sizeof (char) * CHARSIZE);
        fgets(storeB[j], CHARSIZE, stdin);
    }
    
    // number5
    int longest2 = semiFixedLines(storeB, PROBLEM4SIZE);
    printf("(Number5) The longest lengh is %d\n", longest2);
    for(int k = 0; k < PROBLEM4SIZE; k++){
        free(storeB[k]);
    }
    
    // number3
    storeC = (char**)malloc(sizeof(char*) * DYNAMICSIZE);
    printf("C : Type numbers\n");
    while(flg){
        storeC[counter] = malloc(sizeof (char) * CHARSIZE);
        fgets(storeC[counter], CHARSIZE, stdin);
        check = strncmp(storeC[counter], "\n", 1);
        if(check == 0){
            printf("** The end **\n");
            break;
        }
        counter++;
    }
    
    // number6
    int longest3 = dynamicLines(storeC, counter);
    printf("(Number5) The longest lengh is %d\n", longest3);
    
    free(storeC);
    for(int l = 0; l < counter; l++){
        free(storeC[l]);
    }
}

// number4
int fixedLines(char arr[][CHARSIZE], int length){
    int max = 0;
    
    for(int i = 0; i < length; i++){
        if(max < (int)strlen(arr[i]) - 1){
            max = (int)strlen(arr[i]) - 1;
        }
    }
    return max;
}

// number5
int semiFixedLines(char **arr, int length){
    int max = 0;
    
    for(int i = 0; i < length; i++){
        if(max < (int)strlen(arr[i]) - 1){
            max = (int)strlen(arr[i]) - 1;
        }
    }
    return max;
}

// number6
int dynamicLines(char **arr, int length){
    int max = 0;
    
    for(int i = 0; i < length; i++){
        if(max < (int)strlen(arr[i]) - 1){
            max = (int)strlen(arr[i]) - 1;
        }
    }
    return max;
}
