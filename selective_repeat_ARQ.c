#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, win;

    printf("Enter number of frames to send: ");
    scanf("%d", &n);

    printf("Enter window size: ");
    scanf("%d", &win);

    int ack[n];
    for (int i = 0; i < n; i++) {
        ack[i] = 0;
    }

    srand(time(0));

    printf("\nSelective Repeat ARQ Simulation\n\n");

    for (int i = 0; i < n; i++) {
        int tries = 0;

        while (!ack[i]) {
            tries++;
            printf("Sending Frame %d (Attempt %d)...\n", i, tries);

            if (rand() % 2 == 0) {
                printf("ACK %d received.\n", i);
                ack[i] = 1;
            } else {
                printf("ACK %d lost! Retransmitting...\n", i);
            }
        }

        if ((i + 1) % win == 0) {
            printf("Window slid.\n\n");
        }
    }

    printf("\nAll frames sent and acknowledged successfully!\n");
    return 0;
}
