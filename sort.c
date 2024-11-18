/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:06:53 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/15 16:40:55 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_pile *pile)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(pile->pile_a))
		return ;
	first = *(int *)pile->pile_a->content;
	second = *(int *)pile->pile_a->next->content;
	third = *(int *)pile->pile_a->next->next->content;
	if (first > second && second > third)
	{
		handle_format(pile, "sa");
		handle_format(pile, "rra");
	}
	else if (first > second && second < third && first < third)
		handle_format(pile, "sa");
	else if (first > third && second < third)
		handle_format(pile, "ra");
	else if (second > third)
		handle_format(pile, "rra");
	else
		handle_format(pile, "ra");
}

void	sort_five(t_pile *pile)
{
	int	size;

	size = ft_lstsize(pile->pile_a);
	if (size <= 3)
	{
		sort_three(pile);
		return ;
	}
	move_min_to_b(pile, size);
	if (size == 5)
		move_min_to_b(pile, size);
	sort_three(pile);
	handle_format(pile, "pa");
	if (size == 5)
		handle_format(pile, "pa");
}

void	sort_large(t_pile *pile)
{
	int size = ft_lstsize(pile->pile_a);
	int chunk_size = size / 5;  // Diviser la pile en 5 chunks
	// Trier par groupes en déplaçant dans pile_b
	while (ft_lstsize(pile->pile_a) > chunk_size)
	{
		move_min_to_b(pile, chunk_size);  // Déplacer les éléments dans pile_b
	}

	// Trier les éléments restants dans pile_a (qui seront moins nombreux)
	sort_three(pile);

	// Déplacer les éléments de pile_b vers pile_a dans l'ordre
	while (pile->pile_b != NULL)
	{
		handle_format(pile, "pa");  // Déplacer un élément de pile_b vers pile_a
	}
}

void	check_pile(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		printf("%d\n", *(int *)tmp->content);
		tmp = tmp->next;
	}
}

void	debug_piles(t_pile *pile)
{
	printf("\na\n-\n");
	check_pile(pile->pile_a);
	printf("\nb\n-\n");
	check_pile(pile->pile_b);
}