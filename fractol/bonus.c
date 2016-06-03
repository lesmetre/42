/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpressen <mpressen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 19:12:13 by mpressen          #+#    #+#             */
/*   Updated: 2016/06/03 13:38:20 by mpressen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		change_fractal(int keycode, t_fractolparam **p)
{
	if (keycode == 47)
	{
		(*p)->nbfract++;
		if ((*p)->nbfract > 10)
			(*p)->nbfract = 1;
	}
	if (keycode == 43)
	{
		(*p)->nbfract--;
		if ((*p)->nbfract < 1)
			(*p)->nbfract = 10;
	}
	rename_file(*p);
}

static void	name_fractal3(t_fractolparam *p)
{
	if (!ft_strcmp(p->fractal, "10"))
	{
		p->nbfract = 10;
		p->fractal = ft_strdup("sierpinski_carpet");
	}
	else if (!ft_strcmp(p->fractal, "4"))
	{
		p->nbfract = 4;
		p->fractal = ft_strdup("multibar");
	}
	if (!ft_strcmp(p->fractal, "10"))
	{
		p->nbfract = 10;
		p->fractal = ft_strdup("sierpinski_carpet");
	}
}

static void	name_fractal2(t_fractolparam *p)
{
	if (!ft_strcmp(p->fractal, "5"))
	{
		p->nbfract = 5;
		p->fractal = ft_strdup("burning_ship");
	}
	else if (!ft_strcmp(p->fractal, "6"))
	{
		p->nbfract = 6;
		p->fractal = ft_strdup("logbrot");
	}
	else if (!ft_strcmp(p->fractal, "3"))
	{
		p->nbfract = 3;
		p->fractal = ft_strdup("multibrot");
	}
	else if (!ft_strcmp(p->fractal, "2"))
	{
		p->nbfract = 2;
		p->fractal = ft_strdup("mandelbar");
	}
	else
		name_fractal3(p);
}

static void	name_fractal(t_fractolparam **p)
{
	if (!ft_strcmp((*p)->fractal, "8"))
	{
		(*p)->nbfract = 8;
		(*p)->fractal = ft_strdup("julia");
	}
	else if (!ft_strcmp((*p)->fractal, "1"))
	{
		(*p)->nbfract = 1;
		(*p)->fractal = ft_strdup("mandelbrot");
	}
	else if (!ft_strcmp((*p)->fractal, "7"))
	{
		(*p)->nbfract = 7;
		(*p)->fractal = ft_strdup("mpressen");
	}
	else if (!ft_strcmp((*p)->fractal, "9"))
	{
		(*p)->nbfract = 9;
		(*p)->fractal = ft_strdup("sierpinski_triangle");
	}
	else
		name_fractal2(*p);
}

void		recon_fractal(t_fractolparam *p)
{
	if (ft_isdigit(p->fractal[0]))
		name_fractal(&p);
	else
	{
		if (!ft_strcmp(p->fractal, "julia"))
			p->nbfract = 8;
		else if (!ft_strcmp(p->fractal, "mandelbrot"))
			p->nbfract = 1;
		else if (!ft_strcmp(p->fractal, "mpressen"))
			p->nbfract = 7;
		else if (!ft_strcmp(p->fractal, "sierpinski_triangle"))
			p->nbfract = 9;
		else if (!ft_strcmp(p->fractal, "sierpinski_carpet"))
			p->nbfract = 10;
		else if (!ft_strcmp(p->fractal, "burning_ship"))
			p->nbfract = 5;
		else if (!ft_strcmp(p->fractal, "logbrot"))
			p->nbfract = 6;
		else if (!ft_strcmp(p->fractal, "multibrot"))
			p->nbfract = 3;
		else if (!ft_strcmp(p->fractal, "mandelbar"))
			p->nbfract = 2;
		else if (!ft_strcmp(p->fractal, "multibar"))
			p->nbfract = 4;
	}
}
