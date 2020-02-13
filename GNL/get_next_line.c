/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:06:27 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/11/08 13:21:01 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strndup(const char *s, size_t len)
{
	char	*back;
	size_t	x;

	if (!(back = ft_memalloc(len + 1)))
		return (NULL);
	x = 0;
	while (s[x] && x < len)
	{
		back[x] = s[x];
		x++;
	}
	return (back);
}

char		*copy_untill_newline(const char *str, char c)
{
	char	*back;
	char	*temp;
	int		x;

	x = 0;
	if (!str)
		return (NULL);
	if (!(temp = ft_strchr(str, c)))
		return (ft_strdup(str));
	while (str[x] != c)
		x++;
	back = ft_strndup(str, x);
	return (back);
}

static int	next_line(const int fd, char **line, char **str)
{
	char	*temp;

	if (ft_strchr(str[fd], '\n'))
	{
		*line = copy_untill_newline(str[fd], '\n');
		temp = ft_strdup(str[fd] + ft_strlen(*line) + 1);
		ft_strdel(&str[fd]);
		if (ft_strlen(temp) > 0)
			str[fd] = temp;
		else
			ft_strdel(&temp);
	}
	else if (str[fd])
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[FD_COUNT];
	char		*temp;
	char		buffer[BUFF_SIZE + 1];
	int			readvalue;

	if (fd < 0 || fd > 4864 || !line)
		return (-1);
	while ((readvalue = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[readvalue] = '\0';
		if (!str[fd])
			str[fd] = ft_strnew(1);
		temp = ft_strjoin(str[fd], buffer);
		ft_strdel(&str[fd]);
		str[fd] = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (readvalue < 0)
		return (-1);
	if (!readvalue && !str[fd])
		return (0);
	return (next_line(fd, line, str));
}
