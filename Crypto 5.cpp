#include <stdio.h>
#include <string.h>
void encryptRailFence(char *msg) {
    int len = strlen(msg);
    char rail1[100], rail2[100];
    int k1 = 0, k2 = 0;
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0)
            rail1[k1++] = msg[i];
        else
            rail2[k2++] = msg[i];
    }
    rail1[k1] = '\0';
    rail2[k2] = '\0';
    printf("Encrypted: %s%s\n", rail1, rail2);
}
int main() {
    char message[100];
    printf("Enter message: ");
    scanf("%[^\n]", message);
    encryptRailFence(message);
    return 0;
}
