/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 04:22:16 by ratin             #+#    #+#             */
/*   Updated: 2019/04/18 20:34:13 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		put_place(t_filler *filler, int x, int y)
{
	ft_putnbr_fd(y, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(x, 1);
	ft_putchar_fd('\n', 1);
	(void)filler;
}

static int	give_result(t_filler *filler, int i, int ennemy)
{
	int		result;

	result = ft_abs(filler->my_territory.territory[i].x
	- filler->en_territory.territory[ennemy].x)
	+ ft_abs(filler->my_territory.territory[i].y
	- filler->en_territory.territory[ennemy].y);
	return (result);
}

void		write_closest(t_filler *filler, int result, int my, int ennemy)
{
	filler->closest.coef = result;
	filler->closest.my = filler->my_territory.territory[my];
	filler->closest.en = filler->en_territory.territory[ennemy];
}

void		find_closest(t_filler *filler)
{
	int		my;
	int		ennemy;
	int		result;
	t_pion	current;

	my = 0;
	filler->closest.coef = 1000000;
	while (my < filler->my_territory.nbr_of_pion)
	{
		ennemy = 0;
		current = found_piece_posi(filler, filler->my_territory.territory[my].x,
		filler->my_territory.territory[my].y);
		if (current.x != -1)
		{
			while (ennemy < filler->en_territory.nbr_of_pion)
			{
				result = give_result(filler, my, ennemy);
				if (result < filler->closest.coef)
					write_closest(filler, result, my, ennemy);
				ennemy++;
			}
		}
		my++;
	}
}
