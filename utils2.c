/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:18:58 by cgoldens          #+#    #+#             */
/*   Updated: 2024/12/06 16:19:32 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**arg_split(char **ag)
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
