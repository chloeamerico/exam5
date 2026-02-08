#include "bsq.h"

int	min3(int a, int b, int c)
{
	int min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return min;
}

int is_printable(char c)
{
	if (c == '\n' || c < 32 || c == 127)
		return -1;
	return 0;
}

void print_map(t_map *map)
{
	for(int i = 0; i < map->declared_lines; i++)
		printf("%s\n", map->lines[i]);
}