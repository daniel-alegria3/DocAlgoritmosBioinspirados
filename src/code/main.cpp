#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// https://pubs.opengroup.org/onlinepubs/007908775/xsh/systime.h.html

#define CS "%lu"
typedef unsigned long int Decimal;

Decimal str_to_dec( char *binary );

int main (int argc, char *argv[]) {
    // char *binary = "-1011";

    char *binary1 = (char*) malloc(118);
    printf("Enter binary1: ");
    scanf("\n");
    scanf("%[^\n]*c", binary1);
    Decimal decimal1 = str_to_dec(binary1);

    char *binary2 = (char*) malloc(118);
    printf("Enter binary2: ");
    scanf("\n");
    scanf("%[^\n]*c", binary2);
    Decimal decimal2 = str_to_dec(binary2);

    Decimal rpta = decimal1 * decimal2;

    printf(CS " * " CS  " = " CS "\n", decimal1, decimal2, rpta);

    return 0;
}

Decimal str_to_dec( char *binary ) {
    int len = strlen(binary);

    Decimal decimal = 0;
    char ch;
    int bit = 0;
    int is_negative = 0;
    for (int i = len-1; i >= 0; --i) {
        ch = binary[i];
        switch (ch) {
            case '1':
                decimal |= ((long int)1) << bit;
                // Note: do not break here
            case '0':
                ++bit;
                break;
            case '-':
                is_negative = 1;
                break;
            case ' ': case '\t': case '\n':
                 break;
            default:
                fprintf(stderr, "Error: Input is not Binary Number.\n");
                return 666;
                // perror()
        }
    }

    if (is_negative) {
        decimal = ~decimal+1;
    }

    return decimal;
}

