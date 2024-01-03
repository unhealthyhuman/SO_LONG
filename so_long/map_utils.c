/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:26:49 by ischmutz          #+#    #+#             */
/*   Updated: 2024/01/03 17:00:58 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/printf/ft_printf.h"
#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

void	check_open(char *file, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (file[i])
		i++;
	i--;
	if (i < 4 || (file[i - 3] != '.' && file[i - 2] != 'b'
			&& file[i - 1] != 'e' && file[i] != 'r'))
		error_handler("invalid map filename", *data);
	data->fd = open(file, O_RDONLY);
	if (data->fd == -1)
		error_handler("wrong user permissions", *data);
}

char	**read_map(t_data *game)
{
	char	*readline;
	char	*full_line;
	char	*buffer;
	char	**map;

	readline = get_next_line(game->fd);
	if (readline == NULL)
		error_handler("invalid read", *game);
	full_line = NULL;
	while (readline != NULL)
	{
		buffer = full_line;
		full_line = ft_strjoin(full_line, readline);
		free(buffer);
		free (readline);
		if (full_line == NULL)
			error_handler("strjoin failed", *game);  // fd leak (maybe fixed it, check again)
		readline = get_next_line(game->fd);
	}
	map = ft_split(full_line, '\n');
	free(full_line);
	return (map);
}

void	find_player_pos(t_data *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->maplen)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == 'P')
			{
				game->px_pos = width;
				game->py_pos = height;
			}
			width++;
		}
		height++;
	}
}

void	p_surrounded(t_data *game)
{
	int	x_pos;
	int	y_pos;

	find_player_pos(game);
	x_pos = game->px_pos;
	y_pos = game->py_pos;
	if (game->map[y_pos + 1][x_pos] == '1' && game->map[y_pos - 1][x_pos] == '1'
	&& game->map[y_pos][x_pos + 1] == '1' && game->map[y_pos][x_pos - 1] == '1')
		error_handler("invalid map: player surrounded by walls", *game);
}

void	master_check(char *argv1, t_data *data)
{
	check_open(argv1, data);
	data->map = read_map(data);
	check_if_rectangle(data->map, data);
	check_char(data);
	check_pe(data, data->map);
	check_collectible(data, data->map);
	check_walls(data->map, data);
	p_surrounded(data);
	flood_map(data);
}
