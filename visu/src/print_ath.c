/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:56:06 by ratin             #+#    #+#             */
/*   Updated: 2019/04/26 17:12:53 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

void		print_menu(t_party *party)
{
	int		width;
	int		height;

	width = (WIDTH / 3 * 2) + (WIDTH / 13);
	height = party->square_size * 2;
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, width, height
	, 0x000000, "SPACE : PAUSE");
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, width, height + 20
	, 0x000000, "  <-  : RECULER");
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, width, height + 40
	, 0x000000, "  ->  : AVANCER");
}

void		print_p2(t_party *party, int width, int height)
{
	char	*p2_pion;

	p2_pion = ft_itoa(party->p2.score[party->i]);
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr
	, width + 500, height + 40, P2, "Player 2: ");
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, width + 600
	, height + 40, P2, party->p2.name);
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, width + 600
	+ ft_strlen(party->p2.name) * 11, height + 40, P2, p2_pion);
	free(p2_pion);
}

void		print_player(t_party *party)
{
	int		width;
	int		height;
	char	*p1_pion;

	p1_pion = ft_itoa(party->p1.score[party->i]);
	width = party->square_size + party->width / 2;
	height = party->square_size * (party->height + 1);
	if (party->p2.name != 0)
		print_p2(party, width, height);
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, width, height + 40
	, P1, "Player 1: ");
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, width + 100, height
	+ 40, P1, party->p1.name);
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, width + 100
	+ ft_strlen(party->p1.name) * 11, height + 40, P1, p1_pion);
	free(p1_pion);
}

void		print_score(t_party *party)
{
	int		height;

	height = party->square_size * (party->height + 3);
	if (party->p2.name != 0)
	{
		if (party->p1.score[party->turn - 1] > party->p2.score[party->turn - 1])
		{
			mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, WIDTH / 3
			, height, P1, "Player 1: ");
			mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, WIDTH / 3
			+ 100, height, P1, party->p1.name);
			mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, WIDTH / 3
			+ 100 + ft_strlen(party->p1.name) * 11, height, 0xFFF700, "WIN");
		}
		else
		{
			mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, WIDTH / 3
			, height, P2, "Player 2: ");
			mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, WIDTH / 3
			+ 100, height, P2, party->p2.name);
			mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, WIDTH / 3
			+ 100 + ft_strlen(party->p1.name) * 11, height, 0xFFF700, "WIN");
		}
	}
}

int			print_ath(t_party *party)
{
	if (party->i == party->turn - 1)
		party->finished = 1;
	print_menu(party);
	print_player(party);
	if (party->finished == 1)
		print_score(party);
	return (0);
}
