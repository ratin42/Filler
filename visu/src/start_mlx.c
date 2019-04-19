/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:59:07 by ratin             #+#    #+#             */
/*   Updated: 2019/04/19 16:32:19 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

int	quit_fdf(void *mlx)
{
	mlx_clear_window(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr);
	mlx_destroy_window(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr);
	exit(1);
	return (0);
}

int		init_mlx(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		return (0);
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Filler")))
		return (0);
	if (!(mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT)))
		return (0);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
	&mlx->img.size_l, &mlx->img.endian);
	return (1);
}

int			draw(void *mlx, t_filler *filler)
{
	//t_point	*point;

	mlx_clear_window(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr);
	mlx_destroy_image(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->img.img_ptr);
	((t_mlx *)mlx)->img.img_ptr = mlx_new_image(((t_mlx *)mlx)->mlx_ptr, WIDTH,
	HEIGHT);
	((t_mlx *)mlx)->img.data = (int *)mlx_get_data_addr(
	((t_mlx *)mlx)->img.img_ptr, &((t_mlx *)mlx)->img.bpp,
	&((t_mlx *)mlx)->img.size_l, &((t_mlx *)mlx)->img.endian);

	//function to draw

	mlx_put_image_to_window(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr,
	((t_mlx *)mlx)->img.img_ptr, 0, 0);
	(void)filler;
	return (0);
}
