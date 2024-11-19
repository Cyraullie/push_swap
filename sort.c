/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:06:53 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/19 17:37:20 by cgoldens         ###   ########.fr       */
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

// Trouve la position d'un élément dans la pile (comme précédemment)
int find_position(t_list *list, int target)
{
    int position = 0;
    t_list *current = list;
    
    while (current != NULL)
    {
        if (*(int *)current->content == target)
            return position;
        current = current->next;
        position++;
    }
    return -1;
}

// Déplace un élément de la pile en haut de la pile
void move_to_top(t_pile *pile, int value, char stack_name)
{
    int position;
    int size;
    t_list **stack = (stack_name == 'a') ? &(pile->pile_a) : &(pile->pile_b);

    position = find_position(*stack, value);
    size = ft_lstsize(*stack);

    if (position == -1)
        return;

    // Effectuer les rotations
    if (position <= size / 2)
    {
        while (position-- > 0)
            handle_format(pile, (stack_name == 'a') ? "ra" : "rb");
    }
    else
    {
        position = size - position;
        while (position-- > 0)
            handle_format(pile, (stack_name == 'a') ? "rra" : "rrb");
    }
}

// Trouve et déplace le plus petit élément de pile_a vers pile_b
void move_min_to_b(t_pile *pile)
{
    int min_value = *(int *)pile->pile_a->content;
    t_list *current = pile->pile_a->next;
    
    // Trouver le plus petit élément dans pile_a
    while (current != NULL)
    {
        if (*(int *)current->content < min_value)
            min_value = *(int *)current->content;
        current = current->next;
    }

    // Déplacer le plus petit élément en haut et le transférer dans pile_b
    move_to_top(pile, min_value, 'a');
    handle_format(pile, "pb");
}

// Trie un petit nombre d'éléments (jusqu'à 5)
void sort_small(t_pile *pile)
{
    if (ft_lstsize(pile->pile_a) == 2)
    {
        if (*(int *)pile->pile_a->content > *(int *)pile->pile_a->next->content)
            handle_format(pile, "sa");
    }
    else if (ft_lstsize(pile->pile_a) == 3)
    {
        sort_three(pile);
    }
    else if (ft_lstsize(pile->pile_a) <= 5)
    {
        sort_five(pile);
    }
}

// Fonction de tri principale pour les grandes piles
void sort_large(t_pile *pile)
{    
    // Déplacer les plus petits éléments dans pile_b
    while (ft_lstsize(pile->pile_a) > 5)
    {
        move_min_to_b(pile);
    }
    
    // Trier les éléments restants dans pile_a
    sort_small(pile);
    
    // Récupérer les éléments de pile_b et les remettre dans pile_a dans l'ordre
    while (pile->pile_b != NULL)
    {
        handle_format(pile, "pa");
    }
}
