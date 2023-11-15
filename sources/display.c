/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:53:09 by henrik            #+#    #+#             */
/*   Updated: 2023/11/15 04:00:44 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_box(t_game *game, int x, int y, int color, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (j % size != 0 && i % size!= 0)
				mlx_pixel_put(game->mlx_ptr , game->win_ptr, y * size + j, x * size + i, color);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_display_player(t_game *game, double y, double x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= 5)
	{
		while (j <= 5)
		{
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, x * 64 + i + 30, y * 64 + j + 30, 0x0000FF);
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
				ft_draw_box(game, y, x, 0xFF0000, 64);
			else
				ft_draw_box(game, y, x, 0x00FF00, 64);
			x++;
		}
		x = 0;
		y++;
	}
}

int	ft_display(t_game *game)
{
	ft_display_map(game);
	ft_display_player(game, game->player.y, game->player.x);
	game->img_ptr =  mlx_new_image(game->mlx_ptr, game->width, game->height);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_ptr, 0, 0);
	mlx_destroy_image(game->mlx_ptr, game->img_ptr);
	return (0);
}
