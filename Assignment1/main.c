//
//  main.c
//  Assignment1
//
//  Created by Hiroshi Tokutomi on 2017-01-26.
//  Copyright © 2017 Hiroshi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

unsigned getRandInterval(unsigned begin, unsigned end);

// probrem1
void probrem1();
// probrem2
void evenMoreNumber(int counter);
void evenLessNumber(int counter);
// probrem3
void probrem3();
// probrem4
void probrem4();
// probrem5
void probrem5();

int main(int argc, const char * argv[]) {
    
    //*** probrem1***
    /*
    probrem1();
    */
     
    //*** probrem2 ***
    /*
    int counter = getRandInterval(0, 100);
    printf("Randam Number is %d\n", counter);
    //if counter is even
    if(counter % 2 != 0){
        counter += 1;
    }else{
        counter += 2;
    }
    evenMoreNumber(counter);
    evenLessNumber(counter);
     */
    
    //*** probrem3 ***
    /*
    probrem3();
     */
    
    //*** probrem4 ***
    /*
    probrem4();
    */
    
    //*** probrem5 ***
    /*
    probrem5();
     */

    return 0;
}

//*******************
// Probrem1
//*******************
void probrem1(){
    int index;
    
    // Number 1
    // Any number(index) is Okay
    // e.g.)index=6
    index = 6;
    
    // if index is odd
    if(index % 2 != 0){
        index -= 1;
    }
    
    // Number2
    printf("First : %d\n", index + 2);
    printf("First : %d\n", index + 4);
    printf("First : %d\n", index + 6);
    printf("First : %d\n", index + 8);
    printf("First : %d\n", index + 10);
    
    // Number3
    for(int i = index; i < 200; i += 2){
        printf("%d ", i);
    }
    printf("\n");
}

//*******************
// Probrem2
//*******************
// Number1
//  The declaration on the top
//  unsigned getRandInterval(unsigned begin, unsigned end);

// Number2
unsigned getRandInterval(unsigned begin, unsigned end){
    unsigned range = (end - begin) + 1;
    unsigned limit = (RAND_MAX) - (RAND_MAX % range);
    unsigned randVal = rand();
    
    while(randVal >= limit) randVal = rand();
    
    return (randVal % range) + begin;
}

// Number3
//  The declaration on the top
//  #include <stdlib.h>
//  #include <time.h>

// Number4
//  Call the function inside main method

// Number5
void evenMoreNumber(int counter){
    for(int i = 0; i < 10; i++){
        printf("%d ", counter += i * 2);
    }
    printf("\n");
}

// Number6
void evenLessNumber(int counter){
    for(int i = counter; i < 200; i += 2){
        printf("%d ", i);
    }
    printf("\n");
}

//*******************
// Probrem3
//*******************
void probrem3(){
    // Number1
    int counter = getRandInterval(5, 10);
    
    // Number2
    for(int i = counter; i > 0; i--){
        for(int j = i; j > 0; j--){
            printf("*");
        }
        printf("\n");
    }
}

//*******************
// Probrem4
//*******************
void probrem4(){
    // Number1
    int counter = getRandInterval(4, 11);
    
    // Number2
    for(int i = 1; i <= counter; i++){
        for(int j = i; j > 0; j--){
            printf("*");
        }
        printf("\n");
    }
}

//*******************
// Probrem5
//*******************
void probrem5(){
    // Number1
    int counter = getRandInterval(8, 14);
    
    // Number2
    if(counter % 2 != 0){
        counter += 1;
    }
    
    // diferrence between previous counter and current one
    int diff = 0;
    // row
    for(int i = counter; i > 0; i /= 2){
        diff = counter - i;
        // column
        for(int j = 0; j < i + diff / 2; j++){
            if(j >= diff/2){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

//*******************
// Bonus Probrem
//*******************
// Number 1
//  - What is argc?
//  - What is argv[]?
//      Argc is the number of arguments. Argv is an array (vector) holding pointers
//      to the string arguments passed on the command line.
//
//  - How to use argc and argv?
//      $ gcc main.c -o cmdline_basic
//      $ ./cmdline_basic test1 test2
//
//  - Provide an example
//      #include <stdio.h>
//      int main (int argc, char *argv[]) {
//          int i=0;
//          printf("\ncmdline args count=%s", argc);
//
//          /* First argument is executable name only */
//          printf("\nexe name=%s", argv[0]);
//
//          for (i=1; i< argc; i++) {
//              printf("\narg%d=%s", i, argv[i]);
//          }
//          return 0;
//      }
//      -- result --
//      cmdline args count=3
//      exe name=./cmdline
//      arg1=test1
//      arg2=test2
//
