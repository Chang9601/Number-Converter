#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "convert.h"

const char *bases = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool is_number(const char *arg)
{
	for (int i = 0; arg[i]; i++)
			if (arg[i] < '0' || arg[i] > '9')
					return false;
	return true;
}

bool is_in_bound(int number)
{
	return number >= 2 && number <= 36;
}

int calculate_digit_count(int number, int base)
{
	int digit_count = 0;

	while (number)
	{
		number /= base;
		digit_count++;
	}

	return digit_count;
}

void reverse_number(char *number)
{
	for(int i = 0, j = strlen(number) - 1; i < j; i++, j--)
	{
		char temp = number[i];
		number[i] = number[j];
		number[j] = temp;	
	}
}

char *convert(const char *base_from, const char *base_to, const char *number)
{
	int length = strlen(number);
	int from = atoi(base_from);
	int to = atoi(base_to);
	int num = 0;
	int base = 1;
	int idx = 0;

	// Convert to decimal	
	for (int i = length - 1; i >= 0; i--, base *= from)
		num += (number[i] - '0') * base;

	// Convert to target base
	int digit_count = calculate_digit_count(num, to);
	char *converted_number = calloc(digit_count, sizeof(*converted_number));

	do
	{
		converted_number[idx++] = bases[num % to];
		num /= to;		
	}while (num);

	reverse_number(converted_number);
	return converted_number;
}
