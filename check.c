/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:55:11 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/26 14:41:47 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_list *a)
{
	t_list	*current;
	t_list	*checker;

	current = a;
	while (current != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (*(int *)(current->content) == *(int *)(checker->content))
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_number(const char *str)
{
	if (str == NULL)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}

int	is_int(const char *str)
{
	long	num;

	if (str == NULL)
		return (0);
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	is_sorted(t_list *a)
{
	t_list	*current;

	if (!a || !a->next)
		return (1);
	current = a;
	while (current->next)
	{
		if (*(int *)current->content > *(int *)current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	check_errors(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]) || !is_int(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
