#include "bsq.h"

t_square solve_bsq_dp(t_map *map)
{
	t_square best;
	best.size = 0, best.top_x = 0, best.left_y = 0;
	int height = map->declared_lines;
	int width = map->line_length;
	int dp[height][width];
	int i = 0;

	while (i < height)
	{
		int j = 0;
		while (j < width)
		{
			if (map->lines[i][j] == map->obstacle)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = 1 + min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
			if (dp[i][j] > best.size)
			{
				best.size = dp[i][j];
				best.top_x = i - dp[i][j] + 1;
				best.left_y = j - dp[i][j] + 1; 
			}
			j++;
		}
		i++;
	}
	return best;
}

void apply_square(t_map *map, t_square sq)
{
	if (sq.size <= 0)
		return;
	int x = 0;
	while (x < sq.size)
	{
		int y = 0;
		while (y < sq.size)
		{
			int xx = sq.top_x + x;
			int yy = sq.left_y + y;
			map->lines[xx][yy] = map->full;
			y++;
		}
		x++;
	}
}