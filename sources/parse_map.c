/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:09:15 by henrik            #+#    #+#             */
/*   Updated: 2023/11/10 01:47:43 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	ft_get_dir(t_game *game)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = 0;
	while (game->map[i])
	{
		while (game->map[i][j] && ft_check_dir_char(game->map[i][j]) == false)
			j++;
		if (game->map[i][j] == '\0')
		{
			j = 0;
			i++;
		}
		else
		{
			ft_init_dir(game->map[i][j], game);
			start += 1;
			j++;
		}
	}
	if (start == 0)
		ft_error_msg("Missing starting position of the player", game);
	if (start > 1)
		ft_error_msg("Multiple starting positions of the player", game);
}

void	ft_parse_map(t_game *game)
{
	ft_check_map_char(game);
	ft_get_dir(game);
	// ft_check_walls(game);
}
