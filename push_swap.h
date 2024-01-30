#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <stdbool.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct t_num
{
	int				n;
	size_t			i;
	bool			above;
	struct t_num	*smaller_target;
	struct t_num	*bigger_target;
	size_t			cost;
	size_t			total_cost;
	bool			cheapest;
	struct t_num	*next;
} t_n;

typedef struct t_src
{
	int		*num;
	int		*sort;
	int		size;
	t_n		*head;
} t_src;

void	push_swap(int *src, int i);
void	quick_sort(int	*arr, int low, int high);
int	is_sorted(int *num, size_t size);
int	is_list_sorted(t_n *head);
t_n	*find_last_node(t_n *head);
/*create stack*/
unsigned long long	dec_to_bi(unsigned int	decimal_num);
t_n	*create_linkli(t_src *a, int i);
int	*radix_sort(int *src, size_t size);
int	count_words(char **s);
/*operations*/
void	pa(t_n **a_head, t_n **b_head);
void	pb(t_n **a_head, t_n **b_head);
void	sa(t_n **a_head);
void	sb(t_n **b_head);
void	ss(t_n **a_head, t_n **b_head);
t_n	*find_last(t_n *head);
void	ra(t_n	**a_head);
void	rb(t_n	**b_head);
void	rr(t_n	**a_head, t_n **b_head);
t_n	*find_prev(t_n *head);
void	rrb(t_n **b_head);
void	rra(t_n **a_head);
void	rrr(t_n **a_head, t_n **b_head);
/*other func*/
void	print_t_n(t_n *head);
void	free_stack_a(t_n **a, t_n *temp);
void	free_split_src(int *src, char **split);
void	free_split(char **split);
//void	sort_stack(t_n *a_head);
size_t	find_max(t_n *head);
t_n	*find_max_node(t_n *head);
void	free_stacks(t_n **a_head, t_n **b_head);
void	sort_three_a(t_n **head, size_t max);
void	move_to_top(t_n **a, t_n **b, t_n *cheapest);
/*sort_stack.c*/
void	sort_stack(t_n *a, t_n *b, size_t size);
int	count_nodes(t_n *head, int i);
void	sort_three_b(t_n **head, size_t min);
size_t	find_min(t_n *head, size_t min);
t_n	*find_min_node(t_n *head);
/* from_a_to_b.c */
void	put_nulls(t_n *head, char c);
void	from_a_to_b(t_n **a, t_n **b, t_n *cheapest_a);
void	move_to_b(t_n **a, t_n **b, t_n *cheapest);
void	rotate_separately(t_n **a, t_n **b, t_n *cheapest);
void	count_cost(t_n *head, size_t size);
/*from_b_to_a.c */
void	from_b_to_a(t_n **a, t_n **b, t_n *cheapest_b);
void	move_to_a(t_n **a, t_n **b, t_n *cheapest);
void	rotate_separately_target_a(t_n **a, t_n **b, t_n *cheapest);
/*rotate a*/
void	rotate_a_in_order(t_n **a, t_n *min, size_t size);
int	verify_the_num(char *num, int i, int *src, int size);
void	sort_small_stack(t_n **a_cpy, int size, t_n *a, t_n **b_cpy, t_n *min);

#endif
