/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:47:48 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/22 12:47:57 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    map_renderer(t_data *game)
{
    int i;
    int j;

    game->floor = mlx_xpm_file_to_image(game->mlx_ptr, "textures/floor.xpm", &i, &j);
    game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "textures/wall.xpm", &i, &j);
    game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "textures/exit.xpm", &i, &j);
    game->coins = mlx_xpm_file_to_image(game->mlx_ptr, "textures/coins.xpm", &i, &j);
    game->player = mlx_xpm_file_to_image(game->mlx_ptr, "textures/charizard.xpm", &i, &j);
}

