#include "bsq.h"

int	main(int ac, char **av)
{

	if (ac != 2)
	{
		fprintf(stderr, "ERROR ARGUMENTS\n");
		return (EXIT_FAILURE);
	}
	t_map map;
	t_elements elements;
	if (init_struct(av[1], &map, &elements) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	bsq(&map, &elements);
	return (EXIT_SUCCESS);
}