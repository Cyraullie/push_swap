/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:23:00 by cgoldens          #+#    #+#             */
/*   Updated: 2024/12/06 16:23:09 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorting(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp && tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
