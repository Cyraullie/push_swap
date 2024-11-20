/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:56:21 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/20 16:23:25 by cgoldens         ###   ########.fr       */
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
int		is_sorted_o(t_list *a);
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

int find_insertion_point(t_list *pile_a, int value);
int find_max(t_list *pile);
void rotate_a_to_position(t_pile *pile);
void push_chunk_to_b(t_pile *pile, int max_value);
void rotate_to_top(t_pile *pile, int index, char stack);
int find_min_position(t_list *pile);
void move_to_top_b(t_pile *pile, int index);
int calculate_score(t_pile *pile, int value, int index);
int find_best_move(t_pile *pile);
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