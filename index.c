/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:35:42 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/15 14:09:18 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_replace(t_list *lst, int n, int to)
{
	t_list *tmp = lst;

	while (tmp)
	{
		if (tmp->index == -1 && *(int *)tmp->content == n)
		{
			tmp->index = to;
			break;
		}
		tmp = tmp->next;
	}
}

int	min_nbr(t_list *lst)
{
	t_list	*tmp;
	int		min;

	if (!lst)
		return (INT_MAX); // Valeur de retour spéciale si la liste est vide
	tmp = lst;
	min = INT_MAX;
	while (tmp)
	{
			printf("%d\n", *(int *)tmp->content);
		if (tmp->index == -1 && *(int *)tmp->content < min)
			min = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (min);
	/*t_list *tmp = lst;
	long int min = LONG_MAX;

	while (tmp)
	{
		if (tmp->index == -1 && *(int *)tmp->content < min)
		{
			min = *(int *)tmp->content;
		}
		tmp = tmp->next;
	}
	return (int)min;*/
}

void	add_index(t_list *lst)
{
	int len = ft_lstsize(lst);
	int min;
	int i = 0;

	while (i < len)
	{
		min = min_nbr(lst);
		index_replace(lst, min, i);
		i++;
	}
}
