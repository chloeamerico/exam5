#ifndef BSQ_H
#define BSQ_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/types.h>

typedef struct s_map
{
	char	**lines;
	int		declared_lines;
	int		line_length;

	char	empty;
	char	obstacle;
	char	full;
}			t_map;

typedef struct s_square
{
	int		size;
	int		top_x;
	int		left_y;	
}			t_square;

int main(int ac, char **av);

int process_file(char *filename, t_map **map);
int parse_header(char *line, t_map **map);
int parse_map_lines(t_map **map);

int min3(int a, int b, int c);
int is_printable(char c);
void print_map(t_map *map);

void apply_square(t_map *map, t_square sq); // ? pourquoi on prend un pointer de t_map et une structure t_square
t_square solve_bsq_dp(t_map *map);

#endif