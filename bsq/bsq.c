#include "bsq.h"

static bool can_place_square(t_map *map, int i, int j, int size, char obstacle)
{
	int y = i;
	while (y < i + size)
	{
		int x = j;
		while (x < j + size)
		{
			if (y >= map->height || x >= map->width)
				return false;
			if (map->array[y][x] == obstacle)
				return false;
			x++;
		}
		y++;
	}
	return true;
}

t_square *find_square(t_map *map, int i, int j, char obstacle)
{
	int size = 0;
	t_square *elements;

	elements = malloc(sizeof(t_square));
	if (!elements)
		return NULL;

	while (can_place_square(map, i, j, size + 1, obstacle))
		size++;

	elements->size = size; 
	elements->i = i;
	elements->j = j;
	return elements;
}

int bsq(t_map *map, t_elements *elem)
{
	int i = 0;
	int j = 0;
	t_square *new_square;
	t_square *max_square;

	max_square = malloc(sizeof(t_square));
	if (!max_square)
		return (EXIT_FAILURE);
	max_square->size = 0;
	max_square->i = 0;
	max_square->j = 0;

	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->array[i][j] == elem->empty)
			{
				new_square = find_square(map, i, j, elem->obs);
				if (new_square && new_square->size > max_square->size)
				{
					*max_square = *new_square;
				}
				free(new_square);
			}
			j++;
		}
		i++;
	}
	//printf("max square size = %d at (%d,%d)\n", max_square->size, max_square->i, max_square->j);
	print_bsq(map, max_square, elem);
	free(max_square);
	return (EXIT_SUCCESS);
}

void print_bsq(t_map *map, t_square *square, t_elements *elem)
{
	int y = square->i;
	while (y < square->i + square->size)
	{
		int x = square->j;
		while (x < square->j + square->size)
		{
			map->array[y][x] = elem->fill;
			x++;
		}
		y++;
	}

	print_array(map->array);
}