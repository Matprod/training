#pragma once
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void	putstr(char *s);
void print_array(char **array);
void	print_board(char **array);
void free_array(char **array);
char **create_array(int width, int height);
int ft_strlen(char *s);
void gol(int width, int height, int iterations);
void	draw_cells(char** array, int i, int j, int draw);
