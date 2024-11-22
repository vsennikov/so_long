/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:01:21 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/21 16:40:11 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	free_and_exit_validation(t_map *map)
{
	free_map(map);
	error_exit("invalid map");
}

static void	update_collectible(t_map *map, int x_pos, int y_pos)
{
	
	if (map->values[x_pos][y_pos] == 'E')
		map->num_ex++;
	else if(map->values[x_pos][y_pos] == 'C')
		map->num_con++;
	else if(map->values[x_pos][y_pos] == 'P')
		map->num_pl++;
}

static void		check_for_extra(t_map *map)
{
	if (map->num_ex != 1 || map->num_pl != 1 || map->num_con < 1)
		free_and_exit_validation(map);
}

void	map_validation(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (map->values[i])
	{
		j = 0;
		while (map->values[i][j])
		{
			if ((i == 0 || i == map->map_h - 1) && map->values[i][j] != '1')
				free_and_exit_validation(map);
			if ((j == 0 || j == map->map_w - 1) && map->values[i][j] != '1')
				free_and_exit_validation(map);
			if (map->values[i][j] != '1' && map->values[i][j] != '0'
				&& map->values[i][j] != 'E' && map->values[i][j] != 'C'
				&& map->values[i][j] != 'P')
				free_and_exit_validation(map);
			update_collectible(map, i, j);
			j++;
		}
		i++;
	}
	check_for_extra(map);
	flood_check(map, player);
}
