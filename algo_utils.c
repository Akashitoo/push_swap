/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:19:20 by abalasub          #+#    #+#             */
/*   Updated: 2024/03/21 23:05:10 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_node(t_pile *stack, t_pile *node)
{
	int		i;
	t_pile	*current;

	i = 0;
	current = stack;
	while (current != node)
	{
		current = current->next;
		i++;
	}
	return (i);
}

int	stack_size(t_pile *stack)
{
	int		i;
	t_pile	*current;

	i = 0;
	current = stack;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int	len_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	is_sort(t_pile *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	free_split(char **quote)
{
	int	i;

	if (!quote || !quote[0])
		return ;
	i = 0;
	while (quote[i])
	{
		free(quote[i]);
		i++;
	}
	free(quote);
}
