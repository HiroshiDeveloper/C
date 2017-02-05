//
//  main.c
//  Assignment6
//
//  Created by Hiroshi Tokutomi on 2017-02-04.
//  Copyright © 2017 Hiroshi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*** problem1 ***
// number1-1-1
struct date{
    int day;
    int month;
    int year;
};

// number1-2-1
struct machine{
    int name;
    char *memory;
};

// number1-3-1
struct time{
    int *day;
    int *month;
    int *year;
};

//*** problem3 ***
struct item{
    int age;
    struct item *next;
};

//*** problem1 ***
void problem1();

//*** problem3 ***

int main(int argc, const char * argv[]) {
    problem1();
    return 0;
}

//**********************
// Problem1
//**********************
void problem1(){
    // number1-1-2,3
    struct date *dates;
    dates = (struct date*)malloc(sizeof(struct date));
    dates->day = 10;
    
    // number1-2-2, 3, 4
    struct machine *mpu641;
    mpu641->memory = "CPUtype";
    mpu641->name = 10;
    
    // number1-3-2
    struct time *times;
    times = (struct time*)malloc(sizeof(struct time));
    int day10 = 10;
    times->day = &day10;
    
    // number1-3-3, 4
    struct time *sample[10];
    int month12 = 12;
    sample[2]->month = &month12;
    
    // number1-3-5, 6, 7, 8
    int *pointerDay, valDay = 10;
    int *pointerMonth, valMonth = 5;
    int *pointerYear, valYear = 2000;
    for(int i = 0; i < 10; i++){
        sample[i] = (struct time*)malloc(sizeof(struct time));
        pointerDay = &valDay;
        pointerMonth = &valMonth;
        pointerYear = &valYear;
        sample[i]->day = pointerDay;
        sample[i]->month = pointerMonth;
        sample[i]->year = pointerYear;
        printf("sample[%d] address %p,day:%d %p, month:%d %p, year:%d %p\n", i, &sample[i], *(sample[i]->day), &sample[i]->day, *(sample[i]->month), &sample[i]->month, *(sample[i]->year), &sample[i]->year);
        free(sample[i]);
    }
}
