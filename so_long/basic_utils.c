/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:02:45 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/29 15:53:32 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	while (data->map[i] != NULL)
		free(data->map[i++]);
	free(data->map);
}
