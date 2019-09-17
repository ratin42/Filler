/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 04:25:31 by ratin             #+#    #+#             */
/*   Updated: 2019/04/27 19:40:40 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			count_get_pion(t_filler *filler, t_territory *territory)
{
	int		x;
	int		y;
	int		count;

	y = 0;
	count = 0;
	while (y < filler->map_height)
	{
		x = -1;
		while (++x < filler->map_width)
		{
			if (filler->map[y][x] == territory->color - 32)
			{
				count++;
			}
		}
		y++;
	}
	territory->nbr_of_pion = count;
	if (!(territory->territory = (t_pion *)malloc(sizeof(t_pion)
	* count)))
	{
		return (0);
	}
	return (1);
}

int			get_pion(t_filler *filler, t_territory *territory)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	if (!(count_get_pion(filler, territory)))
		return (0);
	while (y < filler->map_height)
	{
		x = 0;
		while (x < filler->map_width)
		{
			if (filler->map[y][x] == territory->color - 32)
			{
				filler->map[y][x] = territory->color;
				territory->territory[i].x = x;
				territory->territory[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
	return (1);
}
