/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 06:58:39 by ratin             #+#    #+#             */
/*   Updated: 2019/04/18 20:32:44 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_pion		compute_result(t_filler *filler, t_pion result, int i)
{
	if (result.x == -1 && i == filler->my_territory.nbr_of_pion)
	{
		result.x = 0;
		result.y = 0;
		filler->fin = 0;
	}
	else
	{
		result.x = filler->my_territory.territory[i].x - result.x;
		result.y = filler->my_territory.territory[i].y - result.y;
	}
	return (result);
}

t_pion		check_piece_neg(t_filler *filler, t_pion result, int i)
{
	result = found_piece_posineg(filler,
	filler->my_territory.territory[i].x
	, filler->my_territory.territory[i].y);
	return (result);
}

t_pion		found_place(t_filler *filler)
{
	int		i;
	int		x;
	int		y;
	t_pion	result;

	i = 0;
	x = filler->closest.my.x;
	y = filler->closest.my.y;
	while (i < filler->my_territory.nbr_of_pion)
	{
		if (filler->player == 2)
			result = check_piece_neg(filler, result, i);
		else
		{
			result = found_piece_posi(filler,
			filler->my_territory.territory[i].x
			, filler->my_territory.territory[i].y);
		}
		if (result.x != -1)
			break ;
		i++;
	}
	result = compute_result(filler, result, i);
	return (result);
}
