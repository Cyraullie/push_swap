/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:56:21 by cgoldens          #+#    #+#             */
/*   Updated: 2024/12/06 16:37:40 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_pile
{
	t_list	*pile_a;
	t_list	*pile_b;
	int		max;
	int		mid;
}	t_pile;

typedef struct s_push
{
	int	next;
	int	max;
	int	mid;
	int	flag;
}	t_push;

//main
void	handle_format(t_pile *pile, char *f);

//free
void	free_list(t_list **lst);
void	free_args(char **args);
int		free_all(int argc, char **args, t_pile *pile);

//check
int		check_double(t_list *a);
int		is_number(const char *str);
int		is_int(const char *str);
int		is_sorted(t_list *a);
int		check_errors(int argc, char **argv, t_pile *pile, int *e);
int		check_sorting(t_list *list);

//operation
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

//utils
void	add_index(t_list *lst);
int		isrevsorted(t_list *lst);
char	**arg_split(char **ag);
int		ft_error(void);
int		count_arg(char **ag);

//sort
void	sort_three_a(t_pile *piles);
void	rev_sort_three_b(t_pile *piles);
void	quick_sort_a(t_pile *piles, int size);
void	small_sort(t_pile *pile);
void	quick_sort(t_pile *piles, int count);

//sort_utils
void	check_a(t_pile *piles);
void	check_b(t_pile *piles);
int		find_pivot(t_list *lst);
t_list	*find_min_lst(t_list *stack);
t_list	*find_max_lst(t_list *stack);
void	quick_a(t_pile *piles, t_push *push);
void	quick_b(t_pile *piles, t_push *push);
int		check_sorting_a(t_list *lst, int count);
void	begin_sorting(t_pile *piles, t_push *push, int count);
void	find_next(t_pile *piles, t_push *push);

#endif