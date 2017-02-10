//
//  header.h
//  Portal
//
//  Created by Hiroshi Tokutomi on 2017-02-10.
//  Copyright © 2017 Hiroshi. All rights reserved.
//

#ifndef header_h
#define header_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ACCOUNTSPATH "/Users/hiroshi/Documents/Github/C/Portal/Portal/Accounts.txt"
#define STUDENTSPATH "/Users/hiroshi/Documents/Github/C/Portal/Portal/Students.txt"
#define ACCOUNTLAST 2
#define COURSESLAST 6
#define STUDENTSLAST 7
#define STUDENTSCOURSESLAST 3

#define CHARLENGTH 256

struct account{
    char *studentId;
    char *password;
};

#endif /* header_h */
