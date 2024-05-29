#include <stdio.h>
#include <stdlib.h>
#include "calculations.h"

void get_input(char arr[]);

void get_input(char arr[]) {
    int i;
    int c;

    for (i = 0; ((c = getchar()) != EOF && c != '\n');) {
        if (c != ' ' && c != '\t')
            arr[i++] = c;
    }
    arr[i] = '\0';
}

int main(void) {
    char arr[1000];
    char temp[1000];
    char op;
    int x;
    int y;
    int i;
    int start;
    int end;

    system("clear");
    while (1) {
        printf("Input a 2 number equation: \n");
        get_input(arr);
        if (arr[0] == 'q')
            break;

        for (i = 0, start = 0, end = 0; arr[i] != '\0'; i++) {
            if (i > 0 && (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/')) {
                op = arr[i];
                end = i;
                for (; start < end; start++)
                    temp[start] = arr[start];

                temp[start] = '\0';
                x = atoi(temp);
                printf("X: %i\n", x);
            }
        }

        if (arr[i] == '\0') {
            end = i;
            if (op == '*' || op == '/')
                start++;
            for (i = 0; start < end; start++)
                temp[i++] = arr[start];
            temp[i] = '\0';
            y = atoi(temp);
            printf("Y: %i\n", y);
            switch (op) {
                case '+':
                    printf("Total = %i\n", addition(x, y));
                    break;
                case '-':
                    printf("Total = %i\n", addition(x, y));
                case '*':
                    printf("Total = %i\n", multiplication(x, y));
                default:
                    break;
            }
        }
    }

    return 0;
}