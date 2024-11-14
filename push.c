/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:24:43 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/13 14:50:01 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
	}
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
	}
}
