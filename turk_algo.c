/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:46:21 by abalasub          #+#    #+#             */
/*   Updated: 2024/03/24 18:09:16 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b(t_pile **s1, t_pile **s2)
{
	t_pile	*cheapest;
	t_pile	*target;

	cheapest = cheapest_cost(s1, s2);
	target = find_closest_smaller(cheapest->number, *s2);
	if (!target)
		target = find_max(*s2);
	loop_rr_or_rrr(s2, s1, cheapest, target);
	loop_ra_or_rra(s1, cheapest);
	loop_rb_or_rrb(s2, target);
	push_to_b(s2, s1);
}

void	move_b_to_a(t_pile **s1, t_pile **s2)
{
	t_pile	*cheapest;
	t_pile	*target;

	cheapest = cheapest_cost2(s1, s2);
	target = find_closest_biggest(cheapest->number, *s1);
	if (!target)
		target = find_min(*s1);
	loop_rr_or_rrr(s1, s2, cheapest, target);
	loop_rb_or_rrb(s2, cheapest);
	loop_ra_or_rra(s1, target);
	push_to_a(s1, s2);
}

void	turk_algo(t_pile **s1, t_pile **s2)
{
	if (stack_size(*s1) > 5 && !is_sort(*s1))
		push_to_b(s2, s1);
	if (stack_size(*s1) > 5 && !is_sort(*s1))
		push_to_b(s2, s1);
	while (stack_size(*s1) > 5 && !is_sort(*s1))
		move_a_to_b(s1, s2);
	sort_five(s1, s2);
	loop_rb_or_rrb(s2, find_max(*s2));
	while (*s2)
		move_b_to_a(s1, s2);
	loop_ra_or_rra(s1, find_min(*s1));
}
