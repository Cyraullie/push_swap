/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:17:17 by cgoldens          #+#    #+#             */
/*   Updated: 2024/12/06 16:22:19 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
