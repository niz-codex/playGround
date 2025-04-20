#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char getRandomChar() {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";
    return charset[rand() % (sizeof(charset) - 1)];
}

void generatePassword(int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", getRandomChar());
    }
    printf("\n");
}

int main() {
    int length;
    printf("Enter password length: ");
    scanf("%d", &length);

    srand(time(NULL));
    printf("Generated Password: ");
    generatePassword(length);
    return 0;
}
