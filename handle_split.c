#include "push_swap.h"

static int	*create_src_split(int count, char **split, int *s_size, int *src)
{
	int	size;

	size = 0;
	if (!split[0][0])
	       return (NULL);	
	src = (int *)malloc(sizeof(int) * count);
	if (src == NULL)
		return (NULL);
	while (size < count)
	{
		if (!verify_the_num(split[size], 0, src, size))
		{
			write(2, "Error\n", 6);
			free(src);
			return (NULL);
		}
		src[size] = ft_atoi(split[size]);
		size++;
	}
	*s_size = size;
	return (src);
}

int	*handle_split_input(int count, char **split, int *size, char *str)
{
	int	*src = NULL;

	split = ft_split(str, 32);
	if (!(count = count_words(split)))
	{
		free_split(split);
		write(2, "Error\n", 6);
		return (0);
	}
	src = create_src_split(count, split, size, src);
	if (src == NULL)
	{
		free_split(split);
		return (0);
	}
	if (is_sorted(src, *size))
	{
		free_split_src(src, split);
		return (0);
	}
	return (src);
}
