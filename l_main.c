/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpihur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:45:39 by mpihur            #+#    #+#             */
/*   Updated: 2024/01/30 21:03:04 by mpihur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
/*
void	print_t_n(t_n *head)
{
	while (head)
	{
		printf("add = %p, n= %d, i= %ld, above = %d, cost = %ld, cheapest = %d, next = %p\n"
				, head, head->n, head->i, head->above, head->cost, 
				head->cheapest, head->next);
		head = head->next;
	}
}*/

static t_src	*init_t_src(int *src, int size, t_src *a)
{
	a = (t_src *)malloc(sizeof(t_src));
	if (!a)
	{
		ft_printf("Allocation error!\n");
		return (NULL);
	}
	a->num = src;
	a->size = size;
	a->sort = malloc(sizeof(int) * (size + 1));
	if (!a->sort)
		return (NULL);
	ft_memcpy(a->sort, a->num, a->size);
	quick_sort(a->sort, 0, size - 1);
	return (a);
}

void	free_src(t_src	**a)
{
	free ((*a)->num);
	free ((*a)->sort);
	free (*a);
}

void	push_swap(int *src, int size)
{
	t_src	*a;

	//if (size > 524287)
	if (is_sorted(src, size))
	{
		free(src);
		return ;
	}
	a = NULL;
	a = init_t_src(src, size, a);
	if (!a)
		return ;
	if (!is_sorted(a->sort, a->size))
	{
		ft_printf("Sorting algorithm has issue\n");
		return ;
	}
	a->head = create_linkli(a, 0);
	sort_stack(a->head, NULL, 0);
	free_src(&a);
}

static int	*create_src(int argc, char **argv, int *s_size, int *src)
{
	int	size;

	size = 0;
	src = (int *)malloc(sizeof(int) * (argc - 1));
	if (src == NULL)
		return (NULL);
	while (size + 1 < argc)
	{
		if (!verify_the_num(argv[size + 1], 0, src, size))
		{
			write(2, "Error\n", 6);
			free(src);
			return (NULL);
		}
		src[size] = ft_atoi(argv[size + 1]);
		size++;
	}
	*s_size = size;
	return (src);
}

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

int	main(int argc, char **argv)
{
	int	*src;
	int	size;
	char	**split = NULL;
	int	count;

	size = 0;
	count = 0;
	src = NULL;
	if (argc < 2)
	{
		ft_printf("Error! Add arguments.\n");
		return (0);
	}
	if (argc == 2)
		src = handle_split_input(count, split, &size, argv[1]);
	else
		src = create_src(argc, argv, &size, src);
	if (src == NULL)
		return (0);
	push_swap(src, size);
	if (argc == 2)
		free_split(split);
	return (0);
}
