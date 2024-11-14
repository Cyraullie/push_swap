/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:56:04 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/14 15:17:03 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_format(t_pile *pile, char *f)
{
	if (ft_strcmp(f, "sa") == 0)
		sa(&(pile->pile_a));
	if (ft_strcmp(f, "sb") == 0)
		sb(&(pile->pile_b));
	if (ft_strcmp(f, "ss") == 0)
		ss(&(pile->pile_a), &(pile->pile_b));
	if (ft_strcmp(f, "pa") == 0)
		pa(&(pile->pile_a), &(pile->pile_b));
	if (ft_strcmp(f, "pb") == 0)
		pb(&(pile->pile_a), &(pile->pile_b));
	if (ft_strcmp(f, "ra") == 0)
		ra(&(pile->pile_a));
	if (ft_strcmp(f, "rb") == 0)
		rb(&(pile->pile_b));
	if (ft_strcmp(f, "rr") == 0)
		rr(&(pile->pile_a), &(pile->pile_b));
	if (ft_strcmp(f, "rra") == 0)
		rra(&(pile->pile_a));
	if (ft_strcmp(f, "rrb") == 0)
		rrb(&(pile->pile_b));
	if (ft_strcmp(f, "rrr") == 0)
		rrr(&(pile->pile_a), &(pile->pile_b));
	ft_printf("%s\n", f);
}

void	free_list(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	init(t_pile *pile, char **arg, int l)
{
	t_list	*tmp;
	int		*value;
	int		i;

	pile->pile_b = NULL;
	pile->pile_a = NULL;
	i = 0;
	while (i < l)
	{
		value = malloc(sizeof(int));
		if (!value)
			return ;
		*value = ft_atoi(arg[i + 1]);
		tmp = ft_lstnew(value);
		ft_lstadd_back(&(pile->pile_a), tmp);
		i++;
	}
}

void	choose_sort(t_pile *pile)
{
	int	size;

	size = ft_lstsize(pile->pile_a);
	if (size <= 3)
		sort_three(pile);
	else if (size <= 5)
		sort_five(pile);
}

int	main(int argc, char **argv)
{
	t_pile	*pile;

	if (argc > 1)
	{
		if (check_errors(argc, argv))
			handle_errors("Error\n");
		pile = malloc(sizeof(t_pile));
		if (!pile)
			handle_errors("Error\n");
		init(pile, argv, argc - 1);
		if (check_double(pile->pile_a))
		{
			free_list(&(pile->pile_a));
			free_list(&(pile->pile_b));
			handle_errors("Error\n");
		}
		if (is_sorted(pile->pile_a))
			return (0);
		choose_sort(pile);
		ft_printf("\na\n-\n");
		check_pile(pile->pile_a);
		ft_printf("\nb\n-\n");
		check_pile(pile->pile_b);
		free_list(&(pile->pile_a));
		free_list(&(pile->pile_b));
		free(pile);
	}
	return (0);
}
