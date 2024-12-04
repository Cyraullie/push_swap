/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:29:41 by cgoldens          #+#    #+#             */
/*   Updated: 2024/12/04 16:17:31 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_replace(t_list *lst, int n, int to)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->index == -1 && *(int *)tmp->content == n)
			break ;
		tmp = tmp->next;
	}
	tmp->index = to;
}

int	min_nbr(t_list *lst)
{
	t_list		*tmp;
	long int	min;

	min = LONG_MAX;
	tmp = lst;
	while (tmp)
	{
		if (tmp->index == -1 && *(int *)tmp->content < min)
			min = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

void	add_index(t_list *lst)
{
	int	len;
	int	min;
	int	i;

	i = 0;
	len = ft_lstsize(lst);
	while (i < len)
	{
		min = min_nbr(lst);
		index_replace(lst, min, i);
		i++;
	}
}

int	isrevsorted(t_pile *pile)
{
	t_list	*tmp;

	tmp = pile->pile_a;
	while (tmp->next)
	{
		if (*(int *)tmp->content < *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

char **arg_split(char **ag)
{
	char	**args;

	args = ft_split(ag[1], ' ');
	if (!args)
	{
		free_args(args);
		ft_error();
		exit (EXIT_FAILURE);
	}
	return (args);
}

int	ft_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (1);
}

int	count_arg(char **ag)
{
	int		arg_count;

	arg_count = 0;
	while (ag[arg_count])
		arg_count++;
	return (arg_count);
}