/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:59:53 by abalasub          #+#    #+#             */
/*   Updated: 2024/04/11 23:09:20 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_unknown(char *line, int len,
	t_pile **stack_a, t_pile **stack_b)
{
	if (ft_strncmp(line, "rra\n", len) == 0)
		reverse_rotate(stack_a);
	else if (ft_strncmp(line, "rrb\n", len) == 0)
		reverse_rotate(stack_b);
	else if (ft_strncmp(line, "rrr\n", len) == 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	else
		ft_printf("Commande non reconnu\n");
	return ;
}

void	push_swap_rotate(char *line, int len,
	t_pile **stack_a, t_pile **stack_b)
{
	if (ft_strncmp(line, "sa\n", len) == 0)
		swap(*stack_a);
	else if (ft_strncmp(line, "sb\n", len) == 0)
		swap(*stack_b);
	else if (ft_strncmp(line, "ss\n", len) == 0)
	{
		swap(*stack_a);
		swap(*stack_b);
	}
	else if (ft_strncmp(line, "pa\n", len) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp(line, "pb\n", len) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(line, "ra\n", len) == 0)
		rotate(stack_a);
	else if (ft_strncmp(line, "rb\n", len) == 0)
		rotate(stack_b);
	else if (ft_strncmp(line, "rr\n", len) == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else
		reverse_rotate_unknown(line, len, stack_a, stack_b);
	return ;
}

void	read_n_execute(t_pile **stack_a, t_pile **stack_b)
{
	char	*line;
	int		len;

	line = get_next_line(0);
	while (line && line[0] != EOF)
	{
		len = ft_strlen(line);
		push_swap_rotate(line, len, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
}

void	ok_or_ko(t_pile *stack_a, t_pile *stack_b)
{
	if (is_sort(stack_a) && !stack_size(stack_b))
		ft_printf("OK\n");
	else
	{
		ft_printf("KO\n");
		free_stack(&stack_b);
	}
}

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
	read_n_execute(&stack_a, &stack_b);
	ok_or_ko(stack_a, stack_b);
	free_stack(&stack_a);
	free_split(quote);
}
