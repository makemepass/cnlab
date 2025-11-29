#include <stdio.h>
#include <string.h>

#define FLAG "01111110"

int main() {
    char in[100], stuff[200] = FLAG, destuff[200];
    int i, j = 0, count = 0;

    printf("Enter binary value: ");
    scanf("%s", in);

    // Bit Stuffing
    for(i = 0; in[i]; i++) {
        strncat(stuff, &in[i], 1);
        count = (in[i] == '1') ? count + 1 : 0;
        if(count == 5) strcat(stuff, "0"), count = 0;
    }

    strcat(stuff, FLAG);
    printf("\nStuffed: %s\n", stuff);

    // Bit De-stuffing
    int start = strlen(FLAG), end = strlen(stuff) - strlen(FLAG);
    for(i = start; i < end; i++) {
        destuff[j++] = stuff[i];
        count = (stuff[i] == '1') ? count + 1 : 0;
        if(count == 5) i++, count = 0;
    }
    destuff[j] = '\0';

    printf("Destuffed: %s\n", destuff);
    return 0;
}
