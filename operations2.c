/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:25:46 by abalasub          #+#    #+#             */
/*   Updated: 2024/04/04 16:20:49 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_pile **s1)
{
	t_pile	*tmp;
	t_pile	*current;

	if (!*s1 || stack_size(*s1) < 2)
	{
		ft_printf("Impossible !\n");
		return ;
	}
	tmp = (*s1)->next;
	(*s1)->next = NULL;
	current = tmp;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = *s1;
	*s1 = tmp;
}

void	rotate_a(t_pile **s1)
{
	rotate(s1);
	ft_printf("ra\n");
}

void	rotate_b(t_pile **s1)
{
	rotate(s1);
	ft_printf("rb\n");
}

void	rotate_both(t_pile **s1, t_pile **s2)
{
	rotate(s1);
	rotate(s2);
	ft_printf("rr\n");
}
