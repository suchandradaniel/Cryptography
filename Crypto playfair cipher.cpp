#include <stdio.h>
#include <ctype.h>
#include <string.h>

char m[5][5] = {
    {'M','F','H','I','K'},
    {'U','N','O','P','Q'},
    {'Z','V','W','X','Y'},
    {'E','L','A','R','G'},
    {'D','S','T','B','C'}
};

void pos(char c, int *r, int *c2) {
    if (c == 'J') c = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (m[i][j] == c) { *r = i; *c2 = j; return; }
}

int main() {
    char msg[] = "Must see you over Cadogan West. Coming at once.", in[200], out[200];
    int i, j = 0, len;

    for (i = 0; msg[i]; i++)
        if (isalpha(msg[i])) in[j++] = toupper(msg[i] == 'J' ? 'I' : msg[i]);
    if (j % 2) in[j++] = 'X';
    in[j] = 0;

    for (i = 0; i < j; i += 2) {
        int r1, c1, r2, c2;
        pos(in[i], &r1, &c1); pos(in[i + 1], &r2, &c2);
        if (r1 == r2)
            out[i] = m[r1][(c1 + 1) % 5], out[i + 1] = m[r2][(c2 + 1) % 5];
        else if (c1 == c2)
            out[i] = m[(r1 + 1) % 5][c1], out[i + 1] = m[(r2 + 1) % 5][c2];
        else
            out[i] = m[r1][c2], out[i + 1] = m[r2][c1];
    }
    out[j] = 0;
    printf("Encrypted: %s\n", out);
    return 0;
}
