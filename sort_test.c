/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:28:00 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/25 16:42:54 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"


// Fonction pour obtenir la taille d'une pile
int	pile_size(t_list *pile)
{
    int size = 0;
    while (pile)
    {
        size++;
        pile = pile->next;
    }
    return size;
}

// Algorithme Radix utilisant handle_format
void radix_sort(t_pile *piles)
{
    int max_num = 0;
    int max_bits = 0;
    int size = pile_size(piles->pile_a);

    // Trouver le nombre maximum pour déterminer le nombre de bits
    t_list *current = piles->pile_a;
    while (current)
    {
        if (*(int*)current->content > max_num)
            max_num = *(int*)current->content;
        current = current->next;
    }

    // Calculer le nombre de bits nécessaires
    while ((max_num >> max_bits) != 0)
        max_bits++;

    // Algorithme Radix
    for (int i = 0; i < max_bits; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (((*(int*)piles->pile_a->content >> i) & 1) == 1)
                handle_format(piles, "ra");  // Rotation de pile_a
            else
                handle_format(piles, "pb");  // Push vers pile_b
        }

        // Remettre tous les éléments dans pile_a depuis pile_b
        while (piles->pile_b)
            handle_format(piles, "pa");  // Push vers pile_a
    }
}
