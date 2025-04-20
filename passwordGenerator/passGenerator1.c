#include <stdio.h>

int main() {
    FILE *file = fopen("pinlist.txt", "w");
    if (!file) {
        perror("File error");
        return 1;
    }

    for (int i = 0; i < 10000; i++) {
        fprintf(file, "%04d\n", i); // Format as 0000, 0001, ..., 9999
    }

    fclose(file);
    printf("Generated all 4-digit PINs.\n");
    return 0;
}
