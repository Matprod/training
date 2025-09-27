#include "bsq.h"

static int init_elements(char *av,t_elements *elements, t_map *map)
{
	FILE *file;

	char *line = NULL;
	size_t len = 0;
	size_t read = 0;
	file = fopen(av, "r");
	if(!file)
		return(fprintf(stderr, "ERROR OPENING FILE\n"));
	read = getline(&line, &len, file);
	if (read == -1)
	{
		fprintf(stderr, "Error READING\n");
		return (EXIT_FAILURE);
	}
	int i = 0;
	if (ft_strlen(line) != 8)
	{
		fprintf(stderr, "ERROR WITH ELEMENTS LINE");
		return (EXIT_FAILURE);
	}
	elements->n_line = (int)line[0] -48;
	elements->empty = line[2];
	elements->obs = line[4];
	elements->fill = line[6];
	//printf("n_line = %d\n empty = %c\n obs = %c\n fill = %c\n", elements->n_line, elements->empty, elements->obs, elements->fill);
	if (line[1] != ' ' || line[3] != ' '|| line[5] != ' ')
		return(EXIT_FAILURE);
	if (elements->empty == elements->obs || elements->empty == elements->fill || elements->fill == elements->obs) 
		return(EXIT_FAILURE);
	map->height = elements->n_line;
	read = getline(&line, &len, file);
	map->width = ft_strlen(line);
	fclose(file);
	return (EXIT_SUCCESS);
}
static int init_map(char *av, t_map *map)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;  // getline retourne ssize_t
    int i = 0;

    file = fopen(av, "r");
    if (!file)
        return fprintf(stderr, "ERROR OPENING FILE\n"), EXIT_FAILURE;

    map->array = (char **)malloc((map->height + 1) * sizeof(char *));
    if (!map->array)
        return fprintf(stderr, "ERROR MALLOC\n"), EXIT_FAILURE;

    // skip first line (metadata)
    read = getline(&line, &len, file);
    if (read == -1)
        return fprintf(stderr, "ERROR READING HEADER\n"), EXIT_FAILURE;

    while (i < map->height)
    {
        read = getline(&line, &len, file);
        if (read == -1)
        {
            fprintf(stderr, "ERROR READING LINE %d\n", i);
            fclose(file);
            free(line);
            return EXIT_FAILURE;
        }

        // enlever le \n si présent
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        if (ft_strlen(line)+1 != map->width)
        {
            fprintf(stderr, "ERROR: invalid width at line %d | line = %s\n", i, line);
			fprintf(stderr, "strlen line = %d | map width = %d\n",ft_strlen(line), map->width);
            fclose(file);
            free(line);
            return EXIT_FAILURE;
        }

        map->array[i] = ft_strdup(line);
        if (!map->array[i])
        {
            fclose(file);
            free(line);
            return fprintf(stderr, "ERROR MALLOC\n"), EXIT_FAILURE;
        }
        i++;
    }
    map->array[map->height] = NULL;

    fclose(file);
    free(line);
    return EXIT_SUCCESS;
}




int init_struct(char *av ,t_map *map, t_elements *elements)
{
	if (init_elements(av, elements, map) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	if (init_map(av, map) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	//print_array(map->array);
	//free_array(map->array);
}