/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:53:35 by henrik            #+#    #+#             */
/*   Updated: 2023/10/19 08:04:13 by henrik           ###   ########lyon.fr   */
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
	if (nb_lines < 10)
		ft_error_msg("Missing info in .cub file", game);
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
	game->file = malloc(sizeof(char *) * (nb_lines + 1));
	if (!game->file)
		ft_error_msg("MALLOC", game);
	line = get_next_line(fd);
	while (line)
	{
		game->file[i++] = line;
		line = get_next_line(fd);
	}
	game->file[i] = NULL;
	close(fd);
}

void	ft_check_textures(t_game *game, t_textures *textures)
{
	if (!textures->north)
		ft_error_msg(NO_ERR, game);
	if (!textures->south)
		ft_error_msg(SO_ERR, game);
	if (!textures->west)
		ft_error_msg(WE_ERR, game);
	if (!textures->east)
		ft_error_msg(EA_ERR, game);
	// if (!textures->ceiling)
	// 	ft_error_msg(C_ERR, game);
	// if (!textures->floor)
	// 	ft_error_msg(F_ERR, game);
}

void	ft_get_textures(t_game *game, t_textures *textures)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (game->file[i])
	{
		while (game->file[i][y] == ' ')
			y++;
		if (game->file[i][y] == 'N' && game->file[i][y + 1] == 'O')
			textures->north = ft_extract_path(game->file[i], 'N', 'O', game);
		else if (game->file[i][y] == 'S' && game->file[i][y + 1] == 'O')
			textures->south = ft_extract_path(game->file[i], 'S', 'O', game);
		else if (game->file[i][y] == 'W' && game->file[2][y + 1] == 'E')
			textures->west = ft_extract_path(game->file[i], 'W', 'E', game);
		else if (game->file[i][y] == 'E' && game->file[3][y + 1] == 'A')
			textures->east = ft_extract_path(game->file[i], 'E', 'A', game);
		else if (game->file[i][y] == 'F')
			textures->floor = ft_extract_colors(game->file[i], 'F', textures, game);
		else if (game->file[i][y] == 'C')
			textures->ceiling = ft_extract_colors(game->file[i], 'F', textures, game);
		i++;
		y = 0;
	}
	ft_check_textures(game, textures);
}

void	ft_get_map(t_game *game)
{
	game->map = game->file + 8;
}

void	ft_parse_map(t_game *game, char *argv)
{
	int	nb_lines;

	nb_lines = 0;
	ft_check_extension(argv, game);
	nb_lines = ft_get_nb_lines(nb_lines, argv, game);
	ft_get_file(argv, nb_lines, game);
	ft_get_textures(game, &game->textures);
	printf("%s\n", game->textures.north);
	printf("%s\n", game->textures.south);
	printf("%s\n", game->textures.west);
	printf("%s\n", game->textures.east);
	// // ft_get_map(game);
	// int i = 0;
	// while (game->file[i])
	// 	printf("%s\n", game->file[i++]);
}
