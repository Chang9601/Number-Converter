#ifndef CONVERT_H
#define CONVERT_H
#include <stdbool.h>

bool is_number(const char *arg);
bool is_in_bound(int number);
int calculate_digit_count(int number, int base);
void reverse_number(char *number);
char *convert(const char *base_from, const char *base_to, const char *number);

#endif
