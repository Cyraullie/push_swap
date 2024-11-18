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

void	move_min_to_b(t_pile *pile, int chunk_size)
{
	int min_value;
	int i;

	for (i = 0; i < chunk_size; i++)
	{
		min_value = find_min(pile->pile_a);
		while (*(int *)pile->pile_a->content != min_value)
		{
			handle_format(pile, "ra");
		}
		handle_format(pile, "pb");
	}
}

int	find_min(t_list *pile)
{
    int min_value = *(int *)pile->content;
    t_list *tmp = pile->next;

    while (tmp)
    {
        if (*(int *)tmp->content < min_value)
        {
            min_value = *(int *)tmp->content;
        }
        tmp = tmp->next;
    }

    return min_value;
}
