#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc+1]) {
    if (argc > 1) {
        int size = argc - 1;
        double list[size];
        for (size_t i = 0; i < size; ++i) {
            list[i] = strtod(*++argv, 0);
            printf("%.2f ", list[i]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}