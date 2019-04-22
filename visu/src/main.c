/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <Raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:48:23 by ratin             #+#    #+#             */
/*   Updated: 2019/04/21 20:06:25 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

int				main(void)
{
	t_mlx		mlx;
	t_game		*game;

	if (!(parse_game(&game)))
		return (0);
	if (!(init_mlx(&mlx)))
		return (0);
	mlx_hook(mlx.win_ptr, DestroyNotify, PointerMotionMask, quit_fdf, (void *)&mlx);
	//mlx_loop_hook(mlx.mlx_ptr, draw, &mlx);
	mlx_loop(mlx.mlx_ptr);
	(void)filler;
	return (0);
}
