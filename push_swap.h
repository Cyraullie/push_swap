/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:56:21 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/20 11:12:18 by cgoldens         ###   ########.fr       */
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


int		check_double(t_list *a);
int		is_number(const char *str);
int		is_int(const char *str);
int		is_sorted(t_list *a);
int		check_errors(int argc, char **argv);

void	debug_piles(t_pile *pile);
void	add_index(t_list *lst);

void	handle_format(t_pile *pile, char *f);
void	free_list(t_list **lst);

void	sort_three(t_pile *pile);
void	sort_five(t_pile *pile);
void	sort_large(t_pile *pile);
int		isrevsorted(t_pile	*pile);
void	sort_small(t_pile *pile);
int		has_elements_in_chunk(t_list *list, int min, int max);
int		find_largest(t_list *list);
int		find_position(t_list *list, int target);

void    move_top_util(int position, t_pile *pile, char stack_name, char *base);
void	move_min_to_b(t_pile *pile);
void	move_to_top(t_pile *pile, int value, char stack_name);
int		find_min(t_list *pile);

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

#endif