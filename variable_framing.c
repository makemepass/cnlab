#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    int n, i, j, k = 0;
    printf("Enter the string: ");
    scanf("%s", str);
    printf("Enter number of frames: ");
    scanf("%d", &n);
    int frames[n];
    printf("Enter the size of each frame:\n");
    for(i = 0; i < n; i++) {
        printf("Frame %d size: ", i);
        scanf("%d", &frames[i]);
    }
    printf("\nFrames:\n");
    for(i = 0; i < n && k < strlen(str); i++) {
        for(j = 0; j < frames[i] && k < strlen(str); j++) {
            printf("%c", str[k]);
            k++;
        }
        printf("\n");
    }
    return 0;
}
