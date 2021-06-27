/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuzawa <skuzawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:19:49 by skuzawa           #+#    #+#             */
/*   Updated: 2021/03/10 19:48:38 by skuzawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

int		make_board2(int i)
{
	int k;
	int j;

	k = 0;
	while (k < g_col)
	{
		j = 0;
		while (j < g_row)
		{
			if (g_buff[i] == g_emp)
				g_board[k][j] = 0;
			else if (g_buff[i] == g_obs)
				g_board[k][j] = -1;
			else if (g_buff[i] != '\n')
				return (1);
			j++;
			i++;
		}
		i++;
		k++;
	}
	return (0);
}

int		make_board1(void)
{
	int i;

	i = -1;
	g_board = (int **)malloc(sizeof(int *) * (g_col));
	while (++i < g_col)
		g_board[i] = (int *)malloc(sizeof(int) * (g_row));
	i = 0;
	while (g_buff[i] != '\n')
		i++;
	i++;
	if (make_board2(i) == 0)
		return (0);
	else
		return (1);
}

int		check_around(int i, int j)
{
	if (g_board[i - 1][j] == -1 || g_board[i - 1][j - 1] == -1
	|| g_board[i][j - 1] == -1)
		return (1);
	return (min(g_ch[i - 1][j], g_ch[i - 1][j - 1], g_ch[i][j - 1]) + 1);
}

void	check_board2(void)
{
	int i;
	int j;

	i = 1;
	while (i < g_col)
	{
		j = 1;
		while (j < g_row)
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

void	check_board1(void)
{
	int i;
	int j;

	g_ch = (int **)malloc(sizeof(int *) * g_col);
	i = -1;
	while (++i < g_col)
		g_ch[i] = (int *)malloc(sizeof(int) * g_row);
	i = -1;
	j = -1;
	while (++i < g_col)
	{
		if (g_board[i][0] != -1)
			g_ch[i][0] = 1;
		else
			g_ch[i][0] = -1;
	}
	while (++j < g_row)
	{
		if (g_board[0][j] != -1)
			g_ch[0][j] = 1;
		else
			g_ch[0][j] = -1;
	}
	check_board2();
}
