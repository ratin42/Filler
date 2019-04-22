/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <Raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:40:21 by ratin             #+#    #+#             */
/*   Updated: 2019/04/21 20:41:39 by Raphael          ###   ########.fr       */
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

typedef	struct	s_player
{
	int			number;
	char		color;
	int			nbr_pion;
	char		*name;
}				t_player;

typedef	struct	s_map
{
	char		**image;
	int			width;
	int			height;
}				t_map;

typedef	struct	s_piece
{
	char		**image;
	int			width;
	int			height;
}				t_piece;

typedef struct	s_game
{
	int			turn;
	t_player	p1;
	t_player	p2;
	t_map		*map;
}				t_game;


int			init_mlx(t_mlx *mlx);
int			parse_game(t_game *game);
int			quit_fdf(void *mlx);
int			draw(void *mlx, t_game *game);

#endif