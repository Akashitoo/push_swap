/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:10:56 by abalasub          #+#    #+#             */
/*   Updated: 2024/03/25 22:11:11 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_operations2(t_pile **s1, t_pile **s2, t_pile *node)
{
	t_pile	*target;
	int		cost;
	int		a;
	int		b;

	target = find_closest_biggest(node->number, *s2);
	if (!target)
		target = find_min(*s2);
	cost = 0;
	a = index_node(*s1, node);
	b = index_node(*s2, target);
	if (a <= stack_size(*s1) / 2 && b <= stack_size(*s2) / 2)
		return (rmin(a, b) + (rmax(a, b) - rmin(a, b)));
	else if (a > stack_size(*s1) / 2 && b > stack_size(*s2) / 2)
	{
		cost += rmin(stack_size(*s1) - a, stack_size(*s2) - b)
			+ (rmax(stack_size(*s1) - a, stack_size(*s2) - b)
				- rmin(stack_size(*s1) - a, stack_size(*s2) - b));
		return (cost);
	}
	if (a < stack_size(*s1) / 2 && b > stack_size(*s2) / 2)
		return (a + (stack_size(*s2) - b));
	else
		return (b + (stack_size(*s1) - a));
}

int	count_operations(t_pile **s1, t_pile **s2, t_pile *node)
{
	t_pile	*target;
	int		cost;
	int		a;
	int		b;

	target = find_closest_smaller(node->number, *s2);
	if (!target)
		target = find_max(*s2);
	cost = 0;
	a = index_node(*s1, node);
	b = index_node(*s2, target);
	if (a <= stack_size(*s1) / 2 && b <= stack_size(*s2) / 2)
		return (rmin(a, b) + (rmax(a, b) - rmin(a, b)));
	else if (a > stack_size(*s1) / 2 && b > stack_size(*s2) / 2)
	{
		cost += rmin(stack_size(*s1) - a, stack_size(*s2) - b)
			+ (rmax(stack_size(*s1) - a, stack_size(*s2) - b)
				- rmin(stack_size(*s1) - a, stack_size(*s2) - b));
		return (cost);
	}
	if (a < stack_size(*s1) / 2 && b > stack_size(*s2) / 2)
		return (a + (stack_size(*s2) - b));
	else
		return (b + (stack_size(*s1) - a));
}

t_pile	*cheapest_cost2(t_pile **s1, t_pile **s2)
{
	t_pile	*current;
	t_pile	*cheapest_cost;

	cheapest_cost = *s2;
	current = (*s2)->next;
	while (current != NULL)
	{
		if (count_operations2(s2, s1, current)
			< count_operations2(s2, s1, cheapest_cost))
			cheapest_cost = current;
		current = current->next;
	}
	return (cheapest_cost);
}

t_pile	*cheapest_cost(t_pile **s1, t_pile **s2)
{
	t_pile	*current;
	t_pile	*cheapest_cost;

	cheapest_cost = *s1;
	current = (*s1)->next;
	while (current != NULL)
	{
		if (count_operations(s1, s2, current)
			< count_operations(s1, s2, cheapest_cost))
			cheapest_cost = current;
		current = current->next;
	}
	return (cheapest_cost);
}
