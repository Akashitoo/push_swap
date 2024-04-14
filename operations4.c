/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:01:00 by abalasub          #+#    #+#             */
/*   Updated: 2024/04/04 16:31:50 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile *lst)
{
	int	tmp;

	if (!lst || !lst->next)
	{
		ft_printf("Impossible !\n");
		return ;
	}
	tmp = lst->number;
	lst->number = lst->next->number;
	lst->next->number = tmp;
}

void	swap_a(t_pile *lst)
{
	swap(lst);
	ft_printf("sa\n");
}

void	swap_b(t_pile *lst)
{
	swap(lst);
	ft_printf("sb\n");
}

void	swap_both(t_pile *s1, t_pile *s2)
{
	swap(s1);
	swap(s2);
	ft_printf("ss\n");
}
