/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:41 by cgoldens          #+#    #+#             */
/*   Updated: 2024/12/06 16:19:05 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_replace(t_list *lst, int n, int to)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->index == -1 && *(int *)tmp->content == n)
			break ;
		tmp = tmp->next;
	}
	tmp->index = to;
}

int	min_nbr(t_list *lst)
{
	t_list		*tmp;
	long int	min;

	min = LONG_MAX;
	tmp = lst;
	while (tmp)
	{
		if (tmp->index == -1 && *(int *)tmp->content < min)
			min = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

void	add_index(t_list *lst)
{
	int	len;
	int	min;
	int	i;

	i = 0;
	len = ft_lstsize(lst);
	while (i < len)
	{
		min = min_nbr(lst);
		index_replace(lst, min, i);
		i++;
	}
}

int	isrevsorted(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->next != NULL)
		{
			if (*(int *)tmp->content < *(int *)tmp->next->content)
				return (0);
			tmp = tmp->next;
		}
		else
			break ;
	}
	return (1);
}
