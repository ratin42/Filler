/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <Raphael@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 20:07:35 by Raphael           #+#    #+#             */
/*   Updated: 2019/04/21 20:42:28 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

char    *get_player_name(t_game *game, int player)
{

}

int     init_game(t_game *game)
{
    game->turn = 0;
    game->p1.name = get_player_name(game, 1);
    return (1);
}