#pragma once

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_elements
{
	int n_line;
	char empty;
	char obs;
	char fill;
}	t_elements;

typedef struct s_map
{
	char **array;
	int width;
	int height;
}	t_map;

typedef struct s_square
{
	int size;
	int i;
	int j;
}	t_square;

int ft_strlen(char *s);
void print_array(char **array);
char *ft_strdup(char *src);
void free_array(char **array);
int init_struct(char *av ,t_map *map, t_elements *elements);
int bsq(t_map *map, t_elements *elem);