/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:40:21 by ratin             #+#    #+#             */
/*   Updated: 2019/04/30 19:07:12 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H
# include <mlx.h>
# include <X.h>
# include <stdlib.h>
# include "../../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# define WIDTH 1080
# define HEIGHT 1020
# define BACKSCREEN 0x51556C
# define P1 0x4B7FD8
# define NEW 0xFF0000
# define P2 0xD84BD8

typedef	struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef	struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_mlx;

typedef	struct	s_player
{
	char		*name;
	int			*score;
}				t_player;

typedef	struct	s_map
{
	char		**image;
}				t_map;

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			dp;
	int			delta_e;
	int			delta_ne;
}				t_line;

typedef struct	s_party
{
	int			turn;
	int			i;
	int			width;
	int			height;
	int			square_size;
	int			border;
	int			pause;
	int			finished;
	t_player	p1;
	t_player	p2;
	t_map		*map;
	t_mlx		mlx;
	char		*image;
}				t_party;

int				quit_fdf(t_party *party);
int				draw(t_party *party);
int				give_color(t_mlx *mlx);
void			get_info(t_party *party);
int				init_mlx(t_party *party);
int				print_ath(t_party *party);
int				init_game(t_party *party);
void			free_prog(t_party *party);
int				make_board(t_party *party);
int				parse_game(t_party *party);
void			get_player(t_party *party);
int				give_map_memory(t_party *party);
void			print_party_map(t_party *party);
int				handle_key(int key, t_party *party);
void			get_score(t_party *party, int turn);
int				ft_put_pixel(t_mlx *mlx, int x, int y, int color);
int				put_line(t_point *point1, t_point *point2, t_mlx *mlx
				, int color);
int				print_lines(t_point *point1, t_point *point2, t_mlx *mlx
				, int color);
void			vertical_limit(t_point *point1, t_point *point2, t_mlx *mlx
				, int color);

#endif
