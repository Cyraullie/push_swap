/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:28:00 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/20 16:11:41 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"
/*
// Fonction principale de tri
void quick_sort_push_swap(t_pile *piles)
{
    int size = ft_lstsize(piles->pile_a);
    
    // Effectuer le tri principal
    quick_sort_a(piles, size, 0);
    
    // S'assurer que tous les éléments sont dans la pile A
    while (piles->pile_b)
        handle_format(piles, "pa");
    
    // Ajustement final
    final_adjust(piles);
}

void quick_sort_a(t_pile *piles, int len, int count_r)
{
    if (len <= 1 || is_sorted(piles->pile_a, len, 1))
        return;

    if (len <= 3)
    {
        sort_small_a(piles, len);
        return;
    }

    int pivot = find_median(piles->pile_a, len);
    int pushed = 0;
    int rotated = 0;

    for (int i = 0; i < len; i++)
    {
        if (*(int*)piles->pile_a->content < pivot)
        {
            handle_format(piles, "pb");
            pushed++;
        }
        else
        {
            handle_format(piles, "ra");
            rotated++;
        }
    }

    // Remettre en place les éléments rotés
    while (rotated-- > 0)
        handle_format(piles, "rra");

    quick_sort_a(piles, len - pushed, count_r + pushed);
    quick_sort_b(piles, pushed, 0);
}

void quick_sort_b(t_pile *piles, int len, int count_r)
{
    if (len <= 1)
    {
        while (len--)
            handle_format(piles, "pa");
        return;
    }

    if (len <= 3)
    {
        sort_small_b(piles, len);
        return;
    }

    int pivot = find_median(piles->pile_b, len);
    int pushed = 0;
    int rotated = 0;

    for (int i = 0; i < len; i++)
    {
        if (*(int*)piles->pile_b->content >= pivot)
        {
            handle_format(piles, "pa");
            pushed++;
        }
        else
        {
            handle_format(piles, "rb");
            rotated++;
        }
    }

    // Remettre en place les éléments rotés
    while (rotated-- > 0)
        handle_format(piles, "rrb");

    quick_sort_a(piles, pushed, 0);
    quick_sort_b(piles, len - pushed, count_r + pushed);
}


// Fonction pour trouver la médiane
int find_median(t_list *pile, int len)
{
    int *arr = malloc(sizeof(int) * len);
    int i = 0;
    t_list *tmp = pile;

    while (i < len)
    {
        arr[i++] = *(int*)tmp->content;
        tmp = tmp->next;
    }

    // Tri simple pour trouver la médiane
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int median = arr[len / 2];
    free(arr);
    return median;
}

// Fonction pour trier de petits groupes dans la pile A
void sort_small_a(t_pile *piles, int len)
{
    if (len == 2)
    {
        if (*(int*)piles->pile_a->content > *(int*)piles->pile_a->next->content)
        	handle_format(piles, "sa");
    }
    else if (len == 3)
    {
        int a = *(int*)piles->pile_a->content;
        int b = *(int*)piles->pile_a->next->content;
        int c = *(int*)piles->pile_a->next->next->content;

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
}

// Fonction pour trier de petits groupes dans la pile B
void sort_small_b(t_pile *piles, int len)
{
    int original_len = len;
    while (len--)
        handle_format(piles, "pa");
    sort_small_a(piles, original_len);
}


// Vérifier si une partie de la pile est triée
int is_sorted(t_list *pile, int len, int ascending)
{
    while (--len)
    {
        if (ascending && *(int*)pile->content > *(int*)pile->next->content)
            return 0;
        if (!ascending && *(int*)pile->content < *(int*)pile->next->content)
            return 0;
        pile = pile->next;
    }
    return 1;
}
*/