#include <stdio.h>
#include <string.h>

#define FLAG "01111110"

int main() {
    char input[100], stuffed[200], destuffed[200];
    int i, j = 0, count = 0;

    printf("Enter binary value: ");
    scanf("%s", input);

    // Start with FLAG
    strcpy(stuffed, FLAG);

    // Bit Stuffing
    for(i = 0; i < strlen(input); i++) {
        int len = strlen(stuffed);
        stuffed[len] = input[i];
        stuffed[len + 1] = '\0';

        if(input[i] == '1') {
            count++;
            if(count == 5) {
                strcat(stuffed, "0");  // Stuff a 0
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    // End with FLAG
    strcat(stuffed, FLAG);

    printf("\nStuffed: %s\n", stuffed);

    // Bit Destuffing
    j = 0;
    count = 0;
    for(i = strlen(FLAG); i < strlen(stuffed) - strlen(FLAG); i++) { // skip flags
        destuffed[j++] = stuffed[i];
        if(stuffed[i] == '1') {
            count++;
            if(count == 5) {
                i++; // Skip stuffed 0
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    destuffed[j] = '\0';

    printf("Destuffed: %s\n", destuffed);

    return 0;
}
