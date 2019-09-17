/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:59:07 by ratin             #+#    #+#             */
/*   Updated: 2019/04/26 16:55:31 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

int			quit_fdf(t_party *party)
{
	mlx_clear_window(party->mlx.mlx_ptr, party->mlx.win_ptr);
	mlx_destroy_window(party->mlx.mlx_ptr, party->mlx.win_ptr);
	free_prog(party);
	exit(1);
	return (0);
}

int			init_mlx(t_party *party)
{
	if (!(party->mlx.mlx_ptr = mlx_init()))
		quit_fdf(party);
	if (!(party->mlx.win_ptr = mlx_new_window(party->mlx.mlx_ptr, WIDTH, HEIGHT
	, "Filler")))
		quit_fdf(party);
	if (!(party->mlx.img.img_ptr = mlx_new_image(party->mlx.mlx_ptr, WIDTH
	, HEIGHT)))
		quit_fdf(party);
	party->mlx.img.data = (int *)mlx_get_data_addr(party->mlx.img.img_ptr
	, &party->mlx.img.bpp,
	&party->mlx.img.size_l, &party->mlx.img.endian);
	return (1);
}

void		back_screen(t_party *party)
{
	int		y;
	int		x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_put_pixel(&party->mlx, x, y, BACKSCREEN);
			x++;
		}
		y++;
	}
}

int			draw(t_party *party)
{
	t_mlx	*mlx;

	mlx = &party->mlx;
	while (1)
	{
		mlx_clear_window(party->mlx.mlx_ptr, party->mlx.win_ptr);
		mlx_destroy_image(party->mlx.mlx_ptr, party->mlx.img.img_ptr);
		party->mlx.img.img_ptr = mlx_new_image(party->mlx.mlx_ptr, WIDTH
		, HEIGHT);
		party->mlx.img.data = (int *)mlx_get_data_addr(party->mlx.img.img_ptr
		, &party->mlx.img.bpp,
		&party->mlx.img.size_l, &party->mlx.img.endian);
		back_screen(party);
		make_board(party);
		mlx_put_image_to_window(party->mlx.mlx_ptr, party->mlx.win_ptr
		, party->mlx.img.img_ptr, 0, 0);
		print_ath(party);
		mlx_do_sync(party->mlx.mlx_ptr);
		if (party->pause == 0 && party->i < party->turn - 1)
			party->i += 1;
	}
	return (1);
}
