#include <stdio.h>
#include <string.h>
char data[50], g[20], temp[20];
void XOR() {
    for (int i = 0; i < strlen(g); i++)
        temp[i] = (temp[i] == g[i] ? '0' : '1');
}
void CRC() {
    int i, j;
    for (i = 0; i < strlen(g); i++)
        temp[i] = data[i];
    do {
        if (temp[0] == '1')
            XOR();
        for (j = 0; j < strlen(g) - 1; j++)
            temp[j] = temp[j + 1];
        temp[j] = data[i++];
    } while (i <= strlen(data));
}
int main() {
    int n, m, k;
    strcpy(g, "110000001111");
    printf("Enter data: ");
    scanf("%s", data);
    n = strlen(data);
    m = strlen(g);
    printf("\nGenerator Polynomial (g): %s\n", g);
    printf("Length of g: %d\n", m);
    printf("Length of data: %d\n", n);
    for (k = n; k < n + m - 1; k++)
        data[k] = '0';
    data[k] = '\0';
    printf("\nModified Data (after appending %d zeros): %s\n", m - 1, data);
    CRC();
    printf("\nCRC Remainder: %s\n", temp);
    int j;
    for (int k = n, j = 0; k < n + m - 1; k++, j++)
        data[k] = temp[j];
    data[n + m - 1] = '\0';
    printf("\nFinal Codeword (Data + Remainder): %s\n", data);
    return 0;
}
