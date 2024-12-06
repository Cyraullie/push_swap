/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:14:31 by cgoldens          #+#    #+#             */
/*   Updated: 2024/12/06 16:22:33 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
