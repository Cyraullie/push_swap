/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:30:03 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/27 14:36:25 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top(t_pile *pile, int value, char stack_name)
{
	int		position;
	int		size;
	t_list	**stack;

	if (stack_name == 'a')
		stack = &(pile->pile_a);
	else
		stack = &(pile->pile_b);
	position = find_position(*stack, value);
	size = ft_lstsize(*stack);
	if (position == -1)
		return ;
	if (position <= size / 2)
		move_top_util(position, pile, stack_name, "r");
	else
	{
		position = size - position;
		move_top_util(position, pile, stack_name, "rr");
	}
}

void	move_min_to_b(t_pile *pile)
{
	int		min_value;
	t_list	*current;

	min_value = *(int *)pile->pile_a->content;
	current = pile->pile_a->next;
	while (current != NULL)
	{
		if (*(int *)current->content < min_value)
			min_value = *(int *)current->content;
		current = current->next;
	}
	move_to_top(pile, min_value, 'a');
	handle_format(pile, "pb");
}

int	find_position(t_list *list, int target)
{
	int		position;
	t_list	*current;

	position = 0;
	current = list;
	while (current != NULL)
	{
		if (*(int *)current->content == target)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

void	find_min_max(t_list *pile, int *min, int *max)
{
	*min = INT_MAX;
	*max = INT_MIN;
	while (pile)
	{
		if (*(int *)pile->content < *min)
			*min = *(int *)pile->content;
		if (*(int *)pile->content > *max)
			*max = *(int *)pile->content;
		pile = pile->next;
	}
}
