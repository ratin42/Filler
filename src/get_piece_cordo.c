/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece_cordo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:36:24 by ratin             #+#    #+#             */
/*   Updated: 2019/04/18 20:34:19 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			scan_all_piece(t_filler *filler)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!(filler->piece.all_piece = (t_pion *)malloc(sizeof(t_pion)
	* (filler->piece.x * filler->piece.y))))
		return (0);
	while (i < filler->piece.y)
	{
		j = 0;
		while (j < filler->piece.x)
		{
			filler->piece.all_piece[k].x = j;
			filler->piece.all_piece[k].y = i;
			k++;
			j++;
		}
		i++;
	}
	return (1);
}

int			get_piece_cordo(t_filler *filler)
{
	filler->piece.i = 0;
	if (!(scan_all_piece(filler)))
		return (0);
	return (1);
}
