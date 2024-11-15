/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:06:53 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/15 16:40:55 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_pile *pile)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(pile->pile_a))
		return ;
	first = *(int *)pile->pile_a->content;
	second = *(int *)pile->pile_a->next->content;
	third = *(int *)pile->pile_a->next->next->content;
	if (first > second && second > third)
	{
		handle_format(pile, "sa");
		handle_format(pile, "rra");
	}
	else if (first > second && second < third && first < third)
		handle_format(pile, "sa");
	else if (first > third && second < third)
		handle_format(pile, "ra");
	else if (second > third)
		handle_format(pile, "rra");
	else
		handle_format(pile, "ra");
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

static void partition(t_pile *pile, int low, int high)
{
    int pivot;
    int i;
    int j;

    pivot = *(int *)ft_lstget(pile->pile_a, high)->content; // Choisir le pivot (ici, le dernier élément)
    i = low - 1;
    j = low;

    while (j < high)
    {
        if (*(int *)ft_lstget(pile->pile_a, j)->content <= pivot)
        {
            i++;
            // Échange les éléments à i et j
            ft_lstswap(pile, i, j);
        }
        j++;
    }
    // Mettre le pivot à sa place correcte
    ft_lstswap(pile, i + 1, high);
}

// Fonction recursive quick_sort
void quick_sort(t_pile *pile, int low, int high)
{
    if (low < high)
    {
        int pi = partition(pile, low, high);  // Partitionner la pile

        // Appels récursifs pour les sous-piles à gauche et à droite
        quick_sort(pile, low, pi - 1);
        quick_sort(pile, pi + 1, high);
    }
}

// Wrapper pour quick_sort qui commence avec les indices corrects
void quick_sort_wrapper(t_pile *pile)
{
    int size = ft_lstsize(pile->pile_a);
    if (size > 1)
    {
        quick_sort(pile, 0, size - 1);
    }
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

void	debug_piles(t_pile *pile)
{
	printf("\na\n-\n");
	check_pile(pile->pile_a);
	printf("\nb\n-\n");
	check_pile(pile->pile_b);
}
