#include <stdio.h>
#include <string.h>
int main() {
    char message[] = "HELLOCRYPTOWORLD"; 
    char key[] = "3214"; 
    int cols = strlen(key);
    int len = strlen(message);
    int rows = (len + cols - 1) / cols; // Ceiling division
    char grid[rows][cols];
    int k = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            grid[i][j] = (k < len) ? message[k++] : 'X'; 
    printf("Encrypted: ");
    for (int k = 1; k <= cols; k++) {
        for (int j = 0; j < cols; j++) {
            if (key[j] - '0' == k) {
                for (int i = 0; i < rows; i++)
                    printf("%c", grid[i][j]);
            }
        }
    }
    printf("\n");
    return 0;
}
