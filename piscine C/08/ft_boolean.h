/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 04:15:54 by mpressen          #+#    #+#             */
/*   Updated: 2015/12/09 04:36:31 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define TRUE		1
# define FALSE		0
# define EVEN(x)	!(x % 2)
# define EVEN_MSG	"J'ai un nombre pair d'arguments.\n"
# define ODD_MSG	"J'ai un nombre impair d'arguments.\n"
# define SUCCESS	0

typedef	int	t_bool;

#endif
