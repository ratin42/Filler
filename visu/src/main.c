/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:48:23 by ratin             #+#    #+#             */
/*   Updated: 2019/04/26 17:04:52 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

int				main(void)
{
	t_party		party;
	t_mlx		*mlx;

	mlx = &party.mlx;
	party.i = 0;
	party.image = NULL;
	if (!(parse_game(&party)))
		quit_fdf(&party);
	if (!(init_mlx(&party)))
		quit_fdf(&party);
	if (!(init_game(&party)))
		quit_fdf(&party);
	mlx_hook(mlx->win_ptr, KeyPress, PointerMotionMask, handle_key, &party);
	mlx_hook(party.mlx.win_ptr, DestroyNotify, PointerMotionMask, quit_fdf
	, &party);
	draw(&party);
	return (0);
}
