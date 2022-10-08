#include <stdio.h>
#include <stdlib.h>
#include "convert.h"
/* TO-DO
 * 1. Handle exception when number arg is not a number. (e.g. 1@#@4)
 * 2. Handle exception when number arg does not fit in the source base. (e.g. source base = 2, num = 93)
 */

int main(int argc, char *argv[])
{
	if (argc != 4) 
	{
		printf("Usage: convert\n");
		exit(EXIT_FAILURE);
	}

	char *baseFrom = argv[1]; 
	char *baseTo = argv[2];
	char *num = argv[3];
		
	if (!isNum(baseFrom) || !isNum(baseTo))
	{
		printf("All the arguments must be number\n");
		exit(EXIT_FAILURE);
	}

	char *convertedNum = convert(baseFrom, baseTo, num);
	printf("%s in base %s converted to %s int base %s", num, baseFrom, convertedNum, baseTo);

	free(convertedNum);
	return EXIT_SUCCESS;
}
