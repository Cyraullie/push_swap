/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:56:04 by cgoldens          #+#    #+#             */
/*   Updated: 2024/12/04 14:38:25 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_format(t_pile *pile, char *f)
{
	ft_printf("%s\n", f);
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
		*value = ft_atoi(arg[i]);
		tmp = ft_lstnew(value);
		tmp->index = -1;
		ft_lstadd_back(&(pile->pile_a), tmp);
		i++;
	}
	add_index(pile->pile_a);
}

void	choose_sort(t_pile *pile)
{
	int	len;

	len = ft_lstsize(pile->pile_a);
	/*if (check_sorting(&pile->stack_a))
		return ;*/
		
	if (len == 2)
	{
		if (*(int *)pile->pile_a->content > *(int *)pile->pile_a->next->content)
			handle_format(pile, "sa");
	}
	/*else if (len == 3)
		sort_3nbr(pile);
	else if (len == 5)
		sort_5nbr(pile);
	else
		quick_sort(pile, ft_lstsize(pile->pile_a));*/
}

int	main(int argc, char **argv)
{
	t_pile	*pile;
	char	**args;
	int		arg_count;

	arg_count = argc - 1;
	if (argc < 1)
		return (1);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			write(STDERR_FILENO, "Error\n", 6);
		arg_count = 0;
		while (args[arg_count])
			arg_count++;
	}
	else
		args = argv + 1;
	pile = malloc(sizeof(t_pile));
	if (!pile)
		write(STDERR_FILENO, "Error\n", 6);
	init(pile, args, arg_count);
	if (!check_errors(arg_count, args, pile))
		choose_sort(pile);
	debug_pile(pile);
	return (free_all(argc, args, pile));
}
