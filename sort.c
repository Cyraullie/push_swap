/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:06:53 by cgoldens          #+#    #+#             */
/*   Updated: 2024/12/06 16:30:34 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_pile *piles)
{
	t_list	*last;

	if (check_sorting(piles->pile_a))
		return ;
	last = ft_lstlast(piles->pile_a);
	if (isrevsorted(piles->pile_a))
	{
		handle_format(piles, "sa");
		handle_format(piles, "rra");
	}
	else if (*(int *)piles->pile_a->content < *(int *)last->content
		&& *(int *)piles->pile_a->next->content < *(int *)last->content)
		handle_format(piles, "sa");
	else if (*(int *)piles->pile_a->content > *(int *)last->content
		&& *(int *)piles->pile_a->next->content < *(int *)last->content)
		handle_format(piles, "ra");
	else if (*(int *)piles->pile_a->content < *(int *)last->content
		&& *(int *)piles->pile_a->next->content > *(int *)last->content)
	{
		handle_format(piles, "sa");
		handle_format(piles, "ra");
	}
	else if (*(int *)piles->pile_a->content > *(int *)last->content
		&& *(int *)piles->pile_a->next->content > *(int *)last->content)
		handle_format(piles, "rra");
}

void	rev_sort_three_b(t_pile *piles)
{
	t_list	*last;

	if (isrevsorted(piles->pile_b))
		return ;
	last = ft_lstlast(piles->pile_b);
	if (check_sorting(piles->pile_b))
	{
		handle_format(piles, "sb");
		handle_format(piles, "rrb");
	}
	else if (*(int *)piles->pile_b->content < *(int *)last->content
		&& *(int *)piles->pile_b->next->content < *(int *)last->content)
		handle_format(piles, "rrb");
	else if (*(int *)piles->pile_b->content > *(int *)last->content
		&& *(int *)piles->pile_b->next->content < *(int *)last->content)
	{
		handle_format(piles, "sb");
		handle_format(piles, "rb");
	}
	else if (*(int *)piles->pile_b->content < *(int *)last->content
		&& *(int *)piles->pile_b->next->content > *(int *)last->content)
		handle_format(piles, "rb");
	else if (*(int *)piles->pile_b->content > *(int *)last->content
		&& *(int *)piles->pile_b->next->content > *(int *)last->content)
		handle_format(piles, "sb");
}

void	quick_sort_a(t_pile *piles, int size)
{
	int	pivot;
	int	i;

	if (!piles || size <= 0 || !piles->pile_a)
		return ;
	if (size <= 3)
	{
		sort_three_a(piles);
		return ;
	}
	pivot = find_pivot(piles->pile_a);
	i = -1;
	while (++i < size)
	{
		if (piles->pile_a->index < pivot)
		{
			handle_format(piles, "pb");
		}
		else
			handle_format(piles, "ra");
	}
	check_a(piles);
	check_b(piles);
}

void	small_sort(t_pile *piles)
{
	if (!piles || !piles->pile_a)
		return ;
	quick_sort_a(piles, ft_lstsize(piles->pile_a));
}

void	quick_sort(t_pile *piles, int count)
{
	t_push	push;

	push.next = find_min_lst(piles->pile_a)->index;
	push.max = find_max_lst(piles->pile_a)->index;
	push.mid = push.max / 2 + push.next;
	push.flag = 0;
	begin_sorting(piles, &push, count);
	while (!(check_sorting_a(piles->pile_a, count)))
	{
		if (ft_lstsize(piles->pile_b) == 0)
			quick_b(piles, &push);
		else
			quick_a(piles, &push);
	}
}
