/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:30:03 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/20 11:15:43 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *pile)
{
	int		min_value;
	t_list	*tmp;

	tmp = pile->next;
	min_value = *(int *)pile->content;
	while (tmp)
	{
		if (*(int *)tmp->content < min_value)
		{
			min_value = *(int *)tmp->content;
		}
		tmp = tmp->next;
	}
	return (min_value);
}

int	find_largest(t_list *list)
{
	int		largest;
	t_list	*current;

	if (!list)
		return (INT_MIN);
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
	int		value;

	if (!list)
		return (0);
	current = list;
	while (current != NULL)
	{
		value = *(int *)current->content;
		if (value >= min && value <= max)
			return (1);
		current = current->next;
	}
	return (0);
}

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
