/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:40:21 by ratin             #+#    #+#             */
/*   Updated: 2019/04/19 16:32:01 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H
# define WIDTH 1080
# define HEIGHT 720
# include <mlx.h>
# include <X.h>
# include <stdlib.h>
# include "../../libft/includes/libft.h"
# include <fcntl.h>

# include <stdio.h>

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
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_mlx;

typedef	struct	s_pion
{
	int			x;
	int			y;
	int			coef;
}				t_pion;

typedef	struct	s_piece
{
	int			x;
	int			y;
	char		axe;
	char		**piece;
	int			i;
	int			piece_free;
	int			contact;
	t_pion		first_pion;
	t_pion		*all_piece;
}				t_piece;

typedef	struct	s_territory
{
	int			nbr_of_pion;
	char		color;
	t_pion		*territory;
}				t_territory;

typedef	struct	s_closest
{
	int			coef;
	t_pion		my;
	t_pion		en;
}				t_closest;

typedef	struct	s_filler
{
	int			fd;
	char		**map;
	int			player;
	int			map_free;
	int			map_width;
	int			map_height;
	int			fin;
	int			gotop;
	int			turn;
	char		pion;
	t_territory	my_territory;
	t_territory	en_territory;
	t_piece		piece;
	t_closest	closest;
}				t_filler;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

int			init_mlx(t_mlx *mlx);
int			get_game(t_filler *filler);
int			quit_fdf(void *mlx);
int			draw(void *mlx, t_filler *filler);

#endif