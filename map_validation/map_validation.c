/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:01:21 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/29 14:59:12 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

static void	free_and_exit_validation(t_game *game)
{
	free_map(game->map);
	free(game->player);
	free(game);
	error_exit("invalid map");
}

static void	update_collectible(t_map *map, int x_pos, int y_pos)
{
	if (map->values[x_pos][y_pos] == 'E')
		map->num_ex++;
	else if (map->values[x_pos][y_pos] == 'C')
		map->num_con++;
	else if (map->values[x_pos][y_pos] == 'P')
		map->num_pl++;
}

static void	check_for_extra(t_game *game)
{
	if (game->map->num_ex != 1 || game->map->num_pl != 1
		|| game->map->num_con < 1)
		free_and_exit_validation(game);
	flood_check(game);
}

void	map_validation(t_game *game)
{
	int		i;
	int		j;
	char	**values;

	i = 0;
	values = game->map->values;
	while (game->map->values[i])
	{
		j = 0;
		while (values[i][j])
		{
			if ((i == 0 || i == game->map->map_h - 1) && values[i][j] != '1')
				free_and_exit_validation(game);
			if ((j == 0 || j == game->map->map_w - 1) && values[i][j] != '1')
				free_and_exit_validation(game);
			if (values[i][j] != '1' && values[i][j] != '0'
				&& values[i][j] != 'E' && values[i][j] != 'C'
				&& values[i][j] != 'P')
				free_and_exit_validation(game);
			update_collectible(game->map, i, j);
			j++;
		}
		i++;
	}
	check_for_extra(game);
}
