//
//  students.c
//  Portal
//
//  Created by Hiroshi Tokutomi on 2017-02-16.
//  Copyright © 2017 Hiroshi. All rights reserved.
//

#include "header.h"
#include "students.h"

char *extractWords(char *line);
char startingNumber(char *line);

void studentIdAndName(char *fileName){
    FILE *fp;
    size_t len = 0;
    ssize_t read;
    char *line = NULL, *words, *tmpId;
    char firstCharacter;
    
    // file open
    fp=fopen(fileName, "r");
    
    // error if the file is not found
    if (fp == NULL){
        printf("Cannot find the text file in this URL: %s\n", fileName);
        exit(0);
    }
    
    // read the file line by line
    while ((read = getline(&line, &len, fp)) != -1) {
        words = extractWords(line);
        firstCharacter = startingNumber(line);
        if(firstCharacter == '1'){
            tmpId = words;
        }else if(firstCharacter == '2'){
            
        }
        
        free(words);
    }
    fclose(fp);
    return;
}

