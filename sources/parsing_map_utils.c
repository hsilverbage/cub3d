/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 01:16:27 by henrik            #+#    #+#             */
/*   Updated: 2023/11/13 15:53:30 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_valid_pos_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

void	ft_init_dir(char c, t_game *game)
{
	if (c == 'N')
		game->player.dir = 0;
	else if (c == 'S')
		game->player.dir = 180;
	else if (c == 'E')
		game->player.dir = 270;
	else if (c == 'W')
		game->player.dir = 90;
}

bool	ft_valid_map_char(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S' || c == '0' || c == '1' || c == ' ')
		return (true);
	return (false);
}
