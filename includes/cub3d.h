/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:20:22 by henrik            #+#    #+#             */
/*   Updated: 2023/11/13 15:33:40 by henrik           ###   ########lyon.fr   */
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
# include "stdbool.h"

# define WIDTH 1080
# define HEIGHT 780

# define BLUE 250
# define RED 500
# define GREEN

# define MALLOC "Malloc was unsuccessful"
# define ERR_ARG "Wrong number of arguments : ./cub3d maps/map_name.cub"
# define NO_ERR "North texture : NO ./path_to_the_north_texture"
# define SO_ERR "South texture : SO ./path_to_the_south_texture"
# define EA_ERR "East texture : EA ./path_to_the_east_texture"
# define WE_ERR "West texture : WE ./path_to_the_west_texture"
# define F_ERR "Floor color, R,G,B colors in range [0,255] : F 220,100,0"
# define C_ERR "Ceiling color, R,G,B colors in range [0,255] : C 220,100,0"
# define COLORS_ERR "R,G,B colors in range [0,255] : C 220,100,0 / F 220,100,0"

typedef struct s_player
{
	double		x;	// EAST - WEST / VERTICAL
	double		y;	// SO - NO /HORIZONTAL
	double		dir;
}				t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	char		**file;
	int			height;
	int			width;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*ceiling;
	char		*floor;
	t_player	player;
}				t_game;

void	ft_init_map(t_game *game, char *argv);

//	ERROR

void	ft_error_msg(char *str, t_game *game);
void	ft_perror_exit(void);

//	FREE

void	ft_free_all(t_game *game);
int		ft_close_mlx(t_game *game);
//KEYS

int	ft_key_pressed(int key, t_game *game);

//DISPLAY

void	ft_display(t_game *game);
void	ft_display_player(t_game *game, double y, double x);

// PARSING UTILS


char	*ft_extract_path(char *str, char c1, char c2, t_game *game);
char	*ft_extract_colors(char *str, char c, t_game *game);
bool	ft_valid_char(char c);
bool	ft_valid_map_char(char c);
bool	ft_check_dir_char(char c);
void	ft_init_dir(char c, t_game *game);

// PARSING MAP

void	ft_parse_map(t_game *game);

#endif
