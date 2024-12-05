/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:06:53 by cgoldens          #+#    #+#             */
/*   Updated: 2024/12/05 16:23:34 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//TODO enlever le sort 5 parce que pas le droit
//TODO opti le tri parce que 69 pour 6 nombre = caca
//TODO peut etre faire avec des index ? genre on donne un index a chaque nombre et on trie l'index.
//TODO ARG=$(python3 generator.py 100 1 1000); ./push_swap $ARG | wc -l
void sort_three(t_pile *piles, t_list *lst)
{
	t_list	*last;

	if (check_sorting(&lst))
		return ;
	last = ft_lstlast(lst);
	if (isrevsorted(lst))
	{
		handle_format(piles, "sa");
		handle_format(piles, "rra");
	}
	else if (*(int *)lst->content < *(int *)last->content
		&& *(int *)lst->next->content < *(int *)last->content)
		handle_format(piles, "sa");
	else if (*(int *)lst->content > *(int *)last->content
		&& *(int *)lst->next->content < *(int *)last->content)
		handle_format(piles, "ra");
	else if (*(int *)lst->content < *(int *)last->content
		&& *(int *)lst->next->content > *(int *)last->content)
	{
		handle_format(piles, "sa");
		handle_format(piles, "ra");
	}
	else if (*(int *)lst->content > *(int *)last->content
		&& *(int *)lst->next->content > *(int *)last->content)
		handle_format(piles, "rra");
}

void rev_sort_three(t_pile *piles, t_list *lst)
{
	t_list *last;

	last = ft_lstlast(lst);
	if (*(int *)lst->content < *(int *)lst->next->content
		&& *(int *)lst->next->content < *(int *)last->content)
	{
		handle_format(piles, "rra");
		handle_format(piles, "sa");
	}
	else if (*(int *)lst->content < *(int *)lst->next->content
				&& *(int *)lst->next->content > *(int *)last->content)
		handle_format(piles, "rra");
	else if (*(int *)lst->content > *(int *)lst->next->content
				&& *(int *)lst->content < *(int *)last->content)
	{
		handle_format(piles, "sa");
		handle_format(piles, "ra");
	}
	else if (*(int *)lst->content > *(int *)last->content
				&& *(int *)lst->next->content < *(int *)last->content)
		handle_format(piles, "ra");
	else if (*(int *)lst->next->content > *(int *)lst->content
				&& *(int *)lst->content > *(int *)last->content)
		handle_format(piles, "sa");
}


//TODO use quick sort with median pivot :)

int	find_pivot(t_list *lst)
{
	int	max;
	t_list	*tmp;
	
	max = INT_MIN;
	tmp = lst;
	while (tmp != NULL)
	{

		if (max < tmp->index)
			max = tmp->index;
		tmp = tmp->next;
	}
	return ((max + 1) / 2);
}

/*void	quick_sort(t_pile *pile)
{
	int	p;
	int	i;
	int size;

	size = ft_lstsize(pile->pile_a);
	if (size <= 3)
    {
        sort_three(pile);
        return ;
    }
	//p = *(int *)pile->pile_a->content;
	p = find_pivot(pile) + *(int *)pile->pile_a->content;
	i = 0;
	while (i < size)
	{
		if (*(int *)pile->pile_a->content < p)
			handle_format(pile, "pb");
		if (*(int *)pile->pile_a->content >= p)
			handle_format(pile, "ra");
		i++;
	}

    quick_sort(pile);*/
    //quick_sort_b(pile);
	//TODO trouver un pivot (la moyenne entre le plus petit et le plus grand)
	/*
	*/
//}
// Tri rapide pour la pile A
void	quick_sort_a(t_pile *piles, int size)
{
	int pivot;
	int pushed;

	if (!piles || size <= 0 || !piles->pile_a)
		return ;
	if (size <= 3)
	{
		sort_three(piles, piles->pile_a);
		return ;
	}

	pivot = find_pivot(piles->pile_a);
	pushed = 0;
	printf("pivot %d\n", pivot);
	for (int i = 0; i < size; i++)
	{
		if (!piles->pile_a)
			break;
		if (piles->pile_a->index < pivot)
		{
			handle_format(piles, "pb");
			pushed++;
		}
		else
			handle_format(piles, "ra");
	}
	if (!is_sorted(piles->pile_a))
		quick_sort_a(piles, size - pushed);
	if (isrevsorted(piles->pile_b))
		quick_sort_b(piles, pushed);
	else
		rev_sort_three(piles, piles->pile_b);

}

// Tri rapide pour la pile B
void	quick_sort_b(t_pile *piles, int size)
{
	int pivot;
	int pushed;

	if (!piles || size <= 0 || !piles->pile_b)
		return ;
	if (size <= 3)
	{
		while (size-- && piles->pile_b)
			handle_format(piles, "pa");
		return ;
	}

	pivot = find_pivot(piles->pile_b);
	pushed = 0;

	for (int i = 0; i < size; i++)
	{
		if (!piles->pile_b)
			break;
		if (piles->pile_b->index >= pivot)
		{
			handle_format(piles, "pa");
			pushed++;
		}
		else
			handle_format(piles, "rb");
	}
	quick_sort_a(piles, pushed);
	quick_sort_b(piles, size - pushed);
}

// Fonction principale de tri
void	quick_sort(t_pile *piles)
{
	if (!piles || !piles->pile_a)
		return ;
	quick_sort_a(piles, ft_lstsize(piles->pile_a));
}
