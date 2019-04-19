/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:39:37 by ratin             #+#    #+#             */
/*   Updated: 2019/04/18 20:38:38 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			touch_top(t_filler *filler)
{
	int		x;

	x = 0;
	while (x < filler->map_width)
	{
		if (filler->map[0][x] == filler->my_territory.color)
			return (1);
		x++;
	}
	return (0);
}

int			gofar(t_filler *filler)
{
	int		y;

	y = 0;
	while (y < filler->map_height)
	{
		if (filler->map[y][5] == filler->my_territory.color)
			return (1);
		y++;
	}
	return (0);
}

void		init_env(t_filler *filler)
{
	filler->map = NULL;
	filler->map_free = 0;
	filler->piece.piece_free = 0;
	filler->piece.piece = NULL;
	filler->piece.all_piece = NULL;
	filler->en_territory.territory = NULL;
	filler->my_territory.territory = NULL;
}

void		free_env(t_filler *filler)
{
	free_double_char(filler->map, filler->map_free);
	free_double_char(filler->piece.piece, filler->piece.piece_free);
	free(filler->my_territory.territory);
	free(filler->en_territory.territory);
	free(filler->piece.all_piece);
}
