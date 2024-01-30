#include "push_swap.h"
#include <string.h>

static void	ft_swap(int *arr, int l, int r)
{
	int	temp;

	temp = arr[l];
	arr[l] = arr[r];
	arr[r] = temp;
}

static int	partition(int *arr, int l, int r, int pivot)
{
	while (l <= r)
	{
		while (arr[l] < pivot)
			l++;
		while (arr[r] > pivot)
			r--;
		if (l <= r)
		{
			ft_swap(arr, l, r);
			l++;
			r--;
		}
	}
	return (l);
}

void	quick_sort(int *arr, int l, int r)
{
	int	pivot;
	int	index;

	if (l >= r)
		return ;
	pivot = arr[(l + r) / 2];
	index = partition(arr, l, r, pivot);
	quick_sort(arr, l, index - 1);
	quick_sort(arr, index, r);
}
/*
#include <stdio.h>

int	main()
{
	int	src[] = {15, 1, -1, 0, 13};
	int	size = sizeof(src) / sizeof(src[0]);
	int	i = 0;

	quick_sort(src, 0, size - 1);
	while (i < size)
		printf("%d ", src[i++]);
}*/
/*static void	quick_sort_recurs(int	*arr, int low, int high, int pivot) 
{ 
        int	i;
        int	j;
        int	temp;

	if (low < high)
	{
		pivot = arr[(low + high) / 2];
		i = low;
		j = high;
		while (i <= j) 
		{
			while (arr[i] < pivot) 
				i++;
			while (arr[j] > pivot) 
				j--;
			if (i <= j) 
			{
				temp = arr[i];
				arr[i++] = arr[j];
				arr[j--] = temp;
			}
		}
	}
	if (low < j) quick_sort(arr, low, j, 0);
	if (i < high) quick_sort(arr, i, high, 0);
}

int	*quick_sort(int	*src, int low, int high, int *sort)
{
	sort = (int *)malloc(sizeof(int) * (high + 1));
	memcpy(sort, src, (high + 1) * sizeof(int));
	quick_sort_recurs(sort, low, high, 0);
	return (sort);
}

#include <stdio.h>

int	main()
{
	int	src[] = {15, 1, -1, 0, 13};
	int	*sort = NULL;
	int	size = sizeof(src) / sizeof(src[0]);
	int	i = 0;

	sort = quick_sort(src, 0, size - 1, sort);
	while (i < size)
		printf("%d ", sort[i++]);
}*/
