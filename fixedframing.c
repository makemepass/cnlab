#include <stdio.h>
#include <string.h>
int main() {
    char data[100];
    int fl, i, n;
    printf("Enter the string: ");
    scanf("%s", data);
    printf("Enter frame length: ");
    scanf("%d", &fl);
    n = strlen(data);
    printf("\nFrames:\n");
    for(i = 0; i < n; i++) {
        printf("%c", data[i]);
        if((i+1) % fl == 0 || i == n-1) {
            printf("\n");
        }
    }
    return 0;
}
