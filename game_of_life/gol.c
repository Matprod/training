
#include "gol.h"

char **create_array(int width, int height)
{
	char **array;
	int i = 0;
	int j = 0;
	array = (char **)calloc(height + 1, sizeof(char *));
	while(i < height)
	{
		j = 0;
		array[i] = (char *)calloc(width+1, sizeof(char));
		while(j < width)
			array[i][j++] = ' ';
		array[i][j] = '\0';
		i++;

	}
	array[i] = NULL;
	return (array);


}

void fill_board(char **array)
{
	char buffer;
	bool draw = false;
	//int flag = 0;
	int i = 0;
	int j = 0;

	while(read(STDIN_FILENO, &buffer, 1) == 1)
	{
		switch (buffer)
		{
		case 'w':
			i--;
			break;
		case 's':
			i++;
			break;
		case 'a':
			j--;
			break;
		case 'd':
			j++;
			break;
		case 'x':
			if (draw == false)
				draw = true;
			else
				draw =false;
			break;
		default:
			//flag = 1;
			break;
		}
		draw_cells(array, i, j, draw);
	}
}
int check_neighbor(char **array, int i, int j, int width, int height)
{
	int count = 0;
	if (i + 1 < height)//haut
	{
		if (array[i + 1][j] && array[i + 1][j] == '0')
		{
			count++;
		}
	}
	if (i + 1 < height && j + 1 < width)//haut droite
	{
		if (array[i + 1][j + 1] && array[i + 1][j + 1] == '0')
		{
			count++;
		}
	}
	if (i + 1 < height && j - 1 >= 0)//haut gauche
	{
		if (array[i + 1][j - 1] && array[i + 1][j - 1] == '0')
		{
			count++;
		}
	}
	if (i - 1 >= 0 && j - 1 >= 0)//bas gauche
	{
		if (array[i - 1][j - 1] && array[i - 1][j - 1] == '0')
		{
			count++;
		}
	}
	if (i - 1 >= 0 && j + 1 < width)//bas droite
	{
		if (array[i - 1][j + 1] && array[i - 1][j + 1] == '0')
		{
			count++;
		}
	}
	if (i - 1 >= 0)//bas
	{
		if (array[i - 1][j] && array[i - 1][j] == '0')
		{
			count++;
		}
	}
	if (j + 1 < width)//droite
	{
		if (array[i][j + 1] && array[i][j + 1] == '0')
		{
			count++;
		}
	}
	if (j - 1 >= 0)//gauche
	{
		if (array[i][j - 1] && array[i][j - 1] == '0')
		{
			count++;
		}

	}
	return (count);
}

char	**one_iteration(char **array, int width, int height)
{
	int i = 0;
	int j = 0;
	char **new_board;
	new_board = create_array(width, height);
	while(array[i])
	{
		while(array[i][j])
		{
			if (array[i][j] == ' ')
			{
				if (check_neighbor(array, i , j, width, height) == 3)
				{
					new_board[i][j] = '0';
				}
			}
			else if (array[i][j] == '0')
			{
				if (check_neighbor(array, i , j, width, height) == 3 || check_neighbor(array, i , j, width, height) == 2)
				{
					new_board[i][j] = '0';
				}
			}
			//printf("print iteration of j = %d\n i = %d\n", j, i);
			//print_board(new_board);
			j++;
		}
		j = 0;
		i++;
	}
	return (new_board);
}
void simulation(char **array, int width, int height, int iterations)
{
	char **new_board;
	printf("BASE PATTERN\n");
	print_board(array);
	if (iterations == 0)
	{

		return ;
	}
	while(iterations--)
	{
		printf("_______________________________________________\n");
		new_board = one_iteration(array, width, height);
		array = new_board;
		print_board(new_board);
		usleep(200000);
		printf("_______________________________________________\n");
	}
	printf("FINAL PRINT\n");
	print_board(new_board);
	free_array(new_board);
}

void	draw_cells(char** array, int i, int j, int draw)
{
	if (draw == true && i >= 0 && j >= 0)
	{
		if (array[i])
		{
			if (array[i][j])
			{
				array[i][j] = '0';
			}
		}
	}
}


void gol(int width, int height, int iterations)
{
	char **array;
	array = create_array(width, height);
	fill_board(array);
	simulation(array, width, height, iterations);
	//print_board(array);
	free_array(array);
}
int	main(int argc, char **argv)
{
	if (argc != 4)
		return (putstr("Error with with the number of arguments\n"), 1);
		
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	int iteration = atoi(argv[3]);

	if (width <= 0 || height <= 0 || iteration < 0)
		return (putstr("Error with value of the arguments\n"), 1);

	gol(width, height, iteration);
	return (0);
}