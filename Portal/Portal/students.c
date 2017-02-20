//
//  students.c
//  Portal
//
//  Created by Hiroshi Tokutomi on 2017-02-16.
//  Copyright © 2017 Hiroshi. All rights reserved.
//

#include "header.h"

char *extractWords(char *line);
char startingNumber(char *line);
void printListStudent(char **studentIdList, char **studentNameList, int counter);

void studentIdAndName(char *fileName){
    
    FILE *fp;
    size_t len = 0;
    ssize_t read;
    char *line = NULL, *words = NULL;
    char firstCharacter;
    char *studentIdList[LISTOFSTUDENT], *studentNameList[LISTOFSTUDENT];
    int counter = 0;
    
    // file open
    fp=fopen(fileName, "r");
    
    // error if the file is not found
    if (fp == NULL){
        printf("Cannot find the text file in this URL: %s\n", fileName);
        return;
    }
    
    // read the file line by line
    while ((read = getline(&line, &len, fp)) != -1) {
        words = extractWords(line);
        firstCharacter = startingNumber(line);
        
        if(firstCharacter == '1'){
            studentIdList[counter] = malloc(sizeof (char) * STUDENTIDLENGTH);
            studentIdList[counter] = words;
        }else if(firstCharacter == '2'){
            studentNameList[counter] = malloc(sizeof (char) * STUDENTNAMELENGTH);
            studentNameList[counter] = words;
            counter++;
        }
    }
    printListStudent(studentIdList, studentNameList, counter);
    free(words);
    fclose(fp);
    return;
}

void printListStudent(char **studentIdList, char **studentNameList, int counter){
    
    printf("There are %d students in CICCC as following:\n", counter);
    for(int i = 0; i < counter; i++){
        printf("%d) %s: %s\n", i + 1, studentNameList[i], studentIdList[i]);
        free(studentIdList[i]);
        free(studentNameList[i]);
    }
    printf("\n");
}

