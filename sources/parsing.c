/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:53:35 by henrik            #+#    #+#             */
/*   Updated: 2023/10/09 18:36:47 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_extension(char *str, t_game *game)
{
	int	i;

	i = ft_strlen(str);
	if (!(str[i - 1] == 'b' && str[i - 2] == 'u'
			&& str[i - 3] == 'c' && str[i - 4] == '.'))
	{
		ft_error_msg("Invalid map extension !", game);
	}
}

int	ft_get_nb_lines(int nb_lines, char *argv, t_game *game)
{
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_perror_exit();
	line = get_next_line(fd);
	while (line)
	{
		nb_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!nb_lines)
		ft_error_msg("Map file is empty", game);
	return (nb_lines);
}

void	ft_get_file(char *argv, int nb_lines, t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_perror_exit();
	line = get_next_line(fd);
	game->file = malloc(sizeof(char *) * (nb_lines + 1));
	if (!game->file)
		ft_error_msg("MALLOC", game);
	while (line)
	{
		game->file[i++] = line;
		line = get_next_line(fd);
	}
	game->file[i] = NULL;
	close(fd);
}

void	ft_get_colors(t_game *game, t_textures *textures)
{
	int			i;

	i = 4;
	while (game->file[i])
	{
		if (ft_strlen(game->file[i]) > 3)
		{
			if (game->file[i][0] == 'F')
				textures->floor = game->file[i] + 2;
			if (game->file[i][0] == 'C')
				textures->ceiling = game->file[i] + 2;
		}
		i++;
	}
}

void	ft_check_textures(t_game *game, t_textures *textures)
{
	if (!textures->north)
		ft_error_msg("Missing north texture", game);
	if (!textures->south)
		ft_error_msg("Missing south texture", game);
	if (!textures->west)
		ft_error_msg("Missing west texture", game);
	if (!textures->east)
		ft_error_msg("Missing east texture", game);
	if (!textures->ceiling)
		ft_error_msg("Missing ceiling texture", game);
	if (!textures->floor)
		ft_error_msg("Missing floor texture", game);

}

void	ft_get_textures(t_game *game, t_textures *textures)
{
	int			i;

	i = 0;
	while (game->file[i])
	{
		if (ft_strlen(game->file[i]) > 3)
		{
			if (game->file[i][0] == 'N' && game->file[i][1] == 'O')
				textures->north = game->file[i] + 3;
			else if (game->file[i][0] == 'S' && game->file[i][1] == 'O')
				textures->south = game->file[i] + 3;
			else if (game->file[i][0] == 'W' && game->file[i][1] == 'E')
				textures->west = game->file[i] + 3;
			else if (game->file[i][0] == 'E' && game->file[i][1] == 'A')
				textures->east = game->file[i] + 3;
		}
		i++;
	}
	ft_get_colors(game, textures);
	ft_check_textures(game, textures);
}

void	ft_get_map(t_game *game)
{
	int	i;
	int	y;

	i = 6;
	y = 0;
	while (game->file)
}

void	ft_parse_map(t_game *game, char *argv)
{
	int	nb_lines;

	nb_lines = 0;
	ft_check_extension(argv, game);
	nb_lines = ft_get_nb_lines(nb_lines, argv, game);
	ft_get_file(argv, nb_lines, game);
	ft_get_textures(game, &game->textures);
	ft_get_map(game);
}
