/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:53:09 by henrik            #+#    #+#             */
/*   Updated: 2023/10/09 18:34:46 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_display(t_game *game)
{
	int		x;
	int		y;

	x = 500;
	y = 500;
	while (x < 564)
	{
		mlx_pixel_put (game->mlx_ptr , game->win_ptr, y, x, 0xFFFFFF);
		while (y < 564)
		{
			mlx_pixel_put (game->mlx_ptr , game->win_ptr, y, x, 0xFFFFFF);
			y++;
		}
		x++;
		y = 500;
	}
}
