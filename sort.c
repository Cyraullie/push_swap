/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:06:53 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/20 11:04:45 by cgoldens         ###   ########.fr       */
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
	move_min_to_b(pile);
	if (size == 5)
		move_min_to_b(pile);
	sort_three(pile);
	handle_format(pile, "pa");
	if (size == 5)
		handle_format(pile, "pa");
}

int	find_position(t_list *list, int target)
{
	int		position;
	t_list	*current;

	position = 0;
	current = list;
	while (current != NULL)
	{
		if (*(int *)current->content == target)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

void	sort_small(t_pile *pile)
{
	if (ft_lstsize(pile->pile_a) == 2)
	{
		if (*(int *)pile->pile_a->content > *(int *)pile->pile_a->next->content)
			handle_format(pile, "sa");
	}
	else if (ft_lstsize(pile->pile_a) == 3)
	{
		sort_three(pile);
	}
	else if (ft_lstsize(pile->pile_a) <= 5)
	{
		sort_five(pile);
	}
}

void	sort_large(t_pile *pile)
{
	while (ft_lstsize(pile->pile_a) > 5)
	{
		move_min_to_b(pile);
	}
	sort_small(pile);
	while (pile->pile_b != NULL)
	{
		handle_format(pile, "pa");
	}
}
