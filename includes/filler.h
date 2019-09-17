/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 02:27:18 by ratin             #+#    #+#             */
/*   Updated: 2019/05/10 02:44:37 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"

typedef	struct	s_pion
{
	int			x;
	int			y;
	int			coef;
}				t_pion;

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

/*
** get_info
*/

int				get_env(t_filler *filler);
int				get_piece(t_filler *filler);
int				ft_place_piece(t_filler *filler);
int				ft_direction(t_filler *filler, char axe);
int				qg_scan_territory(t_filler *filler);
int				get_pion(t_filler *filler, t_territory *territory);
int				get_piece_cordo(t_filler *filler);
int				get_player(t_filler *filler);
int				gofar(t_filler *filler);
int				touch_top(t_filler *filler);
int				calc_coef(t_filler *filler, int i);
void			give_coef_botom(t_filler *filler);
void			give_coef_gotop_right(t_filler *filler);
void			give_coef_gotop_left(t_filler *filler);
void			give_coef_closest(t_filler *filler);
void			find_closest(t_filler *filler);
void			sort_closet(t_filler *filler);
void			sort_pion(t_filler *filler, t_pion *tab);
void			put_place(t_filler *filler, int x, int y);
t_pion			found_piece_posi(t_filler *filler, int x, int y);
t_pion			found_piece_posineg(t_filler *filler, int x, int y);
t_pion			found_place(t_filler *filler);

/*
** free_tab
*/
void			free_double_int(int **array, int size);
void			free_double_char(char **array, int size);
void			free_three_dimension(int ***array, int size_1, int size_2);

/*
** env
*/

void			init_env(t_filler *filler);
void			free_env(t_filler *filler);
int				sertif_map(t_filler *filler);
int				bad_map(void);

#endif
