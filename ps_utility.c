#include "push_swap.h"

int	is_sorted(int *num, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1)
	{
		if (num[i] > num[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_list_sorted(t_n *head)
{
	while (head->next)
	{
		if (head->i > (head->next)->i)
			return (0);
		head = head->next;
	}
	return (1);
}
/*
unsigned long long	dec_to_bi(unsigned int	decimal_num) 
{
    unsigned long long	i;
    unsigned long long	remainder;
    unsigned long long	binary_num;

    i = 1;
    binary_num = 0;
    while (decimal_num != 0) 
    {
        remainder = decimal_num % 2;
        decimal_num /= 2;
        binary_num += remainder * i;
        i *= 10;
    }
    return (binary_num);
}*/

t_n	*find_last_node(t_n *head)
{
	while (head->next)
		head = head->next;
	return (head);
}
