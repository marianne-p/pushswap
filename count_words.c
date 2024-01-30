#include "push_swap.h"

int	count_words(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

