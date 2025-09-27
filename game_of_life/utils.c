#include "gol.h"

void	putstr(char *s)
{
	int i = 0;
	if (!s) 
		return;
	while(s[i])
	{
		putchar(s[i]);
		i++;
	}
}

void	print_array(char **array)
{	
	int i = 0;
	if (!array) 
		return;
	while(array[i])
	{
		putstr(array[i]);
		putchar('\n');
		i++;
	}

}

int ft_strlen(char *s)
{
	int i = 0;
	if (!s)
		return(0);
	while(s[i])
		i++;
	return (i);
}

void print_board(char **array)
{
	int i = 0;
	int len = 0;

	if (!array || !array[0])
		return;

	// calcul largeur max
	while (array[i])
	{
		int l = ft_strlen(array[i]);
		if (l > len)
			len = l;
		i++;
	}

	// haut
	printf("┌");
	for (int j = 0; j < len; j++)
		printf("─");
	printf("┐\n");

	// corps
	i = 0;
	while (array[i])
	{
		printf("│%s│\n", len, array[i]);
		i++;
	}

	// bas
	printf("└");
	for (int j = 0; j < len; j++)
		printf("─");
	printf("┘\n");
}

void free_array(char **array)
{
	int i = 0;

	while(array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}