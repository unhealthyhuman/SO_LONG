/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:21:37 by ischmutz          #+#    #+#             */
/*   Updated: 2024/01/03 21:16:40 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_linelength(char **map, t_data game)
{
	size_t	i;
	size_t	sample;

	i = 1;
	sample = ft_strlen(map[0]);
	while (map[i] != NULL)
	{
		if (sample != ft_strlen(map[i]))
			error_handler("ivalid map: uneven lines", game);
		i++;
	}
	return (sample);
}

void	check_if_rectangle(char **map, t_data *data)
{
	int	i;

	i = 0;
	data->maplen = 0;
	data->linelen = check_linelength(map, *data);
	while (map[data->maplen] != NULL)
		data->maplen++;
	if (data->maplen == data->linelen)
		error_handler("invalid map: not rectangular", *data);
}

void	check_pe(t_data *game, char **map)
{
	int	i;
	int	j;

	game->p_count = 0;
	game->e_count = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				game->p_count++;
			else if (map[i][j] == 'E')
				game->e_count++;
			j++;
		}
		i++;
	}
	if (game->p_count == 0 || game->e_count == 0)
		error_handler("invalid map: no player/exit", *game);
	else if (game->p_count > 1 || game->e_count > 1)
		error_handler("invalid map: too many players/exits", *game);
}

void	check_collectible(t_data *game, char **map)
{
	int	i;
	int	j;

	game->c_count = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				game->c_count++;
			j++;
		}
		i++;
	}
	if (game->c_count == 0)
		error_handler("invalid map: no collectibles", *game);
}

void	check_walls(char **map, t_data *data)
{
	data->i = 0;
	while (map[0][data->i])
	{
		if (map[0][data->i] != '1')
			error_handler("invalid map: invalid walls1", *data);
		if (map[data->maplen - 1][data->i] != '1')
			error_handler("invalid map: invalid walls2", *data);
		data->i++;
	}
	data->i = 1;
	data->j = 0;
	while (map[data->i] != NULL)
	{
		if (map[data->i][0] != '1')
			error_handler("invalid map: invalid walls3", *data);
		if (map[data->i][data->linelen - 1] != '1')
			error_handler("invalid map: invalid walls4", *data);
		data->i++;
	}
}
