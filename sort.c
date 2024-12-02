/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:06:53 by cgoldens          #+#    #+#             */
/*   Updated: 2024/12/02 16:25:40 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//TODO enlever le sort 5 parce que pas le droit
//TODO opti le tri parce que 69 pour 6 nombre = caca
//TODO peut etre faire avec des index ? genre on donne un index a chaque nombre et on trie l'index.
//TODO ARG=$(python3 generator.py 100 1 1000); ./push_swap $ARG | wc -l
void sort_three(t_pile *piles)
{
	int	size;
	int	a;
	int	b;
	int	c;

	size = ft_lstsize(piles->pile_a);
	if (size == 2)
	{
		if (*(int *)piles->pile_a->content > *(int *)piles->pile_a->next->content)
			handle_format(piles, "sa");
		return ;
	}

	a = *(int *)piles->pile_a->content;
	b = *(int *)piles->pile_a->next->content;
	c = *(int *)piles->pile_a->next->next->content;

	if (a > b && b < c && a < c)
		handle_format(piles, "sa");
	else if (a > b && b > c)
	{
		handle_format(piles, "sa");
		handle_format(piles, "rra");
	}
	else if (a > b && b < c && a > c)
		handle_format(piles, "ra");
	else if (a < b && b > c && a < c)
	{
		handle_format(piles, "sa");
		handle_format(piles, "ra");
	}
	else if (a < b && b > c && a > c)
		handle_format(piles, "rra");
}
