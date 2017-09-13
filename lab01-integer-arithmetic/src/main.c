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

int calc(int rappen, int durch)
{
	(void) printf("- %d x %3.2f\n", rappen/durch, durch/100.0);
	return rappen % durch;
}

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments
 *                  with argv[0] being the command call
 *                  argv[1] the 1st argument, ...
 *                  argv[argc-1] the last argument.
 * @returns Returns the rest of the calculation or
 *                  255 on failure
 */
int main(int argc, char* argv[])
{
	int rappen = 0;
	// begin students to add code for task 4.2
 	if(argc < 2) {
		(void) printf("Missing param\n");
		return 255;
	}

	int res = sscanf(argv[1], "%d", &rappen);

	if(res != 1 || rappen < 0) {
		(void) printf("Bad input\n");
		return 255;
	}

	(void) printf("CHF %g:\n", rappen/100.0);

	int divsLenght = 7;
	int divs[7] = { 500, 200, 100, 50, 20, 10, 5 };
		
	for(int i = 0; i < divsLenght; i++) {
		rappen = calc(rappen, divs[i]);
	}

	if(rappen == 0) {
		(void) printf("Kein Rest\n");
	} else {
		(void) printf("Rest = %g\n", rappen/100.0);
	}

	// end students to add code
	return rappen; // rest = 0 = success
}
