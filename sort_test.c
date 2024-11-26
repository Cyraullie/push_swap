/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:28:00 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/26 16:35:22 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

// Fonction pour obtenir la taille d'une pile
int pile_size(t_list *pile)
{
    int size = 0;
    while (pile)
    {
        size++;
        pile = pile->next;
    }
    return size;
}
/*
// Algorithme Radix utilisant handle_format
void radix_sort(t_pile *piles)
{
    int max_num = 0;
    int max_bits = 0;
    int size = pile_size(piles->pile_a);
    t_list *current;

    // Séparer les négatifs et positifs
    for (int i = 0; i < size; i++)
    {
        if (*(int*)piles->pile_a->content < 0)
            handle_format(piles, "pb");  // Pousse le nombre négatif dans pile_b
        else
            handle_format(piles, "ra");   // Fait tourner pile_a pour garder les positifs
    }

    // Trier les positifs dans pile_a
    current = piles->pile_a;
    while (current)
    {
        if (*(int*)current->content > max_num)
            max_num = *(int*)current->content;
        current = current->next;
    }

    // Calculer le nombre de bits nécessaires
    while ((max_num >> max_bits) != 0)
        max_bits++;

    // Algorithme Radix pour les positifs
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

    // Trier les négatifs dans pile_b
    size = pile_size(piles->pile_b);
    
    for (int i = 0; i < size; i++)
    {
        int value = *(int*)piles->pile_b->content;
        *(int*)piles->pile_b->content = ~value; // Inverser les bits pour trier
        handle_format(piles, "rb");           // Rotation de pile_b
    }

    size = pile_size(piles->pile_b);
    current = piles->pile_b;
    max_num = 0;

    while (current)
    {
        if (*(int*)current->content > max_num)
            max_num = *(int*)current->content;
        current = current->next;
    }

    max_bits = 0;
    
    while ((max_num >> max_bits) != 0)
        max_bits++;
//TODO check le tri des negatifs parce que pour le moment ils ne sont pas au bon endroit
    // Algorithme Radix pour les négatifs (inversé pour ordre croissant)
    for (int i = 0; i < max_bits; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (((*(int*)piles->pile_b->content >> i) & 1) == 1)
                handle_format(piles, "rb");   // Rotation de pile_b
            else
                handle_format(piles, "pa");   // Push vers pile_a pour remettre en ordre
        }
        
        // Remettre tous les éléments dans pile_a depuis pile_b
        while (piles->pile_b)
            handle_format(piles, "pa");   // Push vers pile_a pour remettre en ordre
    }
		debug_piles(piles);

}
*/
//TODO j'ai une boucle infini de merde
// Fonction pour trier plus de 5 éléments
void turk_sort(t_pile *piles)
{
    int size = pile_size(piles->pile_a);

    // Diviser la pile en segments
    int segment_size = size / 2;
    for (int i = 0; i < segment_size; i++)
    {
        // Pousser les éléments inférieurs à la médiane dans pile_b
        if (*(int*)piles->pile_a->content < size / 2)
            handle_format(piles, "pb");
        else
            handle_format(piles, "ra");
    }

    // Trier chaque segment individuellement
    while (pile_size(piles->pile_b) > 0)
    {
        // Trouver le minimum dans pile_b et le pousser dans pile_a
        int min_value = find_min_value(piles->pile_b);
        while (*(int*)piles->pile_b->content != min_value)
            handle_format(piles, "rb");
        handle_format(piles, "pa");
    }

    // Finalement, assurez-vous que pile_a est complètement triée
    while (!is_sorted(piles->pile_a))
        handle_format(piles, "ra");
}

// Fonction auxiliaire pour trouver la valeur minimale dans une pile
int find_min_value(t_list *pile)
{
    int min = *(int*)pile->content;
    while (pile)
    {
        if (*(int*)pile->content < min)
            min = *(int*)pile->content;
        pile = pile->next;
    }
    return min;
}
