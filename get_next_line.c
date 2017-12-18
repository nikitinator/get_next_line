/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:02:13 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/08 15:02:48 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				copy_to_lnbreak(char **line, char *str)
{
	size_t	i;
	char	*to_free;

	i = 0;
	to_free = *line;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		str[i] = '\0';
		i++;
		*line = ft_strjoin(*line, str);
		free(to_free);
		ft_strcpy(str, str + i);
		ft_strclr(str + ft_strlen(str));//
		return (LINE);
	}
	else if (str[i] == '\0')
	{
		*line = ft_strjoin(*line, str);
		free(to_free);
		ft_strclr(str);
		return (NOT_LINE);
	}
	return (ERROR);
}

int				get_next_line(const int fd, char **line)
{
	int			n_bytes_read;
	char		buf[BUFF_SIZE + 1];
	static char	storage[FD_SIZE][BUFF_SIZE];

	if (fd < 0 || !line || FD_SIZE <= 0 || !(*line = ft_strnew(0)))
		return (ERROR);
	ft_bzero(buf, BUFF_SIZE + 1);
	if (copy_to_lnbreak(line, storage[fd]) == LINE)
		return (LINE);
	while ((n_bytes_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if ((copy_to_lnbreak(line, buf) == LINE))
		{
			ft_strcpy(storage[fd], buf);
			return (LINE);
		}
	}
	if (**line)
		return (LINE);
	return (n_bytes_read);
}
