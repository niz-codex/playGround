#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePassword(char *password, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-+";
    int charsetLength = sizeof(charset) - 1;
    int i;

    srand(time(NULL)); // Seed the random number generator

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % charsetLength];
    }

    password[length] = '\0'; // Null terminate the string
}

int main() {
    char password[19]; // 12 characters + 1 for null terminator
    generatePassword(password, 18);
    printf("Generated Password: %s\n", password);
    return 0;
}
