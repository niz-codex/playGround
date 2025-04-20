#include <stdio.h>
#include <ctype.h>

int main() {
    char str[1000];
    int count = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);  // Read input string

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha((unsigned char)str[i])) {
            count++;
        }
    }

    printf("Total number of letters: %d\n", count);
    return 0;
}
