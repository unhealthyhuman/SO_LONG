/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:26:49 by ischmutz          #+#    #+#             */
/*   Updated: 2024/01/01 17:12:45 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	**map;

	readline = get_next_line(fd);
	full_line = NULL;
	while (readline != NULL)
	{
		//ft_printf("readline %s\n", readline);
		full_line = ft_strjoin_gnl(full_line, readline);
		//ft_printf("full_line %s\n", full_line);
		if (full_line == NULL)
			error_handler("strjoin failed");
		free (readline);
		readline = get_next_line(fd);
	}
	map = ft_split(full_line, '\n');
	return (map);
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