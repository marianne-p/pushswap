#include "push_swap.h"

int	verify_the_num(char *num, int i, int *src, int size)
{
	long long	ret;

	ret = 0;
	if (num == NULL || *num == '\0')
		return (0);
	else
	{
		while (num[i] == ' ' || (num[i] > 8 && num[i] < 14))
			i++;
		if ((num[i] == '-' || num[i] == '+') && (num[i + 1] >= '0' && num[i + 1] <= '9'))
			i++;
		while (num[i])
		{
			if (num[i] >= '0' && num[i] <= '9')
				i++;
			else
				return (0);
		}
	}
	ret = ft_atoi(num);
	if (ret > INT_MAX || ret < INT_MIN)
		return (0);
	i = 0;
	while (i < size)
	{
		if (ret == src[i])
			return (0);
		i++;
	}
	return (1);
}
