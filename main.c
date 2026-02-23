#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "compressor.h"

void menu_options(){
    printf("\n ***OPTIONS*** \n");
    printf("1. Compress\n");
    printf("2. Decompress\n");
    printf("3. Compress (file-based)\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");

}

int main(){
    int choice;
    char input[256];
    char choiceStr[10];

    while(1){
        menu_options();
        
        fgets(choiceStr, sizeof(choiceStr), stdin);
        choiceStr[strcspn(choiceStr, "\n")] = 0;
        choice = atoi(choiceStr);

        switch (choice) {
            case 1:
            char compressedText[256];
                printf("Enter text to Compress: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;

                rleCompressor(input, compressedText);
                
                printf("Compressed Text: %s\n", compressedText);
                break;

            case 2:
                printf("Enter text to Decompress: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;

                for (int i = 0; input[i]; i++) {
                    input[i] = toupper(input[i]);
                }

                rleDecompressor(input);
                break;
            case 3:
                char filename[256]; // input file name
                char buffer[256];   // buffer for file content
                char compressed[256];   // compressed result
                char outputFilename[20]; // output file name

                printf("\nEnter input file name: ");
                scanf("%255s", filename);

                int c;
                while ((c = getchar()) != '\n' && c != EOF);

                FILE *file = fopen(filename, "r");
                if(file == NULL){
                    perror("File error");
                    break;
                }

            
                int ch = '\0';
                int index = 0;
                   
                while((ch = fgetc(file)) != EOF && index < 256){
                    buffer[index] = ch;
                    index++;
                }
                   buffer[index] = '\0';
                
                fclose(file);

                rleCompressor(buffer, compressed);
                

                printf("%s\n", compressed);

                printf("\nEnter output file name: ");
                scanf("%255s", outputFilename);  

                while ((c = getchar()) != '\n' && c != EOF);

                FILE *file2 = fopen(outputFilename, "w");
                 if(file2 == NULL){
                    perror("File error");
                    break;
                }

                fprintf(file2, "%s", compressed);

                fclose(file2);

                printf("\nResult succesfully written to %s.\n", outputFilename);

                break;

            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please select 1, 2, or 3.\n");
        }
    }

    return 0;
}