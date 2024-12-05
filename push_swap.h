/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:56:21 by cgoldens          #+#    #+#             */
/*   Updated: 2024/12/05 16:15:17 by cgoldens         ###   ########.fr       */
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
}	t_pile;

//main
void	handle_format(t_pile *pile, char *f);

//sort
void	sort_three(t_pile *piles, t_list *lst);

//sort_utils
/*void	move_min_to_b(t_pile *pile);
void	move_to_top(t_pile *pile, int value, char stack_name);
int		find_position(t_list *list, int target);
void	find_min_max(t_list *pile, int *min, int *max);
void	move_top_util(int position, t_pile *pile, char stack_name, char *base);
int		pile_size(t_list *pile);
int		get_max_bits(int max_num);*/

//utils
void	free_list(t_list **lst);
void	free_args(char **args);
int		free_all(int argc, char **args, t_pile *pile);

//check
int		check_double(t_list *a);
int		is_number(const char *str);
int		is_int(const char *str);
int		is_sorted(t_list *a);
int		check_errors(int argc, char **argv, t_pile *pile, int *e);

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

//TODO a trier
void	add_index(t_list *lst);
void	debug_pile(t_pile *pile);
int	isrevsorted(t_list *lst);
int		check_sorting(t_list **list);
int		ft_error(void);
char 	**arg_split(char **ag);
int		count_arg(char **ag);
void	quick_sort(t_pile *pile);
void quick_sort_b(t_pile *piles, int size);
void quick_sort_a(t_pile *piles, int size);

#endif