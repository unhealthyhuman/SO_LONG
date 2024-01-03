/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:47:48 by ischmutz          #+#    #+#             */
/*   Updated: 2024/01/03 16:58:57 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

//check if protected
void	img_into_struct(t_data *game)
{
	int	w;
	int	h;

	game->floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/floor.xpm", &w, &h);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/wall.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/exit.xpm", &w, &h);
	game->coins = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/coins.xpm", &w, &h);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/charizard.xpm", &w, &h);
}

//&w = ptr to width. f(x) stores width of img in w. 
//&h = ptr to height. f(x) stores height of img in h.
//segfault was bc called mlx innit after using this
//so game->mlx_ptr caused segfault

void	place_player(t_data *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->player, width * 50, height * 50);
}

void	put_img(t_data *game, int height, int width)
{
	if (game->map[height][width] == '1')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->wall, width * 50, height * 50);
	else if (game->map[height][width] == '0')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->floor, width * 50, height * 50);
	else if (game->map[height][width] == 'C')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->coins, width * 50, height * 50);
	else if (game->map[height][width] == 'E')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->exit, width * 50, height * 50);
	else if (game->map[height][width] == 'P')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->player, width * 50, height * 50);
}

void	img_into_win(t_data *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->maplen)
	{
		width = 0;
		while (game->map[height][width])
		{
			put_img(game, height, width);
			width++;
		}
		height++;
	}
}
