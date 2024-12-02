/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:06:53 by cgoldens          #+#    #+#             */
/*   Updated: 2024/12/02 14:12:19 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//TODO enlever le sort 5 parce que pas le droit
//TODO opti le tri parce que 69 pour 6 nombre = caca
//TODO peut etre faire avec des index ? genre on donne un index a chaque nombre et on trie l'index.
//TODO ARG=$(python3 generator.py 100 1 1000); ./push_swap $ARG | wc -l
void	sort_three(t_pile *piles)
{
	int	a;
	int	b;
	int	c;

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

void	sort_five(t_pile *pile)
{
	int	size;

	size = ft_lstsize(pile->pile_a);
	if (size <= 3)
	{
		sort_three(pile);
		return ;
	}
	move_min_to_b(pile);
	if (size == 5)
		move_min_to_b(pile);
	sort_three(pile);
	handle_format(pile, "pa");
	if (size == 5)
		handle_format(pile, "pa");
}

void	turkish_sort(t_pile *piles)
{
	int	size;
	int	min;
	int	max;
	int	range;
	int	max_bits;

	size = pile_size(piles->pile_a);
	find_min_max(piles->pile_a, &min, &max);
	range = max - min;
	max_bits = get_max_bits(range);
	turk_loop(size, min, max_bits, piles);
	turk_sort(size, min, piles);
}

void	turk_loop(int size, int min, int max_bits, t_pile *piles)
{
	int	bit;
	int	j;
	int	num;

	bit = 0;
	while (bit < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = *(int *)piles->pile_a->content - min;
			if ((num >> bit) & 1)
				handle_format(piles, "ra");
			else
				handle_format(piles, "pb");
			j++;
		}
		while (piles->pile_b)
			handle_format(piles, "pa");
		bit++;
	}
}

void	turk_sort(int size, int min, t_pile *piles)
{
	int	min_pos;
	int	half_size;

	min_pos = find_position(piles->pile_a, min);
	half_size = size / 2;
	if (min_pos <= half_size)
		while (min_pos-- > 0)
			handle_format(piles, "ra");
	else
		while (min_pos++ < size)
			handle_format(piles, "rra");
}
