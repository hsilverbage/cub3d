/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:20:22 by henrik            #+#    #+#             */
/*   Updated: 2023/10/05 19:02:10 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifdef __APPLE__
#  include "../mlx/mlx.h"
# elif __linux__
#  include "../mlx_linux/mlx.h"
# endif

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "var.h"

# define WIN_WIDTH 1080
# define WIN_HEIGHT 780

# define MALLOC "Malloc was unsuccessful"

typedef struct s_player
{
	int		x;	// EAST - WEST / VERTICAL
	int		y;	// SO - NO /HORIZONTAL
	int		z;	// HEIHGT - 3D
}				t_player;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}			t_textures;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	char		**file;
	int			height;
	int			width;
	t_player	player;
	t_textures	textures;
}				t_game;

void	ft_parse_map(t_game *game, char *argv);

//	ERROR

void	ft_error_msg(char *str);
void	ft_perror_exit(void);

//	FREE

void	ft_free_all(t_game *game);
int		ft_close_mlx(t_game *game);
//KEYS

int	ft_key_pressed(int key, t_game *game);


#endif
