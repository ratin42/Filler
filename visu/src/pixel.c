/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:39:11 by ratin             #+#    #+#             */
/*   Updated: 2019/04/26 17:07:30 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

int		ft_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	if (y < HEIGHT && y > 0 && x < WIDTH && x > 0)
		mlx->img.data[y * WIDTH + x] = color;
	return (0);
}

int		print_lines(t_point *point1, t_point *point2, t_mlx *mlx, int color)
{
	if (point1->y <= point2->y)
		put_line(point1, point2, mlx, color);
	else
		put_line(point2, point1, mlx, color);
	return (0);
}

/*
** print vertical lines for print_lines
*/

void	vertical_limit(t_point *point1, t_point *point2, t_mlx *mlx, int color)
{
	int	y;

	y = point1->y;
	while (y < point2->y)
	{
		ft_put_pixel(mlx, point1->x, y, color);
		y++;
	}
}

int		handle_key(int key, t_party *party)
{
	if (key == 53)
		quit_fdf(party);
	if (key == 49)
	{
		if (party->pause == 0)
			party->pause = 1;
		else
			party->pause = 0;
	}
	if (key == 123 && party->i > 0)
		party->i--;
	if (key == 124 && party->i < party->turn - 1)
		party->i++;
	return (1);
}
