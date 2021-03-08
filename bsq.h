/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuzawa <skuzawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:49:29 by skuzawa           #+#    #+#             */
/*   Updated: 2021/03/08 16:53:47 by skuzawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

int		**g_board;
int		**g_ch;
int		g_flag;
char	*g_buff;
char	*g_filename;

void	ft_putstr(char *str);
void	make_board(int b_row, int b_col);
int		min(int a,int b,int c);
int		check_around(int i, int j);
void	check_board(int b_row, int b_col);
int		fileopen(char *g_buff);
int		fileread(void);
void	find_max(int b_col, int b_row);
void	search_point(int max, int b_col, int b_row);
void	write_full(int max, int bgn, int end);

#endif
