/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:26:49 by ischmutz          #+#    #+#             */
/*   Updated: 2024/01/02 19:04:06 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/printf/ft_printf.h"
#include "so_long.h"

int	check_open(char *file)
{
	int	fd;
	int	i;
	int	j;

	fd = 0;
	i = 0;
	j = 0;
	while (file[i])
		i++;
	i--;
	if (file[i - 3] != '.' && file[i - 2] != 'b' && file[i - 2] != 'e' \
		&& file[i - 2] != 'r')
		error_handler("invalid map filename");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_handler("wrong user permissions");
	return (fd);
}

char	**read_map(int fd)
{
	char	*readline;
	char	*full_line;
	char	*buffer;
	char	**map;

	readline = get_next_line(fd);
	full_line = NULL;
	while (readline != NULL)
	{
		//ft_printf("readline %s\n", readline);
		buffer = full_line;
		full_line = ft_strjoin(full_line, readline);
		free(buffer);
		//ft_printf("full_line %s\n", full_line);
		free (readline);
		if (full_line == NULL)
			error_handler("strjoin failed"); // fd leak
		readline = get_next_line(fd);
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
	while(height < game->maplen)
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
	if (game->map[y_pos + 1][x_pos] == '1' && game->map[y_pos - 1][x_pos] == '1' &&
		game->map[y_pos][x_pos + 1] == '1' && game->map[y_pos][x_pos - 1] == '1')
		error_handler("invalid map: player surrounded by walls");
}

void	master_check(char *argv1, t_data *data)
{
	data->fd = check_open(argv1);
	//read_map(data);
	data->map = read_map(data->fd);
	check_if_rectangle(data->map, data);
	check_pe(data, data->map);
	check_collectible(data, data->map);
	check_walls(data->map, data);
	p_surrounded(data);
	flood_map(data);
}

/* void	movement_restrictions(t_data *data)
{
	//if all collectibles have been collected and exit == 1
	//	return valid map
	//if on wall
	// return invalid map
	//on collectables
	//	collectables++;
	//on exit
	//	exits BUT ONLY IF ALL COLLECTIBLES HAVE BEEN COLLECTED
	//replace current position with wall
	//if one of the four adjacent directions is possible
	// return map valid
	//return map invalid
} */

/* void	read_map(t_data *game)
{
	char	*readline;
	char	*full_line;

	readline = get_next_line(game->fd);
	full_line = NULL;
	while (readline != NULL)
	{
		//ft_printf("readline %s\n", readline);
		full_line = ft_strjoin_gnl(full_line, readline);
		//ft_printf("full_line %s\n", full_line);
		if (full_line == NULL)
			error_handler("strjoin failed");
		free (readline);
		readline = get_next_line(game->fd);
	}
	game->map = ft_split(full_line, '\n');
} */