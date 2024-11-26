/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:56:04 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/26 15:02:13 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int g_count = 0;

void	handle_format(t_pile *pile, char *f)
{
	ft_printf("%s\n", f);
	if (ft_strcmp(f, "sa") == 0)
	{
		sa(&(pile->pile_a));
		g_count++;
	}
	if (ft_strcmp(f, "sb") == 0)
	{
		sb(&(pile->pile_b));
		g_count++;
	}
	if (ft_strcmp(f, "ss") == 0)
	{
		ss(&(pile->pile_a), &(pile->pile_b));
		g_count++;
	}
	if (ft_strcmp(f, "pa") == 0)
	{
		pa(&(pile->pile_a), &(pile->pile_b));
		g_count++;
	}
	if (ft_strcmp(f, "pb") == 0)
	{
		pb(&(pile->pile_a), &(pile->pile_b));
		g_count++;
	}
	if (ft_strcmp(f, "ra") == 0)
	{
		ra(&(pile->pile_a));
		g_count++;
	}
	if (ft_strcmp(f, "rb") == 0)
	{
		rb(&(pile->pile_b));
		g_count++;
	}
	if (ft_strcmp(f, "rr") == 0)
	{
		rr(&(pile->pile_a), &(pile->pile_b));
		g_count++;
	}
	if (ft_strcmp(f, "rra") == 0)
	{
		rra(&(pile->pile_a));
		g_count++;
	}
	if (ft_strcmp(f, "rrb") == 0)
	{
		rrb(&(pile->pile_b));
		g_count++;
	}
	if (ft_strcmp(f, "rrr") == 0)
	{
		rrr(&(pile->pile_a), &(pile->pile_b));
		g_count++;
	}
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
		*value = ft_atoi(arg[i]);
		tmp = ft_lstnew(value);
		ft_lstadd_back(&(pile->pile_a), tmp);
		i++;
	}
}

void	choose_sort(t_pile *pile)
{
	int	size;

	size = ft_lstsize(pile->pile_a);
	if (size == 2)
	{
		if (*(int *)pile->pile_a->content > *(int *)pile->pile_a->next->content)
			handle_format(pile, "sa");
	}
	else if (size <= 5)
		sort_five(pile);
	else
		radix_sort(pile);

}

void free_args(char **args)
{
	int i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	main(int argc, char **argv)
{
	t_pile	*pile;
	char	**args;
	int		arg_count;

	arg_count = argc - 1;
	if (argc > 1)
	{
		if (argc == 2)
		{
			args = ft_split(argv[1], ' ');
			if (!args)
				handle_errors("Error\n");
			arg_count = 0;
			while (args[arg_count])
				arg_count++;
		}
		else
			args = argv + 1;
		if (check_errors(arg_count, args))
			handle_errors("Error not number or not int\n");
		pile = malloc(sizeof(t_pile));
		if (!pile)
			handle_errors("Error p\n");
		init(pile, args, arg_count);
		if (argc == 2)
			free_args(args);
		if (check_double(pile->pile_a))
		{
			free_list(&(pile->pile_a));
			free_list(&(pile->pile_b));
			handle_errors("Error double\n");
		}
		if (is_sorted(pile->pile_a))
			return (0);
		choose_sort(pile);
		//debug_piles(pile);
		free_list(&(pile->pile_a));
		free_list(&(pile->pile_b));
		free(pile);
		//ft_printf("nombre de mouvement : %d", g_count);
	}
	return (0);
}
