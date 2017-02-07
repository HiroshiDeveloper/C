//
//  main.c
//  Assignment7
//
//  Created by Hiroshi Tokutomi on 2017-02-07.
//  Copyright © 2017 Hiroshi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define INTSIZE 10

//*** problem1 ***
void problem1();

//*** problem2 ***
void problem2();

//*** problem4 ***
void problem4();

int main(int argc, const char * argv[]) {
    //*** problem1 ***
    //problem1();
    
    //*** problem2 ***
    //problem2();
    
    //*** problem4 ***
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
    int storeA[5];
    int *storeB = malloc(sizeof (int) * 5);
    int number;
    
    // number1
    /*
    printf("A : Type numbers 5 times\n");
    for(int i = 0; i < 5; i++){
        scanf("%d", &number);
        storeA[i] = number;
    }
    
    // number2
    printf("B : Type numbers 5 times\n");
    for(int j = 0; j < 5; j++){
        scanf("%d", &number);
        storeB[j] = number;
    }
    //printf("%d\n", storeB[2]);
     */
    
    // number3
    

}
