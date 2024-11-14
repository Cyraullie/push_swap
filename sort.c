/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:06:53 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/14 16:54:42 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_pile *pile)
{
	t_list	*last;

	if (is_sorted(pile->pile_a))
		return ;
	last = ft_lstlast(pile->pile_a);
	if (isrevsorted(pile))
	{
		handle_format(pile, "sa");
		handle_format(pile, "rra");
	}
	else if (*(int *)pile->pile_a->content < *(int *)last->content
		&& *(int *)pile->pile_a->next->content < *(int *)last->content)
		handle_format(pile, "sa");
	else if (*(int *)pile->pile_a->content > *(int *)last->content
		&& *(int *)pile->pile_a->next->content < *(int *)last->content)
		handle_format(pile, "ra");
	else if (*(int *)pile->pile_a->content < *(int *)last->content
		&& *(int *)pile->pile_a->next->content > *(int *)last->content)
	{
		handle_format(pile, "sa");
		handle_format(pile, "ra");
	}
	else if (*(int *)pile->pile_a->content > *(int *)last->content
		&& *(int *)pile->pile_a->next->content > *(int *)last->content)
		handle_format(pile, "rra");
}

void	sort_five(t_pile *pile)
{
	while (ft_lstsize(pile->pile_a) > 3)
		pb(&(pile->pile_a), &(pile->pile_b));
	sort_three(pile);
	if (is_sorted(pile->pile_b))
		rb(&(pile->pile_b));
	while (pile->pile_b)
		pa(&(pile->pile_a), &(pile->pile_b));
}

void	check_pile(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		printf("%d\n", *(int *)tmp->content);
		tmp = tmp->next;
	}
}
