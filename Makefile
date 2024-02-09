# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpihur <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 20:25:50 by mpihur            #+#    #+#              #
#    Updated: 2024/01/29 17:08:29 by mpihur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=	push_swap
SRCS :=	l_main.c \
	verify_the_num.c \
	ps_utility.c \
	quick_sort.c \
	create_linkli.c \
	ps_opers.c \
	ps_rr_opers.c \
	ps_rrr_opers.c \
	sort_stack_v2.c \
	sort_small_stack.c \
	sort_utils.c \
	max_min.c \
	from_a_to_b.c \
	from_a_to_b_move.c \
	from_a_to_b_rotate_separately.c \
	from_b_to_a.c \
	from_b_to_a_move.c \
	from_b_to_a_rotate_separately.c \
	rotate_a_in_order.c \
	count_words.c \
	free.c \
	handle_split.c

OBJS :=	$(SRCS:.c=.o)
CC := cc
CFLAGS := -Wall -Wextra -Werror -g
LDFLAGS := -I. -L./Libft -lft -L./ft_printf -lftprintf

RM := rm -f

LIBFT := ./Libft/libft.a
FT_PRINTF := ./ft_printf/libftprintf.a

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(FT_PRINTF) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

$(LIBFT):
	make -C ./Libft

$(FT_PRINTF):
	make -C ./ft_printf

all:	$(LIBFT) $(FT_PRINTF) $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C ./Libft clean
	$(MAKE) -C ./ft_printf clean

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C ./Libft fclean 
	$(MAKE) -C ./ft_printf fclean

re:	fclean all

.PHONY:	clean fclean re all
