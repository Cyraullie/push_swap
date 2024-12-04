/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:06:53 by cgoldens          #+#    #+#             */
/*   Updated: 2024/12/04 16:42:18 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//TODO enlever le sort 5 parce que pas le droit
//TODO opti le tri parce que 69 pour 6 nombre = caca
//TODO peut etre faire avec des index ? genre on donne un index a chaque nombre et on trie l'index.
//TODO ARG=$(python3 generator.py 100 1 1000); ./push_swap $ARG | wc -l
void sort_three(t_pile *piles)
{
	t_list	*last;

	if (check_sorting(&piles->pile_a))
		return ;
	last = ft_lstlast(piles->pile_a);
	if (isrevsorted(piles))
	{
		handle_format(piles, "sa");
		handle_format(piles, "rra");
	}
	else if (*(int *)piles->pile_a->content < *(int *)last->content
		&& *(int *)piles->pile_a->next->content < *(int *)last->content)
		handle_format(piles, "sa");
	else if (*(int *)piles->pile_a->content > *(int *)last->content
		&& *(int *)piles->pile_a->next->content < *(int *)last->content)
		handle_format(piles, "ra");
	else if (*(int *)piles->pile_a->content < *(int *)last->content
		&& *(int *)piles->pile_a->next->content > *(int *)last->content)
	{
		handle_format(piles, "sa");
		handle_format(piles, "ra");
	}
	else if (*(int *)piles->pile_a->content > *(int *)last->content
		&& *(int *)piles->pile_a->next->content > *(int *)last->content)
		handle_format(piles, "rra");
}

//TODO use quick sort with median pivot :)
