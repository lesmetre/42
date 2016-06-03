/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 12:54:09 by mpressen          #+#    #+#             */
/*   Updated: 2016/06/03 13:37:51 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_hook2(int button, t_fractolparam *p)
{
	if (button == 5)
	{
		p->zoom *= 1.1;
		if ((int)p->zoom % 2)
			p->imax += 1;
	}
	else if (button == 4)
	{
		p->zoom *= 0.9;
		if ((int)p->zoom % 2)
			p->imax -= 1;
	}
}

void	rename_file(t_fractolparam *p)
{
	if (p->nbfract == 1)
		p->fractal = ft_strdup("mandelbrot");
	if (p->nbfract == 2)
		p->fractal = ft_strdup("mandelbar");
	if (p->nbfract == 3)
		p->fractal = ft_strdup("multibrot");
	if (p->nbfract == 4)
		p->fractal = ft_strdup("multibar");
	if (p->nbfract == 5)
		p->fractal = ft_strdup("burning_ship");
	if (p->nbfract == 6)
		p->fractal = ft_strdup("logbrot");
	if (p->nbfract == 7)
		p->fractal = ft_strdup("mpressen");
	if (p->nbfract == 8)
		p->fractal = ft_strdup("julia");
	if (p->nbfract == 9)
		p->fractal = ft_strdup("sierpinski_triangle");
	if (p->nbfract == 10)
		p->fractal = ft_strdup("sierpinski_carpet");
}
