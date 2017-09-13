#include <stdio.h>
#include <stdlib.h>

const int start = -100;
const int stop = 200;
const int step = 20;

double toCelsius(int fahrenheit) {
    return ((fahrenheit - 32) * 5) / 9.0;
}

int main() {

    int loops = (abs(start) + abs(stop)) / step;
    int current = start;

    (void) printf("F'heit   Celsius\n");
    (void) printf("----------------\n");
    for (int i = 0; i <= loops; i++) {
        (void) printf("%5d     %6.2f\n", current, toCelsius((current)));
        current += 20;
    }
    return EXIT_SUCCESS;
}