/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:40:33 by abalasub          #+#    #+#             */
/*   Updated: 2024/03/28 00:27:51 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	loop_ra_or_rra(t_pile **s1, t_pile *node)
{
	while ((*s1)->number != node->number)
	{
		if (index_node(*s1, node) <= stack_size(*s1) / 2)
			rotate_a(s1);
		else
			reverse_rotate_a(s1);
	}	
}

void	loop_rb_or_rrb(t_pile **s2, t_pile *node)
{
	if (!*s2 || !node)
		return ;
	while ((*s2)->number != node->number)
	{
		if (index_node(*s2, node) <= stack_size(*s2) / 2)
			rotate_b(s2);
		else
			reverse_rotate_b(s2);
	}	
}

void	loop_rr_or_rrr(t_pile **s1, t_pile **s2,
	t_pile *cheapest, t_pile *target)
{
	while ((*s2)->number != cheapest->number
		&& (*s1)->number != target->number)
	{
		if (index_node(*s2, cheapest) <= stack_size(*s2) / 2
			&& index_node(*s1, target) <= stack_size(*s1) / 2)
			rotate_both(s1, s2);
		else if (index_node(*s2, cheapest) > stack_size(*s2) / 2
			&& index_node(*s1, target) > stack_size(*s1) / 2)
			reverse_rotate_both(s1, s2);
		else
			break ;
	}
}
