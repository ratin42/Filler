/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_territory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 03:36:26 by ratin             #+#    #+#             */
/*   Updated: 2019/04/15 14:22:24 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			init_territory(t_filler *filler)
{
	filler->my_territory.nbr_of_pion = 0;
	filler->en_territory.nbr_of_pion = 0;
	filler->my_territory.territory = NULL;
	filler->en_territory.territory = NULL;
	if (filler->player == 1)
	{
		filler->my_territory.color = 'o';
		filler->en_territory.color = 'x';
	}
	else
	{
		filler->my_territory.color = 'x';
		filler->en_territory.color = 'o';
	}
}

/*
** Lance les differentes fonction de scan
*/

int				qg_scan_territory(t_filler *filler)
{
	init_territory(filler);
	get_pion(filler, &filler->my_territory);
	get_pion(filler, &filler->en_territory);
	return (1);
}
