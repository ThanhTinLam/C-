#include <iostream>
#include "cstring.h"

unsigned int length(char str[]) {
  // returns the length of the string including zero (0)
    int i = 0;
    while ( str[i] != '\0')
    { i ++;
    }
    return i;
}

unsigned int find(char str[], char character) {
  // returns 
  //  - the index of the first occurence of character in str
  //  - the size if the character is not found
    int i;
    int a = length(str);
    for (i=0; i < a; i++) {
        if (str[i] == character) {
            return (i);
        }
    } return length(str);
}

bool equalStr(char str1[], char str2[]) {
  // returns true if they are equal and false if they are not
    int i;
    int max;
    if (length(str1)>length(str2)) {
        max = length(str1);
    }else if (length(str2)>length(str1)) {
        max = length(str2);
    }else {
        max = length(str1);
    }for (i=0; i < max; i++) {
        if (str1[i]==str2[i]) {
            continue;}
        else {
            return false;}
    }return true;
}