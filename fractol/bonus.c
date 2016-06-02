/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 19:12:13 by mpressen          #+#    #+#             */
/*   Updated: 2016/06/02 20:13:06 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_fractal(int keycode, t_fractolparam *p)
{
	if (keycode == 101)
	{
		p->nbfract++;
		if (p->nbfract > 10)
			p->nbfract = 1;
	}
	if (keycode == 98)
	{
		p->nbfract--;
		if (p->nbfract < 1)
			p->nbfract = 10;
	}
}

void	recon_fractal(t_fractolparam *p)
{
	if (!ft_strcmp(p->fractal, "julia") || !ft_strcmp(p->fractal, "8"))
		p->nbfract = 8;
	else if (!ft_strcmp(p->fractal, "mandelbrot") ||
			!ft_strcmp(p->fractal, "1"))
		p->nbfract = 1;
	else if (!ft_strcmp(p->fractal, "mpressen") || !ft_strcmp(p->fractal, "7"))
		p->nbfract = 7;
	else if (!ft_strcmp(p->fractal, "sierpinski_triangle")
			|| !ft_strcmp(p->fractal, "9"))
		p->nbfract = 9;
	else if (!ft_strcmp(p->fractal, "sierpinski_carpet")
			|| !ft_strcmp(p->fractal, "10"))
		p->nbfract = 10;
	else if (!ft_strcmp(p->fractal, "burning_ship") ||
			!ft_strcmp(p->fractal, "5"))
		p->nbfract = 5;
	else if (!ft_strcmp(p->fractal, "logbrot") || !ft_strcmp(p->fractal, "6"))
		p->nbfract = 6;
	else if (!ft_strcmp(p->fractal, "multibrot") || !ft_strcmp(p->fractal, "3"))
		p->nbfract = 3;
	else if (!ft_strcmp(p->fractal, "mandelbar") || !ft_strcmp(p->fractal, "2"))
		p->nbfract = 2;
	else if (!ft_strcmp(p->fractal, "multibar") || !ft_strcmp(p->fractal, "4"))
		p->nbfract = 4;
}
