/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:39:58 by ratin             #+#    #+#             */
/*   Updated: 2019/04/18 20:34:23 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	find_smaller_x(t_filler *filler, t_point *x_smaller)
{
	int	x;
	int	y;

	x = 0;
	while (x < filler->piece.x - 1)
	{
		y = 0;
		while (y < filler->piece.y - 1)
		{
			if (filler->piece.piece[y][x] == '*')
			{
				x_smaller->x = x;
				x_smaller->y = y;
				return ;
			}
			y++;
		}
		x++;
	}
	x_smaller->x = -1;
	x_smaller->y = -1;
}

void	find_bigger_x(t_filler *filler, t_point *x_smaller)
{
	int	x;
	int	y;

	x = filler->piece.x - 1;
	while (x >= 0)
	{
		y = 0;
		while (y < filler->piece.y)
		{
			if (filler->piece.piece[y][x] == '*')
			{
				x_smaller->x = x;
				x_smaller->y = y;
				return ;
			}
			y++;
		}
		x--;
	}
	x_smaller->x = -1;
	x_smaller->y = -1;
}

void	find_smaller_y(t_filler *filler, t_point *y_smaller)
{
	int	x;
	int	y;

	y = 0;
	while (y < filler->piece.y - 1)
	{
		x = 0;
		while (x < filler->piece.x - 1)
		{
			if (filler->piece.piece[y][x] == '*')
			{
				y_smaller->x = x;
				y_smaller->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	y_smaller->x = -1;
	y_smaller->y = -1;
}

void	find_bigger_y(t_filler *filler, t_point *y_smaller)
{
	int	x;
	int	y;

	y = filler->piece.y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < filler->piece.x - 1)
		{
			if (filler->piece.piece[y][x] == '*')
			{
				y_smaller->x = x;
				y_smaller->y = y;
				return ;
			}
			x++;
		}
		y--;
	}
	y_smaller->x = -1;
	y_smaller->y = -1;
}

int		ft_direction(t_filler *filler, char axe)
{
	t_point smaller;
	t_point bigger;

	if (axe == 'x')
	{
		find_smaller_x(filler, &smaller);
		find_bigger_x(filler, &bigger);
		return (bigger.x - smaller.x);
	}
	find_smaller_y(filler, &smaller);
	find_bigger_y(filler, &bigger);
	return (bigger.y - smaller.y);
}
