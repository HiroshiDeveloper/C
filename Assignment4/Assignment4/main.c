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

//*** problem1 ***
void problem1();

//*** problem2 ***
void problem2();

//*** problem3 ***
int *problem3(int *array, int index);

//*** problem4 ***
float problem4(float *array);

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
