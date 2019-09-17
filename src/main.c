/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:49:18 by ratin             #+#    #+#             */
/*   Updated: 2019/05/04 17:32:10 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int				main(void)
{
	t_filler	filler;

	filler.fin = 1;
	filler.player = 0;
	filler.turn = 0;
	while (filler.fin == 1)
	{
		filler.turn++;
		init_env(&filler);
		if (!(get_env(&filler)))
		{
			free_env(&filler);
			return (0);
		}
		if (!(ft_place_piece(&filler)))
		{
			free_env(&filler);
			return (0);
		}
		free_env(&filler);
	}
	return (0);
}
