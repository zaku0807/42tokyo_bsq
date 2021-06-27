/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuzawa <skuzawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:32:07 by skuzawa           #+#    #+#             */
/*   Updated: 2021/03/10 15:38:38 by skuzawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "bsq.h"

int		start(void)
{
	g_flag = read(0, g_buff, 60000);
	g_buff[g_flag] = '\0';
	if (g_buff == NULL)
		return (1);
	return (0);
}

int		input_num(void)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (g_buff[i] == '\v' || g_buff[i] == '\t' || g_buff[i] == '\n' ||
	g_buff[i] == '\r' || g_buff[i] == '\f' || g_buff[i] == ' ')
		i++;
	while (g_buff[i] != '\0' && g_buff[i] >= '0' && g_buff[i] <= '9')
	{
		ret = ret * 10 + (g_buff[i] - '0');
		i++;
	}
	i = 0;
	while (g_buff[i] != '\n')
		i++;
	g_full = g_buff[--i];
	g_obs = g_buff[--i];
	g_emp = g_buff[--i];
	if (ret == 0 || !(g_emp > ' ' && g_emp <= '~') || !(g_obs > ' '
	&& g_obs <= '~') || !(g_full > ' ' && g_full <= '~') || g_full == g_obs ||
	g_emp == g_obs || g_emp == g_full)
		return (-1);
	else
		return (ret);
}

int		row_check(void)
{
	int i;
	int j;
	int cnt;

	i = 0;
	j = 0;
	while (g_buff[i] != '\n')
		i++;
	i++;
	while (j < g_col)
	{
		cnt = 0;
		while (g_buff[i] != '\n')
		{
			cnt++;
			i++;
		}
		i++;
		j++;
		if (cnt != g_row)
			return (1);
	}
	return (0);
}
