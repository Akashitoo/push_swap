/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:52:27 by abalasub          #+#    #+#             */
/*   Updated: 2023/11/21 14:22:55 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	rc;
	char			*rs;

	rs = s;
	rc = c;
	while (n--)
		*rs++ = rc;
	return (s);
}
