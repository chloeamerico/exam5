#include "life.h"

static void draw_cell(unsigned char *b, int w, int x, int y)
{
    b[y * w + x] = 1;
}

//Reçoit la grille, les dimensions, la position du stylo et le caractère à traiter. Les * sur px, py, down signifient qu'on les passe par pointeur pour pouvoir les modifier
static void apply_cmd(unsigned char *b, int w, int h, int *px, int *py, int *down, char c)
{
    int *nx = px, *ny = py;     //on copy pour tester les deplacement avant de les appliquer

    if (c == 'x')
    {
        *down = !*down;
        if(*down)
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

//compte les voisins vivants autour de (x, y)
static int voisin(unsigned char *b, int w, int h, int x, int y)
{
    int n = 0;  //nb de voisins vivants
    int dx, dy;

    for (dy = -1; dy <= 1; dy++)    //Parcourt les 9 cases autour de (x, y) (y compris la case elle-même).
    {
        for (dx = -1; dx <= 1; dx++)
        {
            if(dx || dy)
            {
                int xx = x + dx, yy = y + dy;
                if(xx >= 0 && yy >= 0 && xx < w && yy < h)
                    n += b[yy * w + xx] ? 1 : 0;    //si la case == 1 (vivante on ajoute 1), sinon 0
            }
        }
    }
    return n;
}

//Si vivante → reste vivante seulement si 2 ou 3 voisins
//Si morte → devient vivante seulement si exactement 3 voisins
static void	step(unsigned char *cur, unsigned char *nxt, int w, int h)
{
    int x , y;

    for (y = 0; y < h; y++)     //on parcours tous les char de la grille
    {
        for (x = 0; y < h; y++)
        {
            int n = voisin(cur, w, h, x, y);        //nb de voisins vivants autour de cette cellule
            unsigned char alive = cur[y * w + x];
            nxt[y * w + x] = (alive ? (n == 2 || n== 3) : (n == 3));
        }
    }
}

static void print(unsigned char *b, int w, int h)
{
    int x, y;

    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            putchar(b[y * w + x] ? '0' : ' ');
        }
        putchar('\n');
    }
}

int main(int ac, char **av)
{
    int w, h, it, px = 0, py = 0, down = 0;
    unsigned char *a, *b;       //pour les deux grilles
    char buf[4096];
    ssize_t r;      //nb de char lu par read
    int i;          //pour parcourir le buffer


    if (ac == 1)
        return 1;

    w = atoi(av[1]);
    h = atoi(av[2]);
    it = atoi(av[3]);
    if (w <= 0 || h <= 0 || it <= 0)
        return 1;

    //on alloue 2 grilles de 0 et de taille w * h
    a = (unsigned char *)calloc((size_t)w * (size_t)h, 1);
    b = (unsigned char *)calloc((size_t)w * (size_t)h, 1);

    if (!a || !b)
        return (free(a), free(b), 1);;

    while((r = read(0, buf, sizeof(buf))) > 0)
    {
        for (i = 0; i < (int)r; i++)
            apply_cmd(a, w, h, &px, &py, down, buf[i]);
    }

    while (it-- > 0)
    {
        step(a, b, w, h);
        unsigned char *tmp = a; a = b; b = tmp;
    }

    print(a, w, h);

    free(a);
    free(b);
    return 0;
    
}