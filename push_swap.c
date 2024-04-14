/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:44:55 by abalasub          #+#    #+#             */
/*   Updated: 2024/03/25 23:52:55 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pile	*stack_a;
	t_pile	*stack_b;
	char	**quote;

	quote = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		quote = ft_split(argv[1], ' ');
		if (!check_args(quote, 0))
			return (0);
		stack_a = create_stack_quote(quote);
	}
	else
	{
		if (!check_args(argv, 1))
			return (0);
		stack_a = create_stack(argc, argv);
	}
	stack_b = NULL;
	if (is_sort(stack_a) == 0)
		sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_split(quote);
}
