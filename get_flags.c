#include "main.h"
/**
 * get_flags - calculates flags
 * @format: string formatted
 * @i: index of current character
 * Return: int, flags
 */
int get_flags(const char *format, int *i)
{
	const char FLAGS_CH[] = "-+0# ";
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE};
	int flags = 0;
	int curr_i = *i + 1;
	int j;

	while (format[curr_i] != '\0')
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		{
			if (format[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		}
		if (FLAGS_CH[j] == '\0')
			break;
		curr_i++;
	}
	*i = curr_i - 1;
	return (flags);
}
