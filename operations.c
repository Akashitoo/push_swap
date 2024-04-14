/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:24:00 by abalasub          #+#    #+#             */
/*   Updated: 2024/03/21 23:24:05 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_pile **s1, t_pile **s2)
{
	t_pile	*tmp;

	if (!s1 || !s2 || !*s2)
	{
		ft_printf("Impossible !\n");
		return ;
	}
	tmp = *s2;
	*s2 = tmp->next;
	tmp->next = *s1;
	*s1 = tmp;
}

void	push_to_a(t_pile **s1, t_pile **s2)
{
	push(s1, s2);
	ft_printf("pa\n");
}

void	push_to_b(t_pile **s1, t_pile **s2)
{
	push(s1, s2);
	ft_printf("pb\n");
}
