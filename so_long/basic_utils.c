/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:02:45 by ischmutz          #+#    #+#             */
/*   Updated: 2024/01/07 13:40:15 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <mlx.h>

void	error_handler(char *message, t_data data)
{
	int	i;

	ft_printf("ERROR\n");
	ft_printf("%s\n", message);
	if (data.fd != -1)
		close(data.fd);
	if (data.map)
	{
		i = 0;
		while (data.map[i])
			free(data.map[i++]);
		free(data.map);
	}
	if (data.cpy)
	{
		i = 0;
		while (data.cpy[i])
			free(data.cpy[i++]);
		free(data.cpy);
	}
	exit(1);
}

void	free_and_destroy(t_data *data)
{
	int	i;

	i = 0;
	destroy_img(data);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	if (data->map)
	{
		while (data->map[i])
			free(data->map[i++]);
		free(data->map);
	}
	i = 0;
	if (data->cpy)
	{
		while (data->cpy[i])
			free(data->cpy[i++]);
		free(data->cpy);
	}
	if (data->fd != -1)
		close(data->fd);
	exit(1);
}

int	map_copy(t_data *game)
{
	int	height;
	int	width;

	game->cpy = ft_calloc((game->maplen + 1), (sizeof(char *)));
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
			if (game->cpy[i][j] != '1' &&
				game->cpy[i][j] != 'V' && game->cpy[i][j] != '0'
				&& game->cpy[i][j] != 'e')
				error_handler("invalid map: non_viable map", *game);
			j++;
		}
		i++;
	}
}

void	check_char(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' &&
				game->map[i][j] != '0' && game->map[i][j] != 'P'
				&& game->map[i][j] != 'E' && game->map[i][j] != 'C')
				error_handler("invalid map: 10PEC non-compliant", *game);
			j++;
		}
		i++;
	}
}
