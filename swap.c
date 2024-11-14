/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:24:29 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/13 14:49:55 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{	
	t_list	*first;
	t_list	*second;

	if (*a && (*a)->next)
	{
		first = *a;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*a = second;
	}
}

void	sb(t_list **b)
{
	t_list	*first;
	t_list	*second;

	if (*b && (*b)->next)
	{
		first = *b;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*b = second;
	}
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
}
