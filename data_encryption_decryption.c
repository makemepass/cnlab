#include <stdio.h>
#include <string.h>

char shift(char c, int key) {
    if (c >= 'a' && c <= 'z')
        return (c - 'a' + key + 26) % 26 + 'a';
    if (c >= 'A' && c <= 'Z')
        return (c - 'A' + key + 26) % 26 + 'A';
    return c; 
}

int main() {
    char text[100];
    int key, i;

    printf("enter a message: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("enter a key(1-25): ");
    scanf("%d", &key);

    // Encrypt
    for (i = 0; text[i] != '\0'; i++)
        text[i] = shift(text[i], key);

    printf("encrypted message: %s\n", text);

    // Decrypt
    for (i = 0; text[i] != '\0'; i++)
        text[i] = shift(text[i], -key);

    printf("decrypted message: %s\n", text);

    return 0;
}
