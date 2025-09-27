#include "bsq.h"

int ft_strlen(char *s)
{
	int i = 0;
	if (!s)
		return (0);
	while(s[i])
	{
		i++;
	}
	return (i);
}

char *ft_strdup(char *src)
{
	int i = 0;
	char *dest;

	while(src[i])
	{
		i++;
	}
	dest = (char*)malloc(i + 1 + sizeof(char));
	i = 0;
	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}

void print_array(char **array)
{
	int i = 0;
	while(array[i])
	{
		fprintf(stdout,"%s\n", array[i]);
		i++;
	}
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