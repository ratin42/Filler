/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_closest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 03:49:44 by ratin             #+#    #+#             */
/*   Updated: 2019/04/18 20:39:14 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		sort_big_map(t_filler *filler)
{
	if (filler->player == 2 && filler->turn < 80 && gofar(filler) == 0)
	{
		dprintf(filler->fd, "go botom for turn %d\n", filler->turn);
		give_coef_botom(filler);
	}
	else if (filler->player == 2 && (gofar(filler) == 1
	&& filler->turn < 60))
	{
		dprintf(filler->fd, "go top for turn %d\n", filler->turn);
		if (filler->turn % 2 == 0)
			give_coef_gotop_left(filler);
		else
			give_coef_gotop_right(filler);
	}
	else
	{
		dprintf(filler->fd, "go else for turn  %d\n", filler->turn);
		give_coef_closest(filler);
	}
}

void		sort_closet(t_filler *filler)
{
	if (filler->map_width > 20)
		sort_big_map(filler);
	else
	{
		dprintf(filler->fd, "go else sub for turn  %d\n", filler->turn);
		if (filler->player == 2 && (filler->turn > 2 && touch_top(filler) == 0))
		{
			dprintf(filler->fd, "go else top for turn  %d\n", filler->turn);
			give_coef_gotop_right(filler);
		}
		else
			give_coef_closest(filler);
	}
	sort_pion(filler, filler->my_territory.territory);
}
