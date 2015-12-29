/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 23:20:06 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/29 01:26:06 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# include <stdlib.h>
# include <unistd.h>

int		check_line(int line, char c, char **tab);
int		check_column(int column, char c, char **tab);
int		check_block(int line, int column, char c, char **tab);
int		check_emptycase(int line, int column, char **tab);
int		check(int line, int column, char c, char **tab);
void	ft_putchar(char c);
void	print_tab(char **tab);
int		resolution(char **tab);
void	free_tab(char **tab);
int		count_solutions(char **tab);
#endif
