//
//  transcript.c
//  Portal
//
//  Created by Hiroshi Tokutomi on 2017-02-16.
//  Copyright © 2017 Hiroshi. All rights reserved.
//

#include "header.h"
#include "transcript.h"

char *extractWords(char *line);
char startingNumber(char *line);
char *getCourseName(char *fileName, char *courseId);

void transcript(struct student *student, char *fileName){
    FILE *fp;
    size_t len = 0;
    ssize_t read;
    char *line = NULL, *words, firstCharacter, *courseName;
    int index = 1, flg = 0;
    
    // file open
    fp=fopen(fileName, "r");
    
    // error if the file is not found
    if (fp == NULL){
        printf("Cannot find the text file in this URL: %s\n", fileName);
        exit(0);
    }
    
    // introduction
    printf("\nHi %s %s,\n", student->gender2, student->name);
    printf("Here is your transcript:\n");
    
    // read the file line by line
    while ((read = getline(&line, &len, fp)) != -1) {
        words = extractWords(line);                     // extract words e.g.) StudentId, Pass
        firstCharacter = startingNumber(line);
        if(firstCharacter == '1' && strcmp(words, student->studentId) == 0){
            flg = 1;
        }else if(firstCharacter == '2' && flg == 1){
            courseName = getCourseName(COURSESPATH, words);
            printf("%d) %s: %s: ", index, words, courseName);
        }else if(firstCharacter == '3' && flg == 1){
            printf("%s\n", words);
            index++;
            flg = 0;
        }
    }
    printf("\n");
    fclose(fp);
    return;
}

char startingNumber(char *line){
    char firstCharacter;
    firstCharacter = line[0];
    return firstCharacter;
}

char *getCourseName(char *fileName, char *courseId){
    FILE *fp;
    size_t len = 0;
    ssize_t read;
    char *line = NULL, *words;
    char *courseName;
    int flg = 0;
    
    // file open
    fp=fopen(fileName, "r");
    
    while ((read = getline(&line, &len, fp)) != -1) {
        words = extractWords(line);
        if(flg == 1){           // if course Id is founded, get the course name
            courseName = words;
            break;
        }else if(strcmp(words, courseId) == 0){
            flg = 1;
        }
    }
    fclose(fp);
    return courseName;
}

