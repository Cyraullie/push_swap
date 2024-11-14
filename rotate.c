/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:25:00 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/13 14:49:59 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*first;

	if (*a && (*a)->next)
	{
		first = *a;
		*a = first->next;
		first->next = NULL;
		ft_lstadd_back(a, first);
	}
}

void	rb(t_list **b)
{
	t_list	*first;

	if (*b && (*b)->next)
	{
		first = *b;
		*b = first->next;
		first->next = NULL;
		ft_lstadd_back(b, first);
	}
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}
