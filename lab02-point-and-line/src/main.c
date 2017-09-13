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


typedef struct point {
	double x;
	double y;
} Point;

typedef struct line {
	Point p1;
	Point p2;
} Line;

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
	if(argc != 5) {
		return EXIT_FAILURE;
	}

	Line line = {0};
	
	int res = sscanf(argv[1], "%lf", &line.p1.x);	
	res += sscanf(argv[2], "%lf", &line.p1.y);	
	res += sscanf(argv[3], "%lf", &line.p2.x);	
	res += sscanf(argv[4], "%lf", &line.p2.y);	

	if(res != 4) {
		return EXIT_FAILURE;
	} 

	(void)printf("line %g/%g-%g/%g\n", line.p1.x, line.p1.y, line.p2.x, line.p2.y);
	
	return EXIT_SUCCESS;
}
