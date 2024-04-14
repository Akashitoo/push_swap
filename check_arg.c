/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:40:07 by abalasub          #+#    #+#             */
/*   Updated: 2024/03/27 20:06:05 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '-')
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_int(char *str)
{
	if (ft_strlen(str) > 11)
		return (0);
	if (ft_strlen(str) == 11 && str[0] == '-')
	{
		if (ft_strncmp("-2147483648", str, 11) < 0)
			return (0);
	}
	if (ft_strlen(str) == 11 && str[0] != '-')
	{
		return (0);
	}
	if (ft_strlen(str) == 10)
	{
		if (ft_strncmp("2147483647", str, 10) < 0)
			return (0);
	}
	return (1);
}

int	is_double(char **array, int i, int start)
{
	int	j;

	j = start;
	while (j < i)
	{
		if (ft_atoi(array[i]) == ft_atoi(array[j]))
			return (1);
		j++;
	}
	return (0);
}	

int	check_args(char **array, int start)
{
	int	i;

	if (!array)
		return (0);
	i = start;
	while (array[i])
	{
		if (!is_number(array[i]) || !is_int(array[i]))
		{
			if (!start)
				free_split(array);
			ft_printf("Error\n");
			return (0);
		}
		if (is_double(array, i, start))
		{
			if (!start)
				free_split(array);
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}
