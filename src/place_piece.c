/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:14:22 by ratin             #+#    #+#             */
/*   Updated: 2019/04/18 20:13:48 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	check_pion(t_filler *filler, int x, int y)
{
	if (x >= filler->map_width || y >= filler->map_height)
		return (0);
	if (x < 0 || y < 0)
		return (0);
	if (filler->piece.contact == 0 && filler->map[y][x]
	== filler->my_territory.color)
	{
		filler->piece.contact = 1;
		return (1);
	}
	if (filler->map[y][x] == filler->my_territory.color
	&& filler->piece.contact == 1)
		return (0);
	if (filler->map[y][x] == filler->en_territory.color)
		return (0);
	return (1);
}

int			place_verif(t_filler *filler, int x, int y, int i)
{
	int		cp_x;
	int		cp_y;

	x -= filler->piece.all_piece[i].x;
	y -= filler->piece.all_piece[i].y;
	cp_y = 0;
	while (cp_y < filler->piece.y)
	{
		cp_x = 0;
		while (cp_x < filler->piece.x)
		{
			if (filler->piece.piece[cp_y][cp_x] == '*'
			&& check_pion(filler, x + cp_x, y + cp_y) == 0)
				return (0);
			cp_x++;
		}
		cp_y++;
	}
	if (filler->piece.contact == 0)
		return (0);
	return (1);
}

t_pion		found_piece_posineg(t_filler *filler, int x, int y)
{
	int		i;
	t_pion	error_pion;

	i = filler->piece.x * filler->piece.y - 1;
	error_pion.x = -1;
	while (i >= 0)
	{
		filler->piece.contact = 0;
		if (place_verif(filler, x, y, i) == 1)
			return (filler->piece.all_piece[i]);
		i--;
	}
	return (error_pion);
}

t_pion		found_piece_posi(t_filler *filler, int x, int y)
{
	int		i;
	t_pion	error_pion;

	i = 0;
	error_pion.x = -1;
	while (i < filler->piece.x * filler->piece.y)
	{
		filler->piece.contact = 0;
		if (place_verif(filler, x, y, i) == 1)
			return (filler->piece.all_piece[i]);
		i++;
	}
	return (error_pion);
}

int			ft_place_piece(t_filler *filler)
{
	t_pion	result;

	if (!(qg_scan_territory(filler)))
		return (0);
	if (!(get_piece_cordo(filler)))
		return (0);
	find_closest(filler);
	sort_closet(filler);
	result = found_place(filler);
	put_place(filler, result.x, result.y);
	return (1);
}
