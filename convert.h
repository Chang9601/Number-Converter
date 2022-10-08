#ifndef CONVERT_H
#define CONVERT_H
#include <stdbool.h>

bool isNum(const char *arg);
bool isInBound(int num);
int cntDigit(int num, int base);
void reverseNum(char *num);
char *convert(const char *baseFrom, const char *baseTo, const char *num);

#endif
