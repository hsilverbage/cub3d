/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:00:46 by henrik            #+#    #+#             */
/*   Updated: 2023/10/10 01:38:39 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error_msg(char *str, t_game *game)
{
	ft_free_all(game);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
	exit (EXIT_FAILURE);
}

void	ft_perror_exit(void)
{
	perror("Error ");
	exit(EXIT_FAILURE);
}
