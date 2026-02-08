#include "bsq.h"

int main(int ac, char **av)
{
	(void)ac;
	t_map *map = calloc(1, sizeof(t_map));
	if (!map)
		return -1;
	if (process_file(av[1], &map) == 0)
	{
		t_square best = solve_bsq_dp(map);
		apply_square(map, best);
		print_map(map);
	}
	else
		return(fprintf(stderr, "Error with the map\n"), -1);
	return 0;
}