/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:25:36 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/13 14:50:17 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a)
{
	t_list	*prev;
	t_list	*last;

	if (*a && (*a)->next)
	{
		prev = NULL;
		last = *a;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *a;
		*a = last;
	}
}

void	rrb(t_list **b)
{
	t_list	*prev;
	t_list	*last;

	if (*b && (*b)->next)
	{
		prev = NULL;
		last = *b;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *b;
		*b = last;
	}
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}
