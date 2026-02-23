#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "compressor.h"

void menu_options(){
    printf("\n ***OPTIONS*** \n");
    printf("1. Compress\n");
    printf("2. Decompress\n");
    printf("3. Exit\n");
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
                printf("Enter text to Compress: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;

                for (int i = 0; input[i]; i++) {
                    input[i] = toupper(input[i]);
                }

                rleCompressor(input);
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
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please select 1, 2, or 3.\n");
        }
    }

    return 0;
}