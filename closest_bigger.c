/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_bigger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:19:02 by abalasub          #+#    #+#             */
/*   Updated: 2024/03/25 22:19:14 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*find_min(t_pile *stack)
{
	t_pile	*current;
	t_pile	*min;

	current = stack;
	min = current;
	while (current != NULL)
	{
		if (min->number > current->number)
			min = current;
		current = current->next;
	}
	return (min);
}

t_pile	*first_biggest(int nb, t_pile *s1)
{
	t_pile	*current;

	current = s1;
	while (current != NULL)
	{
		if (current->number > nb)
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_pile	*find_closest_biggest(int nb, t_pile *s1)
{
	t_pile	*current;
	t_pile	*closest_biggest;

	current = first_biggest(nb, s1);
	closest_biggest = current;
	while (current != NULL)
	{
		if (current->number > nb)
		{
			if (current->number < closest_biggest->number)
				closest_biggest = current;
		}
		current = current->next;
	}
	return (closest_biggest);
}
