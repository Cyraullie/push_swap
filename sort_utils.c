/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:30:03 by cgoldens          #+#    #+#             */
/*   Updated: 2024/12/06 16:35:54 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_pivot(t_list *lst)
{
	int		max;
	t_list	*tmp;

	max = INT_MIN;
	tmp = lst;
	while (tmp != NULL)
	{
		if (max < tmp->index)
			max = tmp->index;
		tmp = tmp->next;
	}
	if (ft_lstsize(lst) == 4)
		max++;
	return ((max) / 2);
}

t_list	*find_min_lst(t_list *stack)
{
	t_list	*min;
	t_list	*tmp;

	min = stack;
	tmp = stack;
	while (tmp)
	{
		if (*(int *)tmp->content < *(int *)min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_list	*find_max_lst(t_list *stack)
{
	t_list	*max;
	t_list	*tmp;

	max = stack;
	tmp = stack;
	while (tmp)
	{
		if (*(int *)tmp->content > *(int *)max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}
