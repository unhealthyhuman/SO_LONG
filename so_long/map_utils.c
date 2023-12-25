/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:26:49 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/22 13:46:17 by ischmutz         ###   ########.fr       */
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
	data->map = read_map(data->fd);
	check_if_rectangle(data->map, data);
	check_pe(data->map);
	check_collectible(data->map);
	check_walls(data->map, data);
}

void	movement_restrictions(t_data *data)
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
}

/* void	read_map(int fd) //tengo como input el mapa? **
{
	int		i;
	char	*readline;
	char 	*last_line;
	char	**map;

	i = 0;
	readline = get_next_line(fd);
	i = 1;
	//ft_printf("%s\n", line);
	while (readline != NULL)
	{
		last_line = ft_strjoin(last_line, readline);
		if (last_line == NULL)
			return ;
		//if (i == 1 && check_if_valid(readline) == )
			//does smt;
		
		free(readline);
		readline = get_next_line(fd);
		//last_line = malloc(sizeof(char)*ft_strlen(readline));

	}
	map = ft_split(last_line, '\0');
} */