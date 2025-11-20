//implementing checksum
#include <stdio.h>

int main() {
    int n, i;
    int data[20], sum = 0, checksum;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("\n=== Sender Side ===\n");
    for (i = 0; i < n; i++) {
        printf("Enter data %d : ", i + 1);
        scanf("%d", &data[i]);
        sum += data[i];
    }

    printf("Sender raw sum = %d\n", sum);

    // Wrap-around if sum exceeds 8 bits
    int wrappedSum = sum;
    while (wrappedSum >> 8) {
        wrappedSum = (wrappedSum & 255) + (wrappedSum >> 8);
    }
    printf("Sender wrapped sum = %d\n", wrappedSum);

    checksum = ~wrappedSum & 255;
    printf("Sender checksum = %d\n", checksum);

    // ================= Receiver side =================
    int recvSum = 0, recvData;

    printf("\n=== Receiver Side ===\n");
    for (i = 0; i < n; i++) {
        printf("Enter received word %d : ", i + 1);
        scanf("%d", &recvData);
        recvSum += recvData;
    }

    printf("Enter received checksum : ");
    scanf("%d", &recvData);
    recvSum += recvData;

    printf("Receiver sum = %d\n", recvSum);

    int recvWrapped = recvSum;
    while (recvWrapped >> 8) {
        recvWrapped = (recvWrapped & 255) + (recvWrapped >> 8);
    }
    printf("Receiver wrapped sum = %d\n", recvWrapped);

    int finalCheck = ~recvWrapped & 255;
    printf("Receiver final check value = %d\n", finalCheck);

    if (finalCheck == 0)
        printf("\nResult: Accepted (No Error Detected)\n");
    else
        printf("\nResult: Rejected (Error Detected)\n");

    return 0;
}