/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coef.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:10:39 by ratin             #+#    #+#             */
/*   Updated: 2019/04/18 20:35:51 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		calc_coef(t_filler *filler, int i)
{
	int	result;

	result = ft_abs(filler->my_territory.territory[i].x - filler->closest.en.x)
	+ ft_abs(filler->my_territory.territory[i].y - filler->closest.en.y);
	return (result);
}

void	give_coef_closest(t_filler *filler)
{
	int	i;

	i = 0;
	while (i < filler->my_territory.nbr_of_pion)
	{
		filler->my_territory.territory[i].coef = calc_coef(filler, i);
		i++;
	}
}

void	give_coef_gotop_left(t_filler *filler)
{
	int	i;

	i = 0;
	while (i < filler->my_territory.nbr_of_pion)
	{
		filler->my_territory.territory[i].coef =
		filler->my_territory.territory[i].y
		+ filler->my_territory.territory[i].x;
		i++;
	}
}

void	give_coef_gotop_right(t_filler *filler)
{
	int	i;

	i = 0;
	while (i < filler->my_territory.nbr_of_pion)
	{
		filler->my_territory.territory[i].coef =
		filler->my_territory.territory[i].y
		- filler->my_territory.territory[i].x;
		i++;
	}
}

void	give_coef_botom(t_filler *filler)
{
	int	i;

	i = 0;
	while (i < filler->my_territory.nbr_of_pion)
	{
		filler->my_territory.territory[i].coef =
		-filler->my_territory.territory[i].y;
		i++;
	}
}
