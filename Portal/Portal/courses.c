//
//  courses.c
//  Portal
//
//  Created by Hiroshi Tokutomi on 2017-02-16.
//  Copyright © 2017 Hiroshi. All rights reserved.
//

#include "header.h"
#include "courses.h"

char *extractWords(char *line);
int arrayComma(char *courseName, char *array[]);
char *mrOrMs(char *gender);

void courseFile(struct student *student, char *fileName, int offeredFlg){
    
    FILE *fp;
    size_t len = 0;
    ssize_t read;
    char *line = NULL, *words;
    char *arrayCourses[MAXARRAY];   // devided courses by comma
    char *gender2 = mrOrMs(student->gender);
    int courseLength = 0, flg = 0, counter = 0, index = 1;
    
    // file open
    fp=fopen(fileName, "r");
    
    // error if the file is not found
    if (fp == NULL){
        printf("Cannot find the text file in this URL: %s\n", fileName);
        free(student);
        exit(0);
    }
    
    // get the size of courses(courseLength) and put divided courses into array(arrayComma)
    courseLength = arrayComma(student->courses, arrayCourses);
    
    // introduction
    if(offeredFlg == 0){
        printf("Hi %s %s,\n", gender2, student->name);
        printf("You have taken the following courses:\n");
    }else{
        printf("\nThe following courses are offered in CICCC:\n");
    }
    
    // read the file line by line
    while ((read = getline(&line, &len, fp)) != -1) {
        
        words = extractWords(line);                         // extract words e.g.) StudentId, Pass
        
        if(counter % 2 == 0){                               // line is even (courseId)
            if(offeredFlg == 0){                            // main menu 2
                for(int i = 0; i < courseLength; i++){
                    if(strcmp(words, arrayCourses[i]) == 0){
                        printf("%d) %s ", index, words);    // get courseId e.g.) MASP101
                        flg = 1;
                    }
                }
            }else{                                          // main menu 6
                printf("%d) %s ", index, words);            // get courseId e.g.) MASP101
                index ++;
            }
        }else{
            if(offeredFlg == 0){                            // main menu 2
                // read even lines && the odd line is matched with course
                if(flg == 1){
                    printf("%s\n", words);                  // get course description e.g.) Objective-C
                    flg = 0;
                    index++;                                // index of students list e.g.) 1), 2)
                }
            }else{                                          // main menu 6
                printf("%s\n", words);
            }
        }
        counter++;
    }
    printf("\n");
    fclose(fp);
    return;
}

// return the size of courses(counter) and put divided courses into array(*array[])
// e,g.)
// MADP101, MADP201, MADP301 -> [MADP101, MADP201, MADP301] and counter(the size of array)
int arrayComma(char *courseName, char *array[]){
    
    char *tok;
    char *mark = ",";
    int counter = 0;
    
    tok = strtok(courseName, mark);
    while(tok != NULL){
        array[counter] = malloc(sizeof (char) * CHARLENGTH);
        array[counter] = tok;
        tok = strtok(NULL, mark);   // after twice
        counter++;
    }
    return counter;     // size of course array
}
