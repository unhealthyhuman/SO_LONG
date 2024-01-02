/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:02:45 by ischmutz          #+#    #+#             */
/*   Updated: 2024/01/02 22:14:15 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	error_handler(char *message)
{
	ft_printf("ERROR\n");
	ft_printf("%s\n", message);
	exit(1);
}

void	free_and_destroy(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_image(data->mlx_ptr, data->floor);
	mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_image(data->mlx_ptr, data->player);
	mlx_destroy_image(data->mlx_ptr, data->exit);
	mlx_destroy_image(data->mlx_ptr, data->coins);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
	exit(1);
}

int	map_copy(t_data *game)
{
	int	height;
	int	width;

	game->cpy = ft_calloc(game->maplen, (sizeof(char *)));
	if (!game->cpy)
		return (0);
	height = 0;
	while (height < game->maplen)
	{
		game->cpy[height] = ft_calloc((game->linelen + 1), (sizeof(char)));
		if (!game->cpy[height])
			return (0);
		width = 0;
		while (game->map[height][width])
		{
			game->cpy[height][width] = game->map[height][width];
			width++;
		}
		game->cpy[height][width] = '\0';
		height++;
	}
	game->cpy[height] = NULL;
	return (1);
}

void	check_map(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->cpy[i])
	{
		j = 0;
		while (game->cpy[i][j])
		{
			if (game->cpy[i][j] != '1' || game->cpy[i][j] != 'V')
				error_handler("invalid map: non_viable map");
			j++;
		}
		i++;
	}
}
