/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:51:29 by abalasub          #+#    #+#             */
/*   Updated: 2024/04/04 16:27:47 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*cpy_until_nl(char *str)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (index_newline(str) + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

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

void	clean_buffer(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = index_newline(str) + 1;
	while (j <= BUFFER_SIZE - 1)
	{
		str[i] = str[j];
		i++;
		j++;
	}
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}	
}

char	*generate_line(char *buffer, char *line, int *is_nl)
{
	char	*rest;
	int		len_line;

	len_line = ft_strlen2(line);
	if (!search_newline(buffer))
		line = ft_strjoin2(line, buffer, len_line, ft_strlen2(buffer));
	else
	{
		rest = cpy_until_nl(buffer);
		line = ft_strjoin2(line, rest, len_line, ft_strlen2(rest));
		free(rest);
		clean_buffer(buffer);
		*is_nl = 1;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			readed;
	int			is_nl;

	line = NULL;
	is_nl = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	if (!line && buffer[0] != '\0')
		line = generate_line(buffer, line, &is_nl);
	readed = 1;
	while (!is_nl && !search_newline(buffer) && readed != 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		buffer[readed] = '\0';
		if (buffer[0] == '\0' && readed <= 0)
			return (line);
		line = generate_line(buffer, line, &is_nl);
	}
	return (line);
}
