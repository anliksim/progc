#include <stdio.h>
#include <stdlib.h>

static const int start = -100;
static const int stop = 200;
static const int step = 20;

static double to_celsius(int fahrenheit)
{
    return ((fahrenheit - 32) * 5) / 9.0;
}

/**
 * Convert farenheit values from -100 to 200 into celsius.
 *
 * @return exit code 0 if successful
 */
int main()
{
    const int loops = (abs(start) + abs(stop)) / step;
    int current = start;

    (void) printf("F'heit   Celsius\n");
    (void) printf("----------------\n");

    for (int i = 0; i <= loops; i++) {
        (void) printf("%5d     %6.2f\n", current, to_celsius((current)));
        current += 20;
    }
    return EXIT_SUCCESS;
}
