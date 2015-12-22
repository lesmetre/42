/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eight_queens.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:43:07 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/22 14:51:16 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EIGHT_QUEENS_H
# define EIGHT_QUEENS_H

# include <stdlib.h>
# include <unistd.h>

void	resolution(char **tab, int queens);
char	**backtracking(char **tab);
void	free_tab(char **tab);
int		no_queen_check(int line, int column, char **tab);
int		no_queen_diagonale_right(int line, int column, char **tab);
int		no_queen_diagonale_left(int line, int column, char **tab);
int		no_queen_column(int line, int column, char **tab);
int		no_queen_line(int line, int column, char **tab);
void	print_tab(char **tab);
char	**create_tab_with_points(void);
void	ft_putchar(char c);

#endif
