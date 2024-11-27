/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:53:24 by cgoldens          #+#    #+#             */
/*   Updated: 2024/11/27 14:37:06 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_top_util(int position, t_pile *pile, char stack_name, char *base)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (ft_strlen(base) + 2));
	if (!tmp)
		return ;
	ft_strlcpy(tmp, base, ft_strlen(base) + 1);
	while (position > 0)
	{
		if (stack_name == 'a')
			ft_strlcat(tmp, "a", ft_strlen(base) + 2);
		else
			ft_strlcat(tmp, "b", ft_strlen(base) + 2);
		handle_format(pile, tmp);
		position--;
	}
	free(tmp);
}

int	pile_size(t_list *pile)
{
	int	size;

	size = 0;
	while (pile)
	{
		size++;
		pile = pile->next;
	}
	return (size);
}

int	get_max_bits(int range)
{
	int	max_bits;

	max_bits = 0;
	while (range > 0)
	{
		max_bits++;
		range >>= 1;
	}
	return (max_bits);
}
