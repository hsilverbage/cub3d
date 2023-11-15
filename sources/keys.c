/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:54:49 by hsilverb          #+#    #+#             */
/*   Updated: 2023/11/15 04:07:27 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_moves(t_game *game, int key)
{
	// printf("players old x = %f old y = %f\n", game->player.x, game->player.y);
	if (key == W)
	{
		game->player.y -= MOVE_SPEED;
		ft_display(game);
	}
	if (key == S)
	{
		game->player.y += MOVE_SPEED;
		ft_display(game);
	}
	if (key == A)
	{
		game->player.x -= MOVE_SPEED;
		ft_display(game);
	}
	if (key == D)
	{
		game->player.x += MOVE_SPEED;
		ft_display(game);
	}
	// printf("players new x = %f new y = %f\n", game->player.x, game->player.y);
}

int	ft_key_pressed(int key, t_game *game)
{
	if (key == ESC)
		ft_close_mlx(game);
	else if (key == W || key == S || key == A || key == D)
		ft_moves(game, key);
	return (key);
}
