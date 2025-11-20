#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int totalFrames, windowSize;
    int base = 0, nextSeq = 0;

    srand(time(0));  // seed random generator

    printf("Total frames: ");
    scanf("%d", &totalFrames);
    printf("Window size: ");
    scanf("%d", &windowSize);

    printf("\nGo-Back-N Simulation:\n");

    while (base < totalFrames) {
        // Send frames in the window
        while (nextSeq < base + windowSize && nextSeq < totalFrames) {
            printf("Send %d ", nextSeq);
            nextSeq++;
        }
        printf("\n");

        // Simulate ACK or loss for the base frame
        if (rand() % 2) {
            printf("ACK %d received\n\n", base);
            base++;
        } else {
            printf("Loss at %d, retransmit window\n\n", base);
            nextSeq = base;
        }
    }

    printf("Transmission complete.\n");
    return 0;
}
