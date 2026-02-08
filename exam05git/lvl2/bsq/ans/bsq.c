#include "bsq.h"

int loadElements(FILE *file, t_elements *elements)
{
	int ret = fscanf(file, "%d %c %c %c", &(elements->n_lines), &(elements->empty), &(elements->obstacle), &(elements->full));

	if (ret != 4)
		return (-1);
	if (elements->n_lines <= 0 ||
			elements->empty == elements->obstacle ||
			elements->empty == elements->full ||
			elements->obstacle == elements->full ||
			elements->empty < 32 || elements->empty > 126 ||
			elements->obstacle < 32 || elements->obstacle > 126 ||
			elements->full < 32 || elements->full > 126)
		return (-1);
	return (0);
}

void free_map(char **grid)
{
	int i = 0;
	if (grid)
	{
		while(grid[i] != NULL)
		{
			if (grid[i])
				free(grid[i]);
			i++;
		}
		free(grid);
	}
}

char *ft_substr(char *line, int start, int len)
{
	char *str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	int i = 0;
	int j = 0;
	while(line[i])
	{
		if (i >= start && j < len)
		{
			str[j] = line[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

int element_control(char **grid, char empty, char obst)
{
	int i = 0;
	while (grid[i])
	{
		int j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] != empty && grid[i][j] != obst)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int loadMap(FILE *file, t_map *map, t_elements *elements)
{
	map->height = elements->n_lines;
	map->grid = (char **)malloc((map->height + 1) * (sizeof(char*)));
	if (!map->grid)
		return (-1);
	map->grid[map->height] = NULL;

	for (int k = 0; k <= map->height; k++)
		map->grid[k] = NULL;
	char *line = NULL;
	size_t len = 0;

	ssize_t read = getline(&line, &len, file);
	for (int i = 0; i < map->height; i++)
	{
		ssize_t read = getline(&line, &len, file);
		if (read == -1)
		{
			free(line);
			free_map(map->grid);
			return (-1);
		}

		if (read > 0 && line[read - 1] == '\n')
			read--;
		
		map->grid[i] = ft_substr(line, 0, read);
		if (!map->grid[i])
		{
			free(line);
			free_map(map->grid);
			return (-1);
		}

		if (i == 0)
			map->width = read;
		else
		{
			if (map->width != read)
			{
				free(line);
				free_map(map->grid);
				return (-1);
			}
		}
	}

	if (map->width <= 0 || map->height <= 0)
	{
		free(line);
		free_map(map->grid);
		return (-1);
	}
	if (element_control(map->grid, elements->empty, elements->obstacle) == -1)
	{
		free(line);
		free_map(map->grid);
		return (-1);
	}
	free(line);
	return (0);
}

int find_min(int n1, int n2, int n3)
{
	int min = n1;
	if (n2 < min)
		min = n2;
	if (n3 < min)
		min = n3;
	return (min);
}

void find_big_square(t_map *map, t_square *square, t_elements *elements)
{
	int **matrix = (int **)malloc(map->height * sizeof(int *));
	for (int i = 0; i < map->height; i++)
		matrix[i] = (int *)calloc(map->width, sizeof(int));
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width; j++)
		{
			if (map->grid[i][j] == elements->obstacle)
				matrix[i][j] = 0;
			else if (i == 0 || j == 0)
				matrix[i][j] = 1;
			else
			{
				int min = find_min(matrix[i - 1][j], matrix[i - 1][j - 1], matrix[i][j -1]);
				matrix[i][j] = min + 1;
			}
			if (matrix[i][j] > square->size)
			{
				square->size = matrix[i][j];
				square->i = i - matrix[i][j] + 1;
				square->j = j - matrix[i][j] + 1;
			}
		}
	}
	for (int i = 0; i < map->height; i++)
		free(matrix[i]);
	free(matrix);
}

void print_filled_square(t_map *map, t_square *square, t_elements *elements)
{
	for (int i = square->i; i < square->i + square->size; i++)
	{
		for (int j = square->j; j < square->j + square->size; j++)
		{
			map->grid[i][j] = elements->full;
		}
	}
	for (int i = 0; i < map->height; i++)
		fprintf(stdout, "%s\n", map->grid[i]);
}

int execute_bsq(FILE *file)
{
	t_elements elements;
	if (loadElements(file, &elements) == -1)
		return (-1);
	
	t_map map;
	if(loadMap(file, &map, &elements) == -1)
		return (-1);

	t_square square;
	square.size = 0;
	square.i = 0;
	square.j = 0;

	find_big_square(&map, &square, &elements);
	print_filled_square(&map, &square, &elements);
	free_map(map.grid);
	return (0);
}

int convert_file_pointer(char *name)
{
	FILE *file = fopen(name, "r");
	if (!file)
		return (-1);
	int ret = execute_bsq(file);
	fclose(file);
	return (ret);
}