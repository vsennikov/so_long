/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:27:33 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/21 18:32:58 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	find_player(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (map->values[i])
	{
		j = 0;
		while (map->values[i][j])
		{
			if (map->values[i][j] == 'P')
			{
				player->x_pos = i;
				player->y_pos = j;
			}
			j++;
		}
		i++;
	}
}

static void	dfs(t_map *map, int x, int y)
{
	if (map->values[x][y] == '1' || map->values[x][y] == '2'
		|| map->values[x][y] == '3' || map->values[x][y] == '4')
		return ;
	else if (map->values[x][y] == 'C')
	{
		map->col_for_valid--;
		map->values[x][y] = '3';
	}
	else if (map->values[x][y] == 'E')
	{
		map->col_for_valid--;
		map->values[x][y] = '4';
	}
	else
		map->values[x][y] = '2';
	if (x - 1 >= 1)
		dfs(map, x - 1, y);
	if (y + 1 < map->map_w)
		dfs(map, x, y + 1);
	if (x + 1 < map->map_h)
		dfs(map, x + 1, y);
	if (y - 1 >= 1)
		dfs(map, x, y - 1);
}

static void	return_map_back(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while(map->values[i])
	{
		j = 0;
		while (map->values[i][j])
		{
			if (map->values[i][j] == '2')
				map->values[i][j] = '0';
			else if(map->values[i][j] == '3')
				map->values[i][j] = 'C';
			else if(map->values[i][j] == '4')
				map->values[i][j] = 'E';
			j++;
		}
		i++;
	}
	map->values[player->x_pos][player->y_pos] = 'P';
}

void	flood_check(t_map *map, t_player *player)
{
	map->col_for_valid = map->num_con + map->num_ex;
	find_player(map, player);
	dfs(map, player->x_pos, player->y_pos);
	if (map->col_for_valid != 0)
	{
		free_map(map);
		free(player);
		error_exit("coins and/or exit unreachable");
	}
	return_map_back(map, player);
}
