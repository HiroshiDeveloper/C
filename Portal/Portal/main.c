//
//  main.c
//  Portal
//
//  Created by Hiroshi Tokutomi on 2017-02-05.
//  Copyright © 2017 Hiroshi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ACCOUNTSPATH "/Users/hiroshi/Documents/Github/C/Portal/Portal/Accounts.txt"
#define STUDENTSPATH "/Users/hiroshi/Documents/Github/C/Portal/Portal/Students.txt"

void loginMenu();
void file(char *fileName, int storeSize);

int main(int argc, const char * argv[]) {
    loginMenu();
    
    return 0;
}

void loginMenu(){
    char studentId;
    char password;
    int storeSize = 0;
    
    printf("******************************************\n");
    printf("Please enter your account to login:\n");
    printf("******************************************\n");
    printf("StudentId: ");
    scanf("%s", &studentId);
    printf("Password: ");
    scanf("%s", &password);
    
    storeSize = 2;
    file(ACCOUNTSPATH, storeSize);
}

void file(char *fileName, int storeSize){
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int flg = 0;
    int length = 0;
    
    // file open
    fp=fopen(fileName, "r");
    
    // error if the file is not found
    if (fp == NULL){
        printf("Cannot find the text file in this URL: %s\n", fileName);
        exit(0);
    }
    
    // read the file line by line
    while ((read = getline(&line, &len, fp)) != -1) {
        //printf("Retrieved line of length %zu :\n", read);
        //printf("%s", line);
        flg = 0;
        length = (int)(strlen(line) - 2);
        for(int i = 0; i < length; i++){
            if(flg == 1){
                printf("%c ", line[i]);
            }else if(line[i] == '\"'){
                flg = 1;
            }
        }
        printf("\n");
    }
}

//void check(){
//
//}
