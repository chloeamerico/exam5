#include "life.h"

static void	draw_cell(unsigned char *b, int w, int x, int y)
{
	b[y * w + x] = 1;
}

static void	apply_cmd(unsigned char *b, int w, int h, int *px, int *py, int *down, char c)
{
	int nx = *px, ny = *py;

	if (c == 'x')
	{
		*down = !*down;
		if (*down)
			draw_cell(b, w, *px, *py);
		return;
	}
	if (c == 'w') ny--;
	else if (c == 's') ny++;
	else if (c == 'a') nx--;
	else if (c == 'd') nx++;
	else return;

	if (nx < 0 || ny < 0 || nx >= w || ny >= h)
		return;
	*px = nx;
	*py = ny;
	if (*down)
		draw_cell(b, w, *px, *py);
}

static int	neighbors(unsigned char *b, int w, int h, int x, int y)
{
	int n = 0;  
	int dx, dy;

	for (dy = -1; dy <= 1; dy++)
		for (dx = -1; dx <= 1; dx++)
			if ((dx || dy))
			{
				int xx = x + dx, yy = y + dy;       //calcule coordonees du voisin
				if (xx >= 0 && yy >= 0 && xx < w && yy < h)
					n += b[yy * w + xx] ? 1 : 0;
			}
	return n;
}

static void	step(unsigned char *cur, unsigned char *nxt, int w, int h)
{
	int x, y;

	for (y = 0; y < h; y++)
		for (x = 0; x < w; x++)
		{
			int n = neighbors(cur, w, h, x, y);
			unsigned char alive = cur[y * w + x];
			nxt[y * w + x] = (alive ? (n == 2 || n == 3) : (n == 3));
		}
}

static void	print_board(unsigned char *b, int w, int h)
{
    int x, y;

	for (y = 0; y < h; y++)
	{
		for (x = 0; x < w; x++)
			putchar(b[y * w + x] ? '0' : ' ');
		putchar('\n');
	}
}

int	main(int ac, char **av)
{
	int w, h, it, px = 0, py = 0, down = 0;
	unsigned char *a, *b;
	char buf[4096];
	ssize_t r;
	int i;

	if (ac != 4)
		return 1;
	w = atoi(av[1]);
	h = atoi(av[2]);
	it = atoi(av[3]);
	if (w <= 0 || h <= 0 || it < 0)
		return 1;

	a = (unsigned char *)calloc((size_t)w * (size_t)h, 1);
	b = (unsigned char *)calloc((size_t)w * (size_t)h, 1);
	if (!a || !b)
		return (free(a), free(b), 1);

	while ((r = read(0, buf, sizeof(buf))) > 0)
		for (i = 0; i < (int)r; i++)
			apply_cmd(a, w, h, &px, &py, &down, buf[i]);

	while (it-- > 0)
	{
		step(a, b, w, h);
		{ unsigned char *tmp = a; a = b; b = tmp; }
	}

	print_board(a, w, h);
	free(a);
	free(b);
	return 0;
}