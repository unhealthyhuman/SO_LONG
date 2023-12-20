/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:26:49 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/20 16:34:32 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_if_valid(char *line_to_check)
{

}

/* typedef	struct s_map
{
	char
}; */

char	**read_map(int fd)
{
	char	*readline;
	char	*full_line;
	char	**map;

	readline = get_next_line(fd);
	while (readline != NULL)
	{
		full_line = ft_strjoin(full_line, readline);
		if (full_line == NULL)
			return ;
		free (readline);
		readline = get_next_line(fd);
	}
	map = ft_split(full_line, '\0');
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