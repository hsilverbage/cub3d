/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:53:09 by henrik            #+#    #+#             */
/*   Updated: 2023/10/10 19:07:30 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	ft_display(t_game *game)
// {
// 	int		x;
// 	int		y;

// 	x = 500;
// 	y = 500;
// 	while (x < 564)
// 	{
// 		mlx_pixel_put (game->mlx_ptr , game->win_ptr, y, x, 0xFFFFFF);
// 		while (y < 564)
// 		{
// 			mlx_pixel_put (game->mlx_ptr , game->win_ptr, y, x, 0xFFFFFF);
// 			y++;
// 		}
// 		x++;
// 		y = 500;
// 	}
// }

void	ft_draw_box(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 32)
	{
		while (j < 32)
		{
			mlx_pixel_put(game->mlx_ptr , game->win_ptr, y * 32 + j, x * 32 + i, color);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_display_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				ft_draw_box(game, y, x, 0xFF0000);
			else if (game->map[y][x] == '0')
				ft_draw_box(game, y, x, 0x00FF00);
			else if (game->map[y][x] == 'N' || game->map[y][x] == 'E' || game->map[y][x] == 'W' || game->map[y][x] == 'S')
			{
				game->player.y = y;
				game->player.x = x;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_display_player(t_game *game, double y, double x)
{
	ft_draw_box(game, y, x, 0x0000FF);
}

void	ft_display(t_game *game)
{
	ft_display_map(game);
	ft_display_player(game, game->player.y, game->player.x);
}
