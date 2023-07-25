#include <limits.h>
#include <stdio.h>
#include "main.h"

int main(void)
{
    int len_1, len_2;

    printf("----------------------\n");
    printf("---> R (13) CASES <---\n");
    printf("----------------------\n");

    /* Test case for NULL string input: */
    len_1 = printf("Expected output: %s\n", "(null)");
    len_2 = _printf("Current output:  %R\n", NULL);
    printf("Expected length: [%d]\n", len_1);
    printf("Current length:  [%d]\n", len_2);

    /* Test case for empty string input: */
    len_1 = printf("Expected output: %s\n", "");
    len_2 = _printf("Current output:  %R\n", "");
    printf("Expected length: [%d]\n", len_1);
    printf("Current length:  [%d]\n", len_2);

    /* Test case for lowercase string input: */
    len_1 = printf("Expected output: %s\n", "hello");
    len_2 = _printf("Current output:  %R\n", "hello");
    printf("Expected length: [%d]\n", len_1);
    printf("Current length:  [%d]\n", len_2);

    /* Test case for uppercase string input: */
    len_1 = printf("Expected output: %s\n", "WORLD");
    len_2 = _printf("Current output:  %R\n", "WORLD");
    printf("Expected length: [%d]\n", len_1);
    printf("Current length:  [%d]\n", len_2);

    /* Test case for mixed case string input: */
    len_1 = printf("Expected output: %s\n", "HeLLo WoRLd");
    len_2 = _printf("Current output:  %R\n", "HeLLo WoRLd");
    printf("Expected length: [%d]\n", len_1);
    printf("Current length:  [%d]\n", len_2);

    return (0);
}

