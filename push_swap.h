/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:56:21 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/25 17:12:34 by cgoldens         ###   ########.fr       */
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
int		isrevsorted(t_pile	*pile);
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

void radix_sort(t_pile *piles);
int pile_size(t_list *pile);
int find_min_index(t_list *pile);
/*
void quick_sort_push_swap(t_pile *piles);
//void quick_sort_a(t_pile *piles, int len, int count_r);
//void quick_sort_b(t_pile *piles, int len, int count_r);
//int find_median(t_list *pile, int len);
void sort_small_a(t_pile *piles, int len);
void sort_small_b(t_pile *piles, int len);
int is_sorted(t_list *pile, int len, int ascending);
int find_min_position(t_list *pile);
void quick_sort_recursive(t_pile *piles, int is_a);
void merge_piles(t_pile *piles);
void merge_into_a(t_pile *piles, int size_b);
void merge_into_b(t_pile *piles, int size_a);
void sort_small(t_pile *piles, int size);
*/
#endif