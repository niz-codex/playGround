#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // For usleep

void generatePassword(char *password, int length) {
    static const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-+";
    static const int charsetLength = sizeof(charset) - 1;

    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charsetLength];
    }

    password[length] = '\0'; // Null-terminate the string
}

int main() {
    FILE *file = fopen("passwords.txt", "a"); // Open in append mode
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    char password[19]; // 18 characters + 1 for null terminator
    int numPasswords = 100; // Set the number of passwords you want to generate

    // Seed random number generator using time
    srand((unsigned)time(NULL));

    // Generate passwords and write them to file
    for (int i = 0; i < numPasswords; i++) {
        generatePassword(password, 18); // Generate a password
        fputs(password, file);          // Write the password to file
        fputs("\n", file);              // Add a newline after each password

        // Add a small delay to prevent overwhelming the system
        usleep(100000); // 100ms delay to avoid high CPU usage
    }

    fclose(file); // Close the file
    printf("Generated %d passwords and saved to passwords.txt\n", numPasswords);
    return 0;
}
