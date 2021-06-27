/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuzawa <skuzawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:45:11 by skuzawa           #+#    #+#             */
/*   Updated: 2021/03/10 16:23:38 by skuzawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "bsq.h"

void	put_ans(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	g_ans = (char *)malloc(sizeof(char) * 60000);
	while (g_buff[i] != '\n')
		i++;
	i++;
	while (g_buff[j + i] != '\0')
	{
		g_ans[j] = g_buff[j + i];
		j++;
	}
	g_ans[j] = '\0';
	i = 0;
	while (g_ans[i])
		i++;
	write(1, g_ans, i);
	free(g_ans);
	free(g_buff);
}

void	write_full(int max, int bgn, int end)
{
	int i;
	int col;
	int cnt;

	i = 0;
	cnt = 0;
	while (g_buff[i])
	{
		if (g_buff[i] == '\n')
		{
			cnt++;
			col = -1;
		}
		else if ((cnt - 1) > (bgn - max) && (cnt - 1) <= bgn
		&& col > (end - max) && col <= end)
		{
			g_buff[i] = g_full;
		}
		col++;
		i++;
	}
	put_ans();
}

void	search_point(int max)
{
	int i;
	int j;

	i = 0;
	while (i < g_col)
	{
		j = 0;
		while (j < g_row)
		{
			if (g_ch[i][j] == max)
			{
				write_full(max, i, j);
				free(g_ch);
				return ;
			}
			j++;
		}
		i++;
	}
	free(g_ch);
}

void	find_max(void)
{
	int max;
	int i;
	int j;

	max = 0;
	i = 0;
	while (i < g_col)
	{
		j = 0;
		while (j < g_row)
		{
			if (max < g_ch[i][j])
			{
				max = g_ch[i][j];
			}
			j++;
		}
		i++;
	}
	search_point(max);
}

void	put_error(void)
{
	write(2, "map error\n", 10);
}
