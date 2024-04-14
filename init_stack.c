/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:04:03 by abalasub          #+#    #+#             */
/*   Updated: 2024/03/28 14:58:34 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*ft_newlst(int nb)
{
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	if (!new)
		return (NULL);
	new->number = nb;
	new->next = NULL;
	return (new);
}

void	ft_lst_addfront(t_pile **lst, t_pile *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_pile	*create_stack(int argc, char **argv)
{
	int		i;
	int		t;
	t_pile	*stack;

	i = argc - 2;
	stack = ft_newlst(ft_atoi(argv[argc - 1]));
	while (i > 0)
	{
		t = ft_atoi(argv[i]);
		ft_lst_addfront(&stack, ft_newlst(t));
		i--;
	}
	return (stack);
}

t_pile	*create_stack_quote(char **array)
{
	int		i;
	t_pile	*stack;

	if (!array[0])
	{
		return (NULL);
	}
	i = len_array(array) - 2;
	stack = ft_newlst(ft_atoi(array[i + 1]));
	while (i >= 0)
	{
		ft_lst_addfront(&stack, ft_newlst(ft_atoi(array[i])));
		i--;
	}
	return (stack);
}

void	free_stack(t_pile **stack)
{
	t_pile	*current;
	t_pile	*next;

	if (!*stack)
		return ;
	current = *stack;
	next = current->next;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
