/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:07:52 by ratin             #+#    #+#             */
/*   Updated: 2019/04/17 17:57:47 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			print_line(char *str)
{
	int			fd;

	fd = new_file();
	dprintf(fd, "line = %s\n", str);
}

void			print_file_info(t_filler *filler)
{
	print_info(filler, filler->fd);
}

int				new_file(void)
{
	int			fd;

	fd = open("test.txt", O_APPEND| O_CREAT | O_WRONLY, 0777);
	return (fd);
}

int				print_map(t_filler *filler, int fd)
{
	int			x;
	int			y;

	y = 0;
	dprintf(fd, "map = \n");
	dprintf(fd, "    01234567890123456\n");
	while (filler->map[y] != 0)
	{
		x = 0;
		dprintf(fd, "%03d ", y);
		while (filler->map[y][x])
		{
			dprintf(fd, "%c", filler->map[y][x]);
			x++;
		}
		dprintf(fd, "\n");
		y++;
	}
	dprintf(fd, "    01234567890123456\n");
	dprintf(fd, "\n");
	return (1);
}

void			print_piece(t_filler *filler, int fd)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (filler->piece.piece[i] != '\0')
	{
		while (filler->piece.piece[i][y] != '\0')
		{
			dprintf(fd, "%c", filler->piece.piece[i][y]);
			y++;
		}
		y = 0;
		i++;
		dprintf(fd, "\n");
	}
}

void			print_territory(int fd, t_territory *territory)
{
	int			i;

	i = 0;
	while (i < territory->nbr_of_pion)
	{
		dprintf(fd, "pour piece %d ", i);
		dprintf(fd, " | coef = %d ", territory->territory[i].coef);
		dprintf(fd, "{%d, %d}\n", territory->territory[i].y, territory->territory[i].x);
		i++;
	}
}

void			print_piece_territory(int fd, t_piece *piece)
{
	int			i;

	i = 0;
	while (i < piece->x * piece->y)
	{
		dprintf(fd, "{%d, %d}\n", piece->all_piece[i].y, piece->all_piece[i].x);
		i++;
	}
}

void			print_info(t_filler *filler, int fd)
{
	print_map(filler, fd);
 	dprintf(fd, "filler player = %d\n", filler->player);
	dprintf(fd, "filler size height = %d\n", filler->map_height);
	dprintf(fd, "filler size width = %d\n", filler->map_width);
	dprintf(fd, "filler piece x = %d\n", filler->piece.x);
	dprintf(fd, "filler piece y = %d\n", filler->piece.y);
	dprintf(fd, "piece = \n");
	print_piece(filler, fd);
	dprintf(fd, "\npiece territory = \n");
	print_piece_territory(fd, &filler->piece);
	dprintf(fd, "\nmy territory %c = \n", filler->my_territory.color);
	print_territory(fd, &filler->my_territory);
/* 	dprintf(fd, "\nennemy territory = \n");
	print_territory(fd, &filler->en_territory); */
	dprintf(fd, "\n");
	dprintf(fd, "my closest pion is {%d, %d} whith {%d, %d} ennemy pion\n"
	, filler->closest.my.y, filler->closest.my.x, filler->closest.en.y, filler->closest.en.x);
	dprintf(fd, "\n");
}
