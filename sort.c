/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:06:53 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/20 16:25:54 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_pile *pile)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted_o(pile->pile_a))
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

int	find_position(t_list *list, int target)
{
	int		position;
	t_list	*current;

	position = 0;
	current = list;
	while (current != NULL)
	{
		if (*(int *)current->content == target)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

void	sort_small(t_pile *pile)
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

void sort_large(t_pile *pile)
{
    //int size = ft_lstsize(pile->pile_a);
    int chunk_size = 15; // Ajustez cette valeur selon vos besoins
    int min = find_min(pile->pile_a);
    int max = find_max(pile->pile_a);
    int range = (max - min) / chunk_size;

    // Poussez les éléments vers B en chunks
    for (int i = 1; i <= chunk_size; i++)
    {
        int chunk_max = min + (range * i);
        push_chunk_to_b(pile, chunk_max);
    }

    // Triez les éléments de B vers A
    while (pile->pile_b)
    {
        int best_index = find_best_move(pile);
        move_to_top_b(pile, best_index);
        handle_format(pile, "pa");
        rotate_a_to_position(pile);
    }

    // Rotation finale pour placer le plus petit élément en haut
    int min_pos = find_min_position(pile->pile_a);
    rotate_to_top(pile, min_pos, 'a');
}

void push_chunk_to_b(t_pile *pile, int max_value)
{
    int size = ft_lstsize(pile->pile_a);
    for (int i = 0; i < size; i++)
    {
        if (*(int*)pile->pile_a->content <= max_value)
        {
            handle_format(pile, "pb");
        }
        else
        {
            handle_format(pile, "ra");
        }
    }
}
void rotate_to_top(t_pile *pile, int index, char stack)
{
    int size = (stack == 'a') ? ft_lstsize(pile->pile_a) : ft_lstsize(pile->pile_b);
    
    if (index <= size / 2)
    {
        while (index-- > 0)
            handle_format(pile, (stack == 'a') ? "ra" : "rb");
    }
    else
    {
        while (index++ < size)
            handle_format(pile, (stack == 'a') ? "rra" : "rrb");
    }
}

int find_min_position(t_list *pile)
{
    int min = *(int*)pile->content;
    int min_pos = 0;
    int current_pos = 0;
    t_list *current = pile;

    while (current)
    {
        if (*(int*)current->content < min)
        {
            min = *(int*)current->content;
            min_pos = current_pos;
        }
        current = current->next;
        current_pos++;
    }

    return min_pos;
}


void rotate_a_to_position(t_pile *pile)
{
    int size = ft_lstsize(pile->pile_a);
    int pos = find_insertion_point(pile->pile_a, *(int*)pile->pile_a->content);

    if (pos <= size / 2)
    {
        while (pos--)
            handle_format(pile, "ra");
    }
    else
    {
        while (pos++ < size)
            handle_format(pile, "rra");
    }
}

int find_best_move(t_pile *pile)
{
    t_list *current = pile->pile_b;
    int best_index = 0;
    int best_score = INT_MAX;
    int i = 0;

    while (current)
    {
        int score = calculate_score(pile, *(int*)current->content, i);
        if (score < best_score)
        {
            best_score = score;
            best_index = i;
        }
        current = current->next;
        i++;
    }

    return best_index;
}

int calculate_score(t_pile *pile, int value, int index)
{
    int b_size = ft_lstsize(pile->pile_b);
    //int a_size = ft_lstsize(pile->pile_a);
    int b_score = (index <= b_size / 2) ? index : b_size - index;
    int a_score = find_insertion_point(pile->pile_a, value);
    
    return b_score + a_score;
}

void move_to_top_b(t_pile *pile, int index)
{
    int size = ft_lstsize(pile->pile_b);

    if (index <= size / 2)
    {
        while (index-- > 0)
            handle_format(pile, "rb");
    }
    else
    {
        while (index++ < size)
            handle_format(pile, "rrb");
    }
}

int find_insertion_point(t_list *pile_a, int value)
{
    if (pile_a == NULL || pile_a->next == NULL) 
        return 0;

    t_list *current = pile_a;
    int index = 0;
    int min = *(int*)current->content;
    int max = min;
    int min_pos = 0;

	while (current && current->next)
	{
		int current_value = *(int*)current->content;
		int next_value = *(int*)current->next->content;
		
		if (current_value < min)
		{
			min = current_value;
			min_pos = index;
		}
		if (current_value > max)
			max = current_value;
		
		if ((value > current_value && value < next_value) ||
			(value > max && current_value == max) ||
			(value < min && current_value == min))
			return (index + 1) % ft_lstsize(pile_a);

		current = current->next;
		index++;
	}
	if (value > *(int*)current->content || value < min)
		return 0;

	return min_pos;
}

