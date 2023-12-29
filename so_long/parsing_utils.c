/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:21:37 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/29 14:18:57 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_linelength(char **map)
{
	size_t	i;
	size_t	sample;

	i = 1;
	sample = ft_strlen(map[0]);
	while (map[i] != NULL)
	{
		if (sample != ft_strlen(map[i]))
			error_handler("ivalid map: uneven lines");
		i++;
	}
	return (sample);
}

void	check_if_rectangle(char **map, t_data *data)
{
	int	i;

	i = 0;
	data->maplen = 0;
	data->linelen = check_linelength(map);
	while (map[data->maplen] != NULL)
		data->maplen++;
	if (data->maplen == data->linelen)
		error_handler("invalid map: not rectangular");
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
		error_handler("invalid map: no player/exit");
	else if (game->p_count > 1 || game->e_count > 1)
		error_handler("invalid map: too many players/exits");
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
		error_handler("invalid map: no collectibles");
}

void	check_walls(char **map, t_data *data)
{
	data->i = 0;
	while (map[0][data->i])
	{
		if (map[0][data->i] != '1')
			error_handler("invalid map: invalid walls1");
		if (map[data->maplen - 1][data->i] != '1')
			error_handler("invalid map: invalid walls2");
		data->i++;
	}
	data->i = 1;
	data->j = 0;
	while(map[data->i] != NULL)
	{
		if (map[data->i][0] != '1')
			error_handler("invalid map: invalid walls3");
		if (map[data->i][data->linelen - 1] != '1')
			error_handler("invalid map: invalid walls4");
		data->i++;
	}
}
	
	// while (map[data->i] != NULL)
	// {
	// 	data->j = 0;
	// 	if (data->i == 0 || data->i == data->vlen)
	// 	{
	// 		while (map[data->i][data->j])
	// 		{
	// 			if (map[data->i][data->j] != '1')
	// 				error_handler("invalid map: invalid walls");
	// 			data->j++;
	// 		}
	// 	}
	// 	while (map[data->i][data->j])
	// 	{
	// 		if ((data->j == 0 || data->j == data->hlen) \
	// 		&& map[data->i][data->j] != '1')
	// 			error_handler("invalid map: invalid walls");
	// 	}
	// 	data->i++;
	// }