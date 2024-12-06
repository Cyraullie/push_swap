/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:30:03 by cgoldens          #+#    #+#             */
/*   Updated: 2024/12/06 16:22:11 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_max(t_list *pile, int *min, int *max)
{
	*min = INT_MAX;
	*max = INT_MIN;
	while (pile)
	{
		if (*(int *)pile->content < *min)
			*min = *(int *)pile->content;
		if (*(int *)pile->content > *max)
			*max = *(int *)pile->content;
		pile = pile->next;
	}
}

int	find_min(t_list *pile)
{
	int		min;
	t_list	*current;

	min = INT_MAX;
	current = pile;
	while (current)
	{
		if (*(int *)current->content < min)
			min = *(int *)current->content;
		current = current->next;
	}
	return (min);
}

int	find_max(t_list *pile)
{
	int		max;
	t_list	*current;

	max = INT_MIN;
	current = pile;
	while (current)
	{
		if (*(int *)current->content > max)
			max = *(int *)current->content;
		current = current->next;
	}
	return (max);
}

void	check_b(t_pile *piles)
{
	int	i;

	i = 0;
	if (!isrevsorted(piles->pile_b))
	{
		if (ft_lstsize(piles->pile_b) == 2)
			handle_format(piles, "sb");
		else
			rev_sort_three_b(piles);
	}
	i = ft_lstsize(piles->pile_b);
	while (i != 0)
	{
		handle_format(piles, "pa");
		i--;
	}
}

void	check_a(t_pile *piles)
{
	if (!is_sorted(piles->pile_a))
	{
		if (ft_lstsize(piles->pile_a) == 2)
			handle_format(piles, "sa");
		else
			quick_sort_a(piles, ft_lstsize(piles->pile_a));
	}
}
