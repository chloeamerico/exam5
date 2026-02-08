#include "bsq.h"

int parse_header(char *line, t_map **map)
{

	// !!! strlen interdit
	int len = strlen(line);

	if (line[len - 1] != '\n' || len < 5)
		return -1;
	(*map)->empty = line[len - 4];
	(*map)->obstacle = line[len - 3];
	(*map)->full = line[len - 2];

	if (is_printable((*map)->empty) != 0 || is_printable((*map)->obstacle) != 0 || is_printable((*map)->full) != 0)
		return -1;
	if ((*map)->empty == (*map)->obstacle || (*map)->empty == (*map)->full || (*map)->full == (*map)->obstacle)
		return -1;
	
	line[len - 4] = '\0';
	long num = 0;
	int i = 0;
	while (line[i])
	{
		char c = line[i];
		if (c < '0' || c > '9')
			return -1;
		num = num * 10 + (c - '0');
		if (num > INT_MAX)
			return -1;
		i++;
	}
	if (num <= 0)
		return -1;
	(*map)->declared_lines = num;
	return 0;
}

int parse_map_lines(t_map **map)
{
	int i = 0;
	int j = 0;

	while ((*map)->lines[0][j])
		j++;
	(*map)->line_length = j;

	while (i < (*map)->declared_lines)
	{
		j = 0;
		while ((*map)->lines[i][j])
		{
			if ((*map)->lines[i][j] != (*map)->empty && (*map)->lines[i][j] != (*map)->obstacle)
				return -1;
			j++;
		}
		if (j != (*map)->line_length)
			return -1;
		i++;
	}
	return 0;
}


int process_file(char *filename, t_map **map)
{
	FILE *file;

	if (filename == 0)
		file = stdin;
	else
	{
		file = fopen(filename, "r");
		if (!file)
			return -1;
	}

	size_t len = 0;
	char *line = 0;
	getline(&line, &len, file);
	if (parse_header(line, map) != 0)
		return(free(line), -1);
	(*map)->lines = calloc((*map)->declared_lines, sizeof(*(*map)->lines)); // !
	if (!(*map)->lines)
		return -1;
	
	int i = 0;
	int n_read;
	while ((n_read = getline(&line, &len, file)) != -1)
	{
		if (line[n_read -1] == '\n')
			line[--n_read] = '\0';
		else
			return -1;
		// !!! strdup interdit !
		(*map)->lines[i] = strdup(line);
		i++;
	}

	if (i != (*map)->declared_lines)
		return -1;
	if (parse_map_lines(map) != 0)
		return -1;
	return 0;

}
