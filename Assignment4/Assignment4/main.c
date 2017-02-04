//
//  main.c
//  Assignment4
//
//  Created by Hiroshi Tokutomi on 2017-02-03.
//  Copyright © 2017 Hiroshi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 50
#define INDEX5 5
#define COUNTER2000 2000
#define COUNTER20 20

//*** problem1 ***
void problem1();

//*** problem2 ***
void problem2();

//*** problem3 ***
int *problem3(int *array, int index);

//*** problem4 ***
float problem4(float *array);

//*** problem5 ***
void problem5(int *number, int index);

//*** problem6 ***
int problem6(int *store, int number, int index);

//*** bonus problem
void bonusProblem(int *array, int number);
unsigned getRandInterval(unsigned begin, unsigned end);

int main(int argc, const char * argv[]) {
    //*** problem1 ***
    //problem1();
    
    //*** problem2 ***
    //problem2();
    
    //*** problem3 ***
    /*
    int index = 4;
    int array[4] = {12, 13, 14, 15};
    int *cpyArray;
    cpyArray = problem3(array, index);
    for(int i = 0; i < index; i++){
        printf("Print out the copy array[%d] : %d\n", i, cpyArray[i]);
    }
    */
    
    //*** problem4 ***
    /*
    float array[4] = {12.23, 13.24, 0.456, 1.234};
    float difference = problem4(array);
    printf("The difference is %f\n", difference);
     */
    
    //*** problem5 ***
    /*
    int index = 4;
    int storeNumbers[4] = {3, 5, 6, 8};
    problem5(storeNumbers, index);
     */
    
    //*** problem6 ***
    /*
    int index = 4;
    int search = 4;
    int storeNumbers[4] = {3, 5, 6, 8};
    int result = problem6(storeNumbers, search, index);
    if(result == -1){
        printf("Cannot find %d in the array\n", search);
    }else{
        printf("The index of array is %d\n", result);
    }
    */
    
    //*** bonus problem ***
    int array[COUNTER20];
    for(int i = 0; i < COUNTER20; i++){
        array[i] = getRandInterval(1, 1000);
    }
    int randomNumber = getRandInterval(1, 1000);
    bonusProblem(array, randomNumber);
    
    return 0;
}

//**********************
// Problem1
//**********************
void problem1(){
    int index = 5;
    char store[index];
    
    printf("Type 5 elements ");
    scanf("%s", store);
    
    // error message(store 5 elements)
    if(strlen(store) != 5){
        printf("Error. Type 5 elements\n");
        return;
    }
    
    // print out
    printf("The result is %s\n", store);
}

//**********************
// Problem2
//**********************
void problem2(){
    int index = 5;
    char store[index][LENGTH];
    
    // store
    for(int i = 0; i < index; i++){
        printf("Type anything ");
        scanf("%s", &store[i][LENGTH]);
    }
    
    // print out(original order)
    for(int j = 0; j < index; j++){
        printf("store %d is %s\n", j + 1, &store[j][LENGTH]);
    }
    
    printf("-----\n");
    
    // print out(reverse order)
    for(int j = index - 1; j >= 0; j--){
        printf("store %d is %s\n", j, &store[j][LENGTH]);
    }
}

//**********************
// Problem3
//**********************
int *problem3(int *array, int index) {
    int *cpyArray;
    cpyArray = malloc(10 * sizeof(int));
    
    for (int i = 0; i < index; i++ ) {
        cpyArray[i] = array[i];
    }
    return cpyArray;
}

//**********************
// Problem4
//**********************
float problem4(float *array){
    float max = array[0];
    float min = array[0];
    
    if(!array[1]){
        printf("Error. Store more than two numbers\n");
        exit(0);
    }
    
    for(int i = 1; i <= sizeof(array) / sizeof(array[0]); i++){
        if(max < array[i]){
            max = array[i];
        }else if(min > array[i]){
            min = array[i];
        }
    }
    
    return max - min;
}

//**********************
// Problem5
//**********************
void problem5(int *number, int index){
    int odd = 0;
    int even = 0;
    
    for(int i = 0; i <= index; i++){
        if(number[i] % 2 == 0){
            even++;
        }else{
            odd++;
        }
    }
    
    printf("Counts odd : %d\n", odd);
    printf("Counts even : %d\n", even);
}

//**********************
// Problem6
//**********************
int problem6(int *store, int number, int index){
    int flg = 0;
    
    for(int i = 0; i <= index; i++){
        if(store[i] == number){
            return i;
        }else{
            flg = -1;
        }
    }
    
    if(flg == -1){
        return -1;
    }
    
    return 0;
}

//**********************
// Problem7
//**********************
// We did it in class together.

//**********************
// Bonus Problem
//**********************
void bonusProblem(int *array, int number){
    int sum = 0;
    int flg = 0;
    
    for(int i = 0; i < COUNTER20; i++){
        printf("array[%d] : %d\n", i, array[i]);
        for(int j = 0; j < COUNTER20; j++){
            sum = array[i] + array[j];
            if(sum == number){
                //printf("%d is equal to array[%d]:%d + array[%d]:%d\n", number, i, array[i], j, array[j]);
                flg = 1;
            }
        }
    }
    
    if(flg == 0){
        printf("Error. No matched numbers with %d\n", number);
    }
}

unsigned getRandInterval(unsigned begin, unsigned end){
    unsigned range = (end - begin) + 1;
    unsigned limit = (RAND_MAX) - (RAND_MAX % range);
    unsigned randVal = rand();
    
    while(randVal >= limit) randVal = rand();
    
    return (randVal % range) + begin;
}
