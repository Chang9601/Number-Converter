#include <stdio.h>
#include <stdlib.h>
#include "convert.h"
/* TO-DO
 * 1. Handle exception when number arg is not a number.
 * 2. Handle exception when number arg does not fit the source base.
 *
 *
 *
 *
 *
 *
 *
 *
 */

int main(int argc, char *argv[])
{
	if (argc != 4) 
	{
		printf("Usage: convert\n");
		exit(EXIT_FAILURE);
	}

	char *base_from = argv[1]; 
	char *base_to = argv[2];
	char *number = argv[3];
		
	if (!is_number(base_from) || !is_number(base_to))
	{
		printf("All the arguments must be number\n");
		exit(EXIT_FAILURE);
	}

	char *converted_number = convert(base_from, base_to, number);
	printf("%s in base %s converted to %s int base %s", number, base_from, converted_number, base_to);

	free(converted_number);
	return EXIT_SUCCESS;
}
