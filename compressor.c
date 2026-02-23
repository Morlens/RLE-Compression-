#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "compressor.h"

void rleCompressor(char *input){
    int length = strlen(input);
    int count = 1;

    printf("\n\nHere is the result: ");
    for(int i = 0; i < length; i++){
        if(i < length - 1 && input[i] == input[i + 1]){
            count++;
        } else {
            printf("%d%c ", count, input[i]);
            count = 1;
        }
    }
    printf("\n\n");
}

void rleDecompressor(char *input){
    int count = 0;

    printf("\n\nHere is the result: ");
    for(int i = 0; input[i] != '\0'; i++){
        if(isdigit(input[i])){
            count = count * 10 + (input[i] - '0');
        } else {
            for(int j = 0; j < count; j++){
                printf("%c", input[i]);
            }
            count = 0;
        }
    }
    printf("\n\n");
}