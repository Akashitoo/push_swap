/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_smaller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:19:24 by abalasub          #+#    #+#             */
/*   Updated: 2024/03/25 22:19:38 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*find_max(t_pile *stack)
{
	t_pile	*current;
	t_pile	*max;

	current = stack;
	max = current;
	while (current != NULL)
	{
		if (max->number < current->number)
			max = current;
		current = current->next;
	}
	return (max);
}

t_pile	*first_smaller(int nb, t_pile *s2)
{
	t_pile	*current;

	current = s2;
	while (current != NULL)
	{
		if (current->number < nb)
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_pile	*find_closest_smaller(int nb, t_pile *s2)
{
	t_pile	*current;
	t_pile	*closest_smaller;

	current = first_smaller(nb, s2);
	closest_smaller = current;
	while (current != NULL)
	{
		if (current->number < nb)
		{
			if (current->number > closest_smaller->number)
				closest_smaller = current;
		}
		current = current->next;
	}
	return (closest_smaller);
}
