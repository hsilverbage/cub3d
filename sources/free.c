/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 01:34:59 by henrik            #+#    #+#             */
/*   Updated: 2023/10/06 17:35:28 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_all(t_game *game)
{
	int	i;

	i = 0;
	if (game->file)
	{
		while (game->file[i])
			free(game->file[i++]);
		free(game->file);
	}
}

int	ft_close_mlx(t_game *game)
{
	ft_free_all(game);
	if (game->mlx_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	// mlx_destroy_display(game->mlx_ptr); //DOESNT WORK IF MAC
	free(game->mlx_ptr);
	exit(0);
	return (0);
}
