/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:53:35 by henrik            #+#    #+#             */
/*   Updated: 2023/10/10 02:18:17 by henrik           ###   ########lyon.fr   */
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
	if (nb_lines < 11)
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

void	ft_check_textures(t_game *game, t_textures *textures)
{
	if (!textures->north || !textures->south || !textures->west || \
		!textures->east || !textures->ceiling || !textures->floor || \
		game->file[4][0] != '\0' || game->file[7][0] != '\0')
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Wrong file format, strict order such as :\n", 2);
		ft_putstr_fd(FILE_ERR, STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
}

void	ft_get_textures(t_game *game, t_textures *textures)
{
	char	**file;

	file = game->file;
	if (file[0][0] == 'N' && file[0][1] == 'O' && ft_strlen(file[0]) > 3)
		textures->north = file[0] + 3;
	if (file[1][0] == 'S' && file[1][1] == 'O' && ft_strlen(file[0]) > 3)
		textures->south = file[1] + 3;
	if (file[2][0] == 'W' && file[2][1] == 'E' && ft_strlen(file[0]) > 3)
		textures->west = file[2] + 3;
	if (file[3][0] == 'E' && file[3][1] == 'A' && ft_strlen(file[0]) > 3)
		textures->east = file[3] + 3;
	if (file[5][0] == 'F' && ft_strlen(file[0]) > 2)
			textures->floor = file[5] + 2;
	if (file[6][0] == 'C' && ft_strlen(file[0]) > 2)
			textures->ceiling = file[6] + 2;
	ft_check_textures(game, textures);
}

void	ft_get_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->file[8][i] == '\0')
	{
		ft_free_all(game);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Wrong format file .cub, strict order such as :\n", 2);
		ft_putstr_fd(FILE_ERR, STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	game->map = game->file + 8;
	i = 0;
	while (game->map[i])
		printf("%s\n", game->map[i++]);
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
