/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:53:24 by cgoldens          #+#    #+#             */
/*   Updated: 2024/12/06 16:37:43 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_a(t_pile *piles, t_push *push)
{
	int	count_b;
	int	i;

	i = -1;
	count_b = ft_lstsize(piles->pile_b);
	while (ft_lstsize(piles->pile_b) && ++i < count_b)
	{
		if (piles->pile_b->index == push->next)
			find_next(piles, push);
		else if (piles->pile_b->index >= push->mid)
		{
			piles->pile_b->flag = push->flag;
			handle_format(piles, "pa");
		}
		else if (piles->pile_b->index < push->mid)
			handle_format(piles, "rb");
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

void	quick_b(t_pile *piles, t_push *push)
{
	int	now_flag;

	now_flag = piles->pile_a->flag;
	if (piles->pile_a->flag != 0)
	{
		while (piles->pile_a->flag == now_flag)
		{
			if (piles->pile_a->index != push->next)
				handle_format(piles, "pb");
			find_next(piles, push);
		}
	}
	else if (piles->pile_a->flag == 0)
	{
		while (piles->pile_a->flag != -1)
		{
			if (piles->pile_a->index != push->next)
				handle_format(piles, "pb");
			find_next(piles, push);
		}
	}
	if (ft_lstsize(piles->pile_b))
		push->max = (find_max_lst(piles->pile_b))->index;
	push->mid = (push->max - push->next) / 2 + push->next;
}

int	check_sorting_a(t_list *lst, int count)
{
	int	len;

	len = ft_lstsize(lst);
	if (len != count)
		return (0);
	if (check_sorting(lst) == 0)
		return (0);
	return (1);
}

void	find_next(t_pile *piles, t_push *push)
{
	if (ft_lstsize(piles->pile_b) > 0 && (piles->pile_b->index == push->next))
		handle_format(piles, "pa");
	else if (piles->pile_a->index == push->next)
	{
		piles->pile_a->flag = -1;
		handle_format(piles, "ra");
		push->next++;
	}
	else if ((ft_lstsize(piles->pile_b)) > 2
		&& ft_lstlast(piles->pile_b)->index == push->next)
		handle_format(piles, "rrb");
	else if (piles->pile_a->next->index == push->next)
		handle_format(piles, "sa");
	else if ((ft_lstsize(piles->pile_a)) > 1
		&& (piles->pile_a->next->index == push->next)
		&& (piles->pile_b->next->index == push->next + 1))
		handle_format(piles, "ss");
	else
		return ;
	find_next(piles, push);
}

void	begin_sorting(t_pile *piles, t_push *push, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if (piles->pile_a->index <= push->mid)
			handle_format(piles, "pb");
		else
		{
			if (ft_lstsize(piles->pile_b) > 1
				&& piles->pile_b->index < (push->mid / 2))
				handle_format(piles, "rr");
			else
				handle_format(piles, "ra");
		}
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}
