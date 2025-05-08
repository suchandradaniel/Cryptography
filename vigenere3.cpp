#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char pt[100], key[100], ct[100];
    int i, j, klen;

    printf("Plaintext: ");
    scanf("%s", pt);

    printf("Key: ");
    scanf("%s", key);

    klen = strlen(key);
    for (i = 0, j = 0; pt[i] != '\0'; i++) {
        char p = tolower(pt[i]);
        char k = tolower(key[j % klen]);
        ct[i] = ((p - 'a' + (k - 'a')) % 26) + 'a';
        j++;
    }
    ct[i] = '\0';

    printf("Ciphertext: %s\n", ct);
    return 0;
}
