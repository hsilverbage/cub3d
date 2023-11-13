/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:43:58 by henrik            #+#    #+#             */
/*   Updated: 2023/11/10 01:42:35 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// in extract path, im gonna add, open fd to see if path is valid, else return NULL

#include "cub3d.h"

char	*ft_extract_path(char *str, char c1, char c2, t_game *game)
{
	int	i;
	int	fd;

	i = 0;
	while (str[i] == c1 || str[i] == c2 || str[i] == ' ' || str[i] == '\t')
		i++;
	fd = open(str + i, O_RDONLY);
	if (fd < 0)
	{
		printf("Error : Impossible to access %c%c path\n", c1, c2);
		ft_free_all(game);
		perror(NULL);
		exit (EXIT_FAILURE);
	}
	close(fd);
	return (str + i);
}

bool	ft_check_colors(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ',' || ft_isdigit(str[i]) == 1)
		i++;
	if (str[i] == '\0' || str[i] == '\n')
		return (true);
	else
		return (false);
}

char	*ft_extract_colors(char *str, char c, t_game *game)
{
	int		i;
	char	*color;

	i = 0;
	color = NULL;
	while (str[i] == c || str[i] == ' ' || str[i] == '\t')
		i++;
	if (ft_check_colors(str + i) == false)
		ft_error_msg(COLORS_ERR, game);
	color = str + i;
	return (color);
}

bool	ft_valid_char(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S' || c == 'F' || c == 'C' || c == '\0')
	{
		return (true);
	}
	return (false);
}
