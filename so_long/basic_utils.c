/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:02:45 by ischmutz          #+#    #+#             */
/*   Updated: 2023/12/20 16:26:24 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_handler(char *message)
{
	ft_printf("ERROR\n");
	ft_printf("%s\n", message);
	exit(1);
}
