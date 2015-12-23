/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 23:20:06 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/23 23:51:03 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# include <stdlib.h>
# include <unistd.h>

int		check_line(int line, int column, char c, char **tab);
int		check_column(int line, int column, char c, char **tab);
int		check_block(int line, int column, char c, char **tab);
int		check_emptycase(int line, int column, char c, char **tab);
int		check(int line, int column, char c, char **tab);
void	ft_putchar(char c);
void	print_tab(char **tab);
int		resolution(char **tab, char c, int number_of_9);
#endif
