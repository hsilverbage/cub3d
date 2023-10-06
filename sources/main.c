/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:24:08 by henrik            #+#    #+#             */
/*   Updated: 2023/10/06 17:34:19 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		ft_error_msg("mlx init failed");	//	NEED TO CHECK NEED FREE STRUCTS
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (!game->win_ptr)
		ft_error_msg("mlx new window failed");	//	NEED TO CHECK NEED FREE STRUCTS
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_error_msg("Wrong number of arguments : ./cub3d maps/map_name.cub");
	ft_bzero(&game, sizeof(game));
	ft_parse_map(&game, argv[1]);
	ft_init_mlx(&game);
	//ft_display_map(&game);
	mlx_hook(game.win_ptr, 17, 1L << 2, ft_close_mlx, &game); //17 = destroy - ft_close ft destroy
	mlx_hook(game.win_ptr, 2, 1L << 0, ft_key_pressed, &game); // 2 = key pressed, ft_moves event if W or if A ..
	mlx_loop(game.mlx_ptr);
	return (0);
}
