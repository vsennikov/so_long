/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:52:07 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/21 14:41:03 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *msg)
{
	ft_printf("Error: %s\n", msg);
	exit(1);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->values[i] != NULL)
	{
		free(map->values[i++]);
	}
	free(map->values);
	free(map);
}
