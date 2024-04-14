/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:36:51 by abalasub          #+#    #+#             */
/*   Updated: 2024/03/22 20:21:55 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_pile **s1)
{
	if ((*s1)->number == find_max(*s1)->number)
		rotate_a(s1);
	else if ((*s1)->next->number == find_max(*s1)->number)
		reverse_rotate_a(s1);
	if ((*s1)->number > (*s1)->next->number)
		swap_a(*s1);
}

void	sort_five(t_pile **s1, t_pile **s2)
{
	t_pile	*target;
	int		i;

	i = 0;
	while (stack_size(*s1) > 3)
		push_to_b(s2, s1);
	sort_three(s1);
	while (i < 2 && *s2 != NULL)
	{
		target = find_closest_biggest((*s2)->number, *s1);
		if (!target)
			target = find_min(*s1);
		loop_rr_or_rrr(s1, s2, *s2, target);
		loop_rb_or_rrb(s2, *s2);
		loop_ra_or_rra(s1, target);
		push_to_a(s1, s2);
		i++;
	}
	loop_ra_or_rra(s1, find_min(*s1));
}

void	sort_stack(t_pile **s1, t_pile **s2)
{
	if (stack_size(*s1) == 2)
		swap_a(*s1);
	else if (stack_size(*s1) == 3)
		sort_three(s1);
	else
		turk_algo(s1, s2);
}
