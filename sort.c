/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:06:53 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/15 14:04:27 by cgoldens         ###   ########.fr       */
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
	int	len;

	len = ft_lstsize(pile->pile_a);
	/*while (len--)
	{
		if (pile->pile_a->index == 0 || pile->pile_a->index == 1)
			handle_format(pile, "pb");
		else
			handle_format(pile, "ra");
	}*/
	/*sort_three(pile);
	handle_format(pile, "pa");
	handle_format(pile, "pa");
	if (pile->pile_a->content > pile->pile_a->next->content)
		handle_format(pile, "sa");*/
}

void	check_pile(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		printf("%d _index:%d\n", *(int *)tmp->content, tmp->index);
		tmp = tmp->next;
	}
}

void	debug_piles(t_pile *pile)
{
	printf("\na\n-\n");
	check_pile(pile->pile_a);
	printf("\nb\n-\n");
	check_pile(pile->pile_b);
}
