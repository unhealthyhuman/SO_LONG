/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:21:37 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/21 17:21:44 by ischmutz         ###   ########.fr       */
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

/* void	check_player(char **map)
{
	int	p;
	int	i;
	int	j;

	p = 0;
	while(map[i] != NULL)
	{
		while(map[i][j])
		{
			if (map[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	if (p == 0)
		error_handler("invalid map: no player");
	else if (p > 1)
		error_handler("invalid map: too many players");
} */

void	check_pe(char **map)
{
	int	p;
	int	e;
	int	i;
	int	j;

	p = 0;
	e = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p++;
			else if (map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (p == 0 || e == 0)
		error_handler("invalid map: no player/exit");
	else if (p > 1 || e > 1)
		error_handler("invalid map: too many players/exits");
}

void	check_collectible(char **map)
{
	int	c;
	int	i;
	int	j;

	c = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (c == 0)
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