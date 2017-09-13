/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab implementation
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief  point structure of double coordinates
 */
// begin students to add code for task 4.1

// end students to add code

typedef struct point {
	double x;
	double y;
} Point;

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments,
 *                  with argv[0] being the command call,
 *                  argv[1] the 1st argument,
 *                  argv[argc-1] the last argument.
 * @returns Returns EXIT_SUCCESS (=0) on success.
 */
int main(int argc, char* argv[])
{
	double distance = 0.0;

	// begin students to add code for task 4.1
	
	if(argc != 5) {
		return EXIT_FAILURE;
	}

	Point point1 = {0,0};
	Point point2 = {0,0};
	
	int res = sscanf(argv[1], "%lf", &point1.x);	
	res += sscanf(argv[2], "%lf", &point1.y);	
	res += sscanf(argv[3], "%lf", &point2.x);	
	res += sscanf(argv[4], "%lf", &point2.y);	

	if(res != 4) {
		return EXIT_FAILURE;
	} 

	// calcuate the dx and dy values
	Point d = { point1.x - point2.x, point1.y - point2.y };

	// calculate distance form dx and dy values
	distance = sqrt(d.x*d.x+d.y*d.y);	

	// end students to add code

	(void)printf("distance = %g\n", distance);
	
	return EXIT_SUCCESS;
}
