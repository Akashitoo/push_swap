/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:12:46 by abalasub          #+#    #+#             */
/*   Updated: 2024/04/02 14:22:06 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line.h"
# include <stdlib.h>
# define EOF -1

typedef struct f_list
{
	int				number;
	struct f_list	*next;
}			t_pile;

int		len_array(char **array);
int		index_node(t_pile *stack, t_pile *node);
int		stack_size(t_pile *stack);
int		count_operations(t_pile **s1, t_pile **s2, t_pile *node);
int		stack_size(t_pile *stack);
int		is_sort(t_pile *stack);
int		count_operations(t_pile **s1, t_pile **s2, t_pile *node);
int		count_operations2(t_pile **s1, t_pile **s2, t_pile *node);
int		check_args(char **array, int start);
int		rmin(int a, int b);
int		rmax(int a, int b);

void	sort_five(t_pile **s1, t_pile **s2);
void	sort_three(t_pile **s1);
void	swap(t_pile *lst);
void	swap_a(t_pile *lst);
void	swap_b(t_pile *lst);
void	swap_both(t_pile *s1, t_pile *s2);
void	push(t_pile **s1, t_pile **s2);
void	push_to_a(t_pile **s1, t_pile **s2);
void	push_to_b(t_pile **s1, t_pile **s2);
void	rotate(t_pile **s1);
void	rotate_a(t_pile **s1);
void	rotate_b(t_pile **s1);
void	rotate_both(t_pile **s1, t_pile **s2);
void	reverse_rotate(t_pile **s1);
void	reverse_rotate_a(t_pile **s1);
void	reverse_rotate_b(t_pile **s1);
void	reverse_rotate_both(t_pile **s1, t_pile **s2);
void	ft_lst_addfront(t_pile **lst, t_pile *new);
void	free_stack(t_pile **stack);
void	loop_ra_or_rra(t_pile **s1, t_pile *node);
void	loop_rb_or_rrb(t_pile **s1, t_pile *node);
void	loop_rr_or_rrr(t_pile **s1, t_pile **s2,
			t_pile *cheapest, t_pile *find_min);
void	turk_algo(t_pile **s1, t_pile **s2);
void	free_split(char **array);
void	sort_stack(t_pile **s1, t_pile **s2);

t_pile	*ft_newlst(int nb);
t_pile	*create_stack(int argc, char **argv);
t_pile	*create_stack_quote(char **array);
t_pile	*find_max(t_pile *stack);
t_pile	*find_min(t_pile *stack);
t_pile	*first_biggest(int nb, t_pile *s1);
t_pile	*find_closest_biggest(int nb, t_pile *s1);
t_pile	*cheapest_cost(t_pile **s1, t_pile **s2);
t_pile	*cheapest_cost2(t_pile **s1, t_pile **s2);
t_pile	*find_closest_smaller(int nb, t_pile *s1);
#endif
