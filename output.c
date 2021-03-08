/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuzawa <skuzawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:45:11 by skuzawa           #+#    #+#             */
/*   Updated: 2021/03/08 16:54:50 by skuzawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "bsq.h"

void	write_full(int max, int bgn, int end)
{
	int r;
	int byte_num;
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
		else if ((cnt - 1) >= (bgn - max) && (cnt - 1) <= bgn 
		&& col > (end - max) && col <= end)
		{
			g_buff[i] = g_buff[3]; 
		}
		col++;
		i++;
	}
	r = open(g_filename, O_WRONLY);
	byte_num = write(r, g_buff, g_flag);
	return ;
}

void	search_point(int max, int b_col, int b_row)
{
	int i;
	int j;

	i = 0;
	while (i < b_col)
	{
		j = 0;
		while (j < b_row)
		{
			if (g_ch[i][j] == max)
			{
				write_full(max, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	find_max(int b_col, int b_row)
{
	int max;
	int i;
	int j;

	max = 0;
	i =0;
	while (i < b_col)
	{
		j = 0;
		while (j < b_row)
		{
			if(max < g_ch[i][j])
			{
				max = g_ch[i][j];
			}
			j++;
		}
		i++;
	}
	search_point(max, b_col, b_row);
}