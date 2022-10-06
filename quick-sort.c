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

int partition(double* list, int low, int high) {
    double pivot = list[(low + high) / 2];

    int i = low - 1;
    int j = high + 1;

    for(;;) {
        while (list[++i] < pivot);
        while (list[--j] > pivot);

        if (i >= j) {
            return j;
        }

        swap(&list[i], &list[j]);
    }
}

void quicksort(double* list, int low, int high) {
    if (low >= 0 && low < high) {
        int p = partition(list, low, high);
        quicksort(list, low, p);
        quicksort(list, p+1, high);
    }
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

void test_quicksort() {
    int size = 5;
    double list[] = {5, 1, 4, 2, 3};
    double checklist[] = {1, 2, 3, 4, 5};

    quicksort(list, 0, size-1);

    for(int i = 0; i < 5; ++i) {
        if (list[i] != checklist[i]) {
            printf("%s[FAILED]%s test quick sort\n", KRED, KNRM);
            return;
        } 
    }

    printf("%s[PASSED]%s test quick sort\n", KGRN, KNRM);
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
    test_quicksort();

    return EXIT_SUCCESS;
}