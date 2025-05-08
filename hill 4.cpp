#include <stdio.h>
#include <string.h>

void vigenere(char *text, char *key, int encrypt) {
    int i, j = 0, len = strlen(text), klen = strlen(key);
    for (i = 0; i < len; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            int t = text[i] - 'A';
            int k = key[j % klen] - 'A';
            int c = encrypt ? (t + k) % 26 : (t - k + 26) % 26;
            printf("%c", c + 'A');
            j++;
        } else {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}

int main() {
    char text[100], key[100];

    printf("Enter UPPERCASE text: ");
    gets(text);
    printf("Enter UPPERCASE key: ");
    gets(key);

    printf("Encrypted: ");
    vigenere(text, key, 1);

    printf("Decrypted: ");
    vigenere(text, key, 0);

    return 0;
}
