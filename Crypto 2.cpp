#include <stdio.h>
int main() 
{
    char msg[] = "HOWAREYOU";
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char enc[100], dec[100];
    int i;
    // Encrypt
    for (i = 0; msg[i] != '\0'; i++)
        enc[i] = key[msg[i] - 'A'];
    enc[i] = '\0';
    // Decrypt
    for (i = 0; enc[i] != '\0'; i++)
        for (int j = 0; j < 26; j++)
            if (enc[i] == key[j])
                dec[i] = 'A' + j;
    dec[i] = '\0';
    printf("Original: %s\n", msg);
    printf("Encrypted: %s\n", enc);
    printf("Decrypted: %s\n", dec);
    return 0;
}