#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define KNRM "\x1b[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"

void swap(double* px, double* py) {
    double temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

void test_swap() {
    double list[5] = {1, 2, 3, 4, 5};
    double checklist[5] = {1, 4, 3, 2, 5};

    swap(&list[1], &list[3]);

    for(int i = 0; i < 5; ++i) {
        if (list[i] != checklist[i]) {
            printf("%s[FAILED]%s test swap\n", KRED, KNRM);
            return;
        } 
    }

    printf("%s[PASSED]%s test swap\n", KGRN, KNRM);
}

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

    test_swap();

    return EXIT_SUCCESS;
}