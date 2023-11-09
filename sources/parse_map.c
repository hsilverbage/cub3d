/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:09:15 by henrik            #+#    #+#             */
/*   Updated: 2023/11/10 00:47:35 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	ft_check_walls(t_game *game)
// {
// 	int		i;

// 	i = 0;
// 	while (game->map[i])
// 	{

// 		i++;
// 	}
// }

void	ft_check_map_char(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (ft_valid_map_char(game->map[i][j]) == false)
				return (ft_error_msg("Invalid map char", game));
			j++;
		}
		if (game->map[i][j] != '\0')
			return (ft_error_msg("Invalid map char", game));
		i++;
		j = 0;
		if (game->map[i] && game->map[i][j] == '\0')
		{
			while (game->map[i] && game->map[i][j] == '\0')
				i++;
			if (game->map[i])
				return (ft_error_msg("Invalid map char", game));
		}
	}
}

void	ft_parse_map(t_game *game)
{
	ft_check_map_char(game);
	// ft_check_walls(game);
}
