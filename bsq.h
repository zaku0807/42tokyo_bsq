/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuzawa <skuzawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:49:29 by skuzawa           #+#    #+#             */
/*   Updated: 2021/03/10 15:54:27 by skuzawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

int		**g_board;
int		**g_ch;
int		g_flag;
int		g_row;
int		g_col;
char	g_emp;
char	g_obs;
char	g_full;
char	*g_buff;
char	*g_ans;
char	*g_filename;

void	ft_putstr(char *str);
void	put_error(void);
int		make_board1(void);
int		make_board2(int i);
int		min(int a, int b, int c);
int		check_around(int i, int j);
void	check_board1(void);
void	check_board2(void);
int		row_check(void);
int		fileopen(void);
int		fileread(void);
int		start(void);
int		count_row_col(void);
void	find_max(void);
void	search_point(int max);
void	write_full(int max, int bgn, int end);
void	put_ans(void);
int		input_num(void);

#endif
