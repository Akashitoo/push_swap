/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:27:23 by abalasub          #+#    #+#             */
/*   Updated: 2024/03/21 23:22:59 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_pile **s1)
{
	t_pile	*current;
	t_pile	*previous;

	if (!*s1 || stack_size(*s1) < 2)
	{
		ft_printf("Impossible !\n");
		return ;
	}
	current = *s1;
	previous = NULL;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	if (previous != NULL)
		previous->next = NULL;
	current->next = *s1;
	*s1 = current;
}

void	reverse_rotate_a(t_pile **s1)
{
	reverse_rotate(s1);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_pile **s1)
{
	reverse_rotate(s1);
	ft_printf("rrb\n");
}

void	reverse_rotate_both(t_pile **s1, t_pile **s2)
{
	reverse_rotate(s1);
	reverse_rotate(s2);
	ft_printf("rrr\n");
}
