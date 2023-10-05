/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:53:35 by henrik            #+#    #+#             */
/*   Updated: 2023/10/04 01:50:57 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_extension(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (!(str[i - 1] == 'b' && str[i - 2] == 'u'
			&& str[i - 3] == 'c' && str[i - 4] == '.'))
	{
		ft_error_msg("Invalid map extension !");
	}
}

int	ft_get_nb_lines(int nb_lines, char *argv)
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
		ft_error_msg("Map file is empty");
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
		ft_error_msg("MALLOC");
	while (line)
	{
		game->file[i++] = line;
		line = get_next_line(fd);
	}
	game->file[i] = NULL;
	close(fd);
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
}

void	ft_parse_map(t_game *game, char *argv)
{
	int	nb_lines;

	nb_lines = 0;
	ft_check_extension(argv);
	nb_lines = ft_get_nb_lines(nb_lines, argv);
	ft_get_file(argv, nb_lines, game); // GAME->FILE MALLOCKED
	ft_get_textures(game, &game->textures);
}
