#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "convert.h"

bool isNum(const char *arg)
{
	for (int i = 0; arg[i]; i++)
			if (arg[i] < '0' || arg[i] > '9')
					return false;
	return true;
}

bool isInBound(int num)
{
	return num >= 2 && num <= 36;
}

int cntDigit(int num, int base)
{
	int cnt = 0;

	while (num) {
		num /= base;
		cnt++;
	}

	return cnt;
}

void reverseNum(char *num)
{
	for (int i = 0, j = strlen(num) - 1; i < j; i++, j--) {
		char temp = num[i];
		num[i] = num[j];
		num[j] = temp;	
	}
}

char *convert(const char *baseFrom, const char *baseTo, const char *chNum)
{
	const char *bases = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int len = strlen(chNum);
	int from = atoi(baseFrom);
	int to = atoi(baseTo);
	int intNum = 0;
	int base = 1;
	int idx = 0;

	// Convert to decimal	
	for (int i = len - 1; i >= 0; i--, base *= from)
		intNum += (chNum[i] - '0') * base;

	// Convert to target base
	int cnt = cntDigit(intNum, to);
	char *convertedNum = calloc(cnt, sizeof(*convertedNum));

	do {
		convertedNum[idx++] = bases[intNum % to];
		intNum /= to;		
	} while (intNum);

	reverseNum(convertedNum);
	return convertedNum;
}
