/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:53:09 by henrik            #+#    #+#             */
/*   Updated: 2023/10/10 03:04:33 by henrik           ###   ########lyon.fr   */
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
	while (i < 64)
	{
		while (j < 64)
		{
			mlx_pixel_put(game->mlx_ptr , game->win_ptr, y * 64 + j, x * 64 + i, color);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_display(t_game *game)
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
			else if (game->map[y][x] == 'N')
				ft_draw_box(game, y, x, 0x0000FF);
			x++;
		}
		x = 0;
		y++;
	}
}
