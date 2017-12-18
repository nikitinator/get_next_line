/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 19:39:51 by snikitin          #+#    #+#             */
/*   Updated: 2017/12/07 14:35:43 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		result;

	int	fd;

	if (argc != 2)
	{
		ft_putendl("fuck you");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
/*	while (result > 0)
	{
		result = get_next_line(fd, &line);
		printf("\nline:%s|||\n\n\n", line);
		printf("result:%d\n%s\n",result, line);
		free(line);
	}*/
	while ((result = get_next_line(fd, &line)) > 0)
	{
		printf("______________________________|\n");	
		printf("result:%d|||\n", result);
		printf("line:%s|||\n", line);
		free(line);
		printf("______________________________|\n");
	}
		printf("______________________________|\n");
		printf("result:%d|||\n", result);
		printf("line:%s|||\n", line);
		
		free(line);
		//result = get_next_line(fd, &line);
		//free(line);
	
	return (0);	
}
