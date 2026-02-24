#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "compressor.h"


int main(int argc, char *argv[]){
   if(argc != 4){
    printf("Usage: %s.exe -c | -d input_file output_file\n", argv[0]);
    return 1;
   }

   char *option = argv[1];
   char *input_file = argv[2];
   char *output_file = argv[3];

   FILE *in = fopen(input_file, "r");
   if(!in){
    perror("Error opening input file.");
    return 1;
   }

   FILE *out = fopen(output_file, "w");
   if(!out){
        perror("Error opening output file");
        fclose(in);
        return 1;
   }    

   char buffer[1024];
   char result[1024];
   int index = 0;
   int ch;

   while((ch = fgetc(in)) != EOF && index < 1023){
    buffer[index++] = ch;
    }
    buffer[index] = '\0';
 
    if(strcmp(option, "-c") == 0){
        rleCompressor(buffer, result);
    }else if(strcmp(option, "-d") == 0){
        rleDecompressor(buffer, result);
    }else {
        printf("Unknown option: %s\n", option);
        fclose(in);
        fclose(out);
        return 1;
    }

    fprintf(out, "%s", result);

    fclose(in);
    fclose(out);

    printf("Operation completed successfully.\n");
    return 0;
}