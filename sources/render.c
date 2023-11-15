/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:17:30 by henrik            #+#    #+#             */
/*   Updated: 2023/11/13 16:19:31 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
> when i move
>
> - tout dans une image en utilsant mlx_new_image
> - garder l'adress de l'image grace a la function get add_data_address
> - mlx_clear window
> - mlx_put_image_to_window
> -	mlx_destroy_image

*/

void	ft_render(t_game *game)
{
	mlx_new_image(game->mlx, game->width, game->height, &game->image.addr);
}
