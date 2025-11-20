#include <stdio.h>
#include <string.h>
#define FLAG 'F' 
#define ESC 'E'  
int main() {
    char input[100], stuffed[200], destuffed[100];
    int i, j = 0, k = 0;
    printf("Enter data: ");
    scanf("%s", input);
    stuffed[j++] = FLAG;
    for(i = 0; i < strlen(input); i++) {
        if(input[i] == FLAG || input[i] == ESC) {
            stuffed[j++] = ESC;
        }
        stuffed[j++] = input[i];
    }
    stuffed[j++] = FLAG;
    stuffed[j] = '\0';
    printf("\nStuffed: %s\n", stuffed);
    for(i = 1; i < strlen(stuffed) - 1; i++) {
        if(stuffed[i] == ESC) {
            i++; 
        }
        destuffed[k++] = stuffed[i];
    }
    destuffed[k] = '\0';
    printf("Destuffed: %s\n", destuffed);
    return 0;
}
