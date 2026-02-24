#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "compressor.h"

void rleCompressor(char *input, char *result){
    int length = strlen(input);
    int count = 1;
    int pos = 0;

    for (int i = 0; input[i]; i++) {
            input[i] = toupper(input[i]);
        }

    for(int i = 0; i < length; i++){
        if(i < length - 1 && input[i] == input[i + 1]){
            count++;
        } else {
            pos += sprintf(result + pos, "%d%c", count, input[i]);
            count = 1;
        }
    }
}

void rleDecompressor(char *input, char *result){
    int count = 0;
    int pos = 0;

    for (int i = 0; input[i]; i++) {
        input[i] = toupper(input[i]);
    }   

    for(int i = 0; input[i] != '\0'; i++){
        if(isdigit(input[i])){
            count = count * 10 + (input[i] - '0');
        } else if(input[i] == ' '){
            continue;
        } else {
            for(int j = 0; j < count; j++){
                result[pos++] = input[i];
            }   
            count = 0;
        }
    }
}