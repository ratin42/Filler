/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 19:03:53 by ratin             #+#    #+#             */
/*   Updated: 2019/04/26 17:05:24 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

static int	get_color(t_party *party, int x, int y)
{
	if (party->map[party->i].image[y][x] == 'X')
		return (P2);
	if (party->map[party->i].image[y][x] == 'x')
		return (NEW);
	if (party->map[party->i].image[y][x] == 'O')
		return (P1);
	if (party->map[party->i].image[y][x] == 'o')
		return (NEW);
	if (party->map[party->i].image[y][x] == '.')
		return (BACKSCREEN);
	return (-1);
}

void		fill_square(t_party *party, t_point corner, int x, int y)
{
	int		i;
	t_point	point1;
	t_point	point2;

	if (x == party->width || y == party->height
	|| party->map[party->i].image[y][x] == '.')
		return ;
	i = 2;
	point1.x = corner.x + 2;
	point2.x = point1.x + party->square_size - 4;
	while (i < party->square_size - 1)
	{
		point1.y = corner.y + i;
		point2.y = point1.y;
		print_lines(&point1, &point2, &party->mlx, get_color(party, x, y));
		i++;
	}
}

void		put_square(t_party *party, t_point corner, int x, int y)
{
	t_point	x_point;
	t_point	y_point;

	x_point.x = corner.x + party->square_size;
	x_point.y = corner.y;
	y_point.x = corner.x;
	y_point.y = corner.y + party->square_size;
	if (x - party->border < party->width)
		print_lines(&corner, &x_point, &party->mlx, 0x000000);
	if (y - party->border < party->height)
		print_lines(&corner, &y_point, &party->mlx, 0x000000);
}

void		draw_board(t_party *party)
{
	int		x;
	int		y;
	t_point	corner;

	y = party->border;
	while (y - party->border <= party->height)
	{
		x = party->border;
		while (x - party->border <= party->width)
		{
			corner.x = x * party->square_size;
			corner.y = y * party->square_size;
			put_square(party, corner, x, y);
			fill_square(party, corner, x - party->border, y - party->border);
			x++;
		}
		y++;
	}
}

int			make_board(t_party *party)
{
	party->square_size = ((WIDTH - (WIDTH / 3)) / party->width);
	party->border = 1;
	draw_board(party);
	return (1);
}
