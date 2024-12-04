/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:24:07 by cgoldens          #+#    #+#             */
/*   Updated: 2024/12/04 14:28:48 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_pile(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		printf("%d index:%d\n", *(int *)tmp->content, tmp->index);
		tmp = tmp->next;
	}
}
void	debug_pile(t_pile *pile)
{
	printf("\na\n-\n");
	check_pile(pile->pile_a);
	printf("\nb\n-\n");
	check_pile(pile->pile_b);
}