/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuzawa <skuzawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 08:59:10 by skuzawa           #+#    #+#             */
/*   Updated: 2021/03/08 17:09:13 by skuzawa          ###   ########.fr       */
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
	i=0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	make_board(int b_row, int b_col)
{
	int i;
	int k;
	int j;

	i = 0;
	g_board=(int **)malloc(sizeof(int *) * (b_col));
	while (i < b_col)
	{
		g_board[i] = (int *)malloc(sizeof(int) * (b_row));
		i++;
	}
	i = 0;
	j = 0;
	while(g_buff[i]!='\n')
		i++;
	i++;
	k = 0;
	while(k < b_col)
	{
		j = 0;
		while (j < b_row)
		{
			if (g_buff[i] == g_buff[1])
				g_board[k][j] = 0;
			else if (g_buff[i] == g_buff[2])
				g_board[k][j] = -1;
			else
				;
			i++;
			j++;
		}
		i++;
		k++;
	}
}

int		min(int a, int b, int c)
{
	if(a == -1 || b == -1 || c == -1)
		return (1);
	if (a <=b && a <= c)
		return (a);
	else if(b <= c)
		return (b);
	else
		return (c);
}

int		check_around(int i, int j)
{
	if(g_board[i -1][j] == -1 || g_board[i - 1][j - 1] || g_board[i][j - 1])
		return (1);
	return (min(g_ch[i - 1][j], g_ch[i - 1][j - 1], g_ch[i][j - 1]) + 1);

}

void	check_board(int b_row, int b_col)
{
	int i;
	int j;

	g_ch = (int **)malloc(sizeof(int *) * b_col);
	i = 0;
	while (i < b_col)
	{
		g_ch[i] = (int *)malloc(sizeof(int) * b_row);
		i++;
	}
	i = -1;
	j = -1;
	while (++i < b_col)
	{
		if(g_board[i][0] != -1)
			g_ch[i][0] = 1;
		else
			g_ch[i][0] = -1;
	}	
	while (++j < b_row)
	{
		if (g_board[0][j] != -1)
			g_ch[0][j] = 1;
		else
			g_ch[0][j] = -1;
	}
	i = 1;
	while (i < b_col)
	{
		j = 1;
		while(j < b_row)
		{
			if (g_board[i][j] == -1)
				;
			else
				g_ch[i][j] = check_around(i, j);
			j++;
			
		}
		i++;
	}
}

int		fileopen(char *g_buff)
{
	int fd;
	int i;
	int b_row;
	int b_col;

	i = 0;
	fd = 0;
	b_row= 0;
	fd = open(g_filename, O_RDONLY);
	g_flag = read(fd, g_buff, 60000);
	g_buff[g_flag] = '\0';
	while (g_buff[i]!='\n')
		i++;
	while(g_buff[++i]!='\n')
	{
		b_row++;
	}
	b_col = g_buff[0] - '0';
	make_board(b_row, b_col);
	check_board(b_row, b_col);
	find_max(b_col, b_row);
	close(fd);
	return (0);
}

int		fileread(void)
{
	g_buff = (char*)malloc(sizeof(char) * 60000);
	if (g_buff == NULL)
		return (3);
	if (fileopen(g_buff) == 1)
		return (2);
	return (0);
	
}

int main(int argc, char **argv)
{
	int flag;
	int i;

	i = 0;
    if(argc < 2)
        return (0);
	while (++i < argc)
	{
		g_filename=argv[i];
		flag=fileread();
	}	
	return (0);
}
