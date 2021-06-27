/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuzawa <skuzawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 08:59:10 by skuzawa           #+#    #+#             */
/*   Updated: 2021/03/10 20:57:29 by skuzawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		min(int a, int b, int c)
{
	if (a == -1 || b == -1 || c == -1)
		return (1);
	if (a <= b && a <= c)
		return (a);
	else if (b <= c)
		return (b);
	else
		return (c);
}

int		count_row_col(void)
{
	int i;
	int j;

	g_row = 0;
	i = 0;
	j = 0;
	while (g_buff[i] != '\n')
		i++;
	while (g_buff[++i] != '\n')
		g_row++;
	g_col = input_num();
	if (row_check() == 1)
		return (1);
	if (make_board1() == 1 || g_col == -1)
		return (1);
	check_board1();
	free(g_board);
	find_max();
	return (0);
}

int		fileopen(void)
{
	int fd;
	int i;
	int flag;
	int sum;

	sum = 0;
	i = 0;
	flag = 0;
	fd = open(g_filename, O_RDONLY);
	while (flag != -1)
	{
		g_flag = read(fd, g_buff, 60000);
		if (g_flag != -1)
			sum += flag;
 	}
	if (g_flag == -1)
		return (1);
	close(fd);
	g_buff[g_flag] = '\0';
	flag = count_row_col();
	if (flag == 1)
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	g_buff = (char *)malloc(sizeof(char) * 60000);
	if (argc < 2)
	{
		if (count_row_col() == 1 || start() == 1)
			put_error();
	}
	else
	{
		while (++i < argc)
		{
			g_filename = argv[i];
			if (fileopen() == 1)
				put_error();
		}
	}
	return (0);
}
