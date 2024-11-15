/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:30:03 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/15 15:48:30 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_list *lst)
{
	t_list	*tmp;
	int		min;
	int		pos;
	int		i;

	tmp = lst;
	min = *(int *)tmp->content;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (*(int *)tmp->content < min)
		{
			min = *(int *)tmp->content;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	move_min_to_b(t_pile *pile)
{
	int	min_pos;
	int	size;

	size = ft_lstsize(pile->pile_a);
	min_pos = get_min_index(pile->pile_a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			handle_format(pile, "ra");
	}
	else
	{
		while (min_pos++ < size)
			handle_format(pile, "rra");
	}
	handle_format(pile, "pb");
}
