/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:30:03 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/19 17:36:08 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_largest(t_list *list)
{
	int	largest;
	t_list	*current;

	if (!list)
		return (INT_MIN); // Retourne une valeur minimale si la liste est vide.

	current = list;
	largest = *(int *)current->content;
	while (current != NULL)
	{
		if (*(int *)current->content > largest)
			largest = *(int *)current->content;
		current = current->next;
	}
	return (largest);
}

int	has_elements_in_chunk(t_list *list, int min, int max)
{
	t_list	*current;

	if (!list)
		return (0);

	current = list;
	while (current != NULL)
	{
		int value = *(int *)current->content;
		if (value >= min && value <= max)
			return (1); // Un élément dans la plage a été trouvé.
		current = current->next;
	}
	return (0); // Aucun élément dans la plage.
}
