
/**
 * @brief Structure representant la map.
 */
typedef struct s_map
{
    char **lines; // Tableau 2D de char
    int declared_lines; // ? Nombre de ligne déclarée
    int line_length; // Longueur des lignes

    char full; // Char représentant "full"
	char empty; // Char représentant "empty"
	char obstacle; // Char représentant "obstacle"

} t_map;


/**
 * @brief Structure représentant la solution (le plus grand carré réalisable dans la map)
 */
typedef struct s_square
{
    int size; // 
    int top_x;
    int left_y;
} t_square;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>

// /**
//  * @brief Fonction pour initialiser la structure de map à 0
//  * 
//  * @param t_map pointeur de t_map vers la structure de map allouée
//  */
// void init_map(t_map *map)
// {
//     map->lines = 0;

//     map->declared_lines = 0;
//     map->line_length = 0;

//     map->empty = 0;
//     map->full = 0;
//     map->obstacle = 0;
// }

/**
 * @brief Vérifie si un char est printable.
 * 		  On rejette `/n`, < 32 et == 127
 */
int is_printable(char c)
{
    if (c == '\n' || c < 32 || c == 127)
        return -1;
    else
        return 0;
}

/**
 * @brief 
 */
int parse_header(char *line, t_map **map)
{
	// On récupère la length de la ligne du header
    int len = strlen(line);
	// Si le header ne termine pas par `/n` ou que la len est < 5, je retourne une erreur
    if (line[len - 1] != '\n' || len < 5)
        return -1;
	// Je récupère le charactère empty
    (*map)->empty = line[len - 4];
	// Je récupère le charactère obstacle
    (*map)->obstacle = line[len - 3];
	// Je récupère le charactère full
    (*map)->full = line[len - 2];

	// On vérifie que les 3 char rentrés en structure sont printable, sinon on retourne une erreur
    if (is_printable((*map)->empty) != 0 || is_printable((*map)->obstacle) != 0 || is_printable((*map)->full) != 0)
        return -1;

	// On check que les 3 char rentrés eb structure sont bien différents, sinon on retourne une erreur
    if ((*map)->empty == (*map)->obstacle || (*map)->empty == (*map)->full || (*map)->full == (*map)->obstacle)
        return -1;

	// Une fois les 3 chars traités, on termine la ligne par un `/0` pour traité le nombre de ligne (1er token du header)
    line[len - 4] = '\0';
	// On déclare un long pour récupérer le nombre et un int pour itérer
    long num = 0;
    int i = 0;
	// On loop sur toute la ligne (jusqu'au `/0` qu'on a set)
    while (line[i])
    {
		// On vérifie que chaque char est un chiffre, sinon on retourne une erreur
        char c = line[i];
        if (c < '0' || c > '9')
            return -1;
		// On convertit le char digit en digit (atoi à la mano)
        num = num * 10 + (c - '0');
		// On vérifie que num n'excede pas INT_MAX, sinon on retourne une erreur
        if (num > INT_MAX)
            return -1;
        i++;
    }
	// On vérifie que le num est bien positif, sinon on retourne une erreur
    if (num <= 0)
        return -1;
	// On set le nombre de ligne de la structure à num
    (*map)->declared_lines = num;

    return 0; // success
}

/**
 * @brief Vérifie chaque ligne de la map :
 * 		  - toutes les lignes ont la même length
 * 		  -- aucun charactère "full" à ce stade
 */
int parse_map_lines(t_map **map)
{
    int i = 0;
    int j = 0;

	// On loop jusqu'à la dernière colonne de la première ligne
    while ((*map)->lines[0][j])
        j++;
	// On set line_length par rapport à cette première ligne
    (*map)->line_length = j;
	// On loop sur le nombre de lignes
    while (i < (*map)->declared_lines)
    {
		// On reset j (colonne) à 0
        j = 0;
		// On loop sur la ligne
        while ((*map)->lines[i][j])
        {
			// Si le charactère n'est ni empty, ni obstacle, on retourne une erreur
            if ((*map)->lines[i][j] != (*map)->empty && (*map)->lines[i][j] != (*map)->obstacle)
                return -1;
            j++;
        }
		// On vérifie que chaque ligne correspond au nombre de colonne (line_length)
        if (j != (*map)->line_length)
            return -1;
        i++;
    }
    return 0;
}

/**
 * @brief On lit le fichier, ou stdin. On alloue la mémoire et on dup chaque ligne dans la structure t_map.
 * 	  	  On vérifie le nombre de ligne et que la map est bien un rectangle, on vérifie qu'il n'y a aucun char de type "full"
 */
int process_file(char *filename, t_map **map)
{
	// Permet de d'utiliser soit filename avec fopen, soit stdin. Dans les 2 cas, on traîte ensuire file avec getline
    FILE *file;

	// Pas de fichier ? Lis depuis l'entrée standard
    if (filename == 0)
        file = stdin;
    else
    {
        file = fopen(filename, "r"); // Sinon, ouvre le fichier // Si fopen interdit, je peux utiliser open() et read(), mais je dois gérer le buffering moi même 
        if (!file)
            return -1;
    }
	// Je déclare une variable len de type size_t
    size_t len = 0;
	// Je déclare une variable line de type string (char *)
    char *line = NULL;
	// On lit la première ligne du fichier de map (celle du header)
    getline(&line, &len, file);
	// On parse le header, c'est à dire on initialise la structure t_map avec les bonnes valeurs
    if (parse_header(line, map) != 0)
    {
		// Si il y'a une erreur, on free et on retourne une erreur
        free(line);
        return -1;
    }
	// !
	// On alloue la mémoire pour le tableau de notre structure.
	/** // ! (*map)->lines           // char** — pointeur de pointeur
	 ** // ! *(*map)->lines          // char*  — pointeur simple
	 ** // ! sizeof *(*map)->lines   // taille d'un char* = 8 bytes */
	(*map)->lines = calloc((*map)->declared_lines, sizeof *(*map)->lines);
    if (!(*map)->lines)
        return -1;
	// On réinitialise l'itérateur à 0
    int i = 0;
	// On déclare n_read pour stocker le nb de char lu ou -1 si EOF atteint
    int n_read;
	// On loop sur le file jusqu'à EOF (-1)
    while ((n_read = getline(&line, &len, file)) != -1)
    {
		// Si on tombe sur un `/n`, on le remplace par `/0` // ? Pour pouvoir utiliser strdup ?
        if (line[n_read - 1] == '\n')
            line[--n_read] = '\0';
		// Sinon on retourne une erreur parce que // ?  
        else
            return -1;
		// On duplique la ligne lu dans le tableau de char de la structure
        (*map)->lines[i] = strdup(line);
        i++;
    }
	// On vérifie que le nombre de lignes lu correspond au nombre de ligne déclarées, sinon on retourne une erreur
    if (i != (*map)->declared_lines)
        return -1;
	// On parse chaque ligne, en vérifiant les char et les length
    if (parse_map_lines(map) != 0)
        return -1;

    return 0;
}

void print_map(t_map *map)
{
    int i = 0;

    char **str = map->lines;

	// On loop sur le nombre de ligne
    while (i < map->declared_lines)
		printf("%s\n", str[i++]); // On print toute la ligne
}

/**
 * @brief Retourne la plus petite valeur entre 3 int
 */
int min3(int a, int b, int c)
{
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}
/**
 * @brief Coeur de l'algo BSQ, trouve le plus grand carré possible dans la map
 */
t_square solve_bsq_dp(t_map *map)
{
	// On déclare une structure t_square pour stocker la solution qu'on retournera
    t_square best;
	// 
    best.left_y = 0, best.top_x = 0, best.size = 0;
	// On déclare height et width qui correspondent aux dimensions de la map
    int height = map->declared_lines;
    int width = map->line_length;
	// On initialise dp (un tableau de int en 2D) représentant la map
    int dp[height][width];

    int i = 0;
	// On loop sur chaque ligne
    while (i < height)
    {
		// On reset l'itérateur de colonne à 0
        int j = 0;
		// On loop sur toute la ligne (chaque colonne)
        while (j < width)
        {
			// Si on tombe sur un charactère obstacle, on met un 0 dans le tableau dp
            if (map->lines[i][j] == map->obstacle)
                dp[i][j] = 0;
			// Si c'est le coin supérieur gauche, on met un 1 dans le tableau dp
            else if (i == 0 || j == 0)
                dp[i][j] = 1;
			/* Sinon, on calcul 1 + valeur minimum entre :
				- cellule du dessus dp[i - 1][j]
				- cellule de gauche dp[i][j - 1]
				- cellule diagonal gauche dp[i - 1][j - 1]
			 */
			else
                dp[i][j] = 1 + min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
			// On vérifie si la valeur à dp[i][j] est supérieur à size
            if (dp[i][j] > best.size)
            {
				// on set la nouvelle size
                best.size = dp[i][j];
				// on set top_x et left_y pour avoir les coordonnées du point supérieur gauche
                best.top_x = i - dp[i][j] + 1;
                best.left_y = j - dp[i][j] + 1;
            }
            j++;
        }
        i++;
    }
    return best;
}

/**
 * @brief Remplace les char "empty" par des char "full" dans le tableau map->lines de la structure map
 */
void apply_square(t_map *map, t_square sq)
{
	// Si carré est inférieur ou égale à 0, on retourne une erreur
    if (sq.size <= 0)
        return;

    int x = 0;
	// On itère sur le sur la size de carré
    while (x < sq.size)
    {
		// On reset l'itérateur de colonne (ordonnée)
        int y = 0;
		// On itère sur la size du carré
        while (y < sq.size)
        {
			// On commence par le coin supérieur gauche du carré
            int xx = sq.top_x + x;
            int yy = sq.left_y + y;
			// On change pour un charactère "full" 
            map->lines[xx][yy] = map->full;
            y++;
        }
        x++;
    }
}


int main(int ac, char **av)
{
	// On vérifie qu'on a bien 2 av
    if (ac != 2)
		return -1;
	// On alloue de la mémoire pour la structure de map
    t_map *map = calloc(1, sizeof(t_map));
	// On protège le malloc
    if (!map)
        return -1;
	// On initialise les membres de la structure t_map à 0
    // init_map(map);
	// On process le fichier 
    if (process_file(av[1], &map) == 0)
    {
		// On déclare une structure t_square qui prendra la valeur retour de la solution (solve_bsq_dp)
        t_square best = solve_bsq_dp(map);
		// On remplace le tableau 2D de map par des char "full"
        apply_square(map, best);
		// On print la map résolue
        print_map(map);
	}
    else
        fprintf(stderr, "map error\n");
    return 0;
}
