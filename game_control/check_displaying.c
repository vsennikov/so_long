/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_displaying.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:07:04 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/02 11:24:50 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_displaying(t_game *game)
{
	if (!game->s_coin || !game->s_exit || !game->s_floor || !game->s_player
		|| !game->s_wall)
	{
		delete_images(game);
		mlx_destroy_window(game->mlx, game->mlx_win_ptr);
		mlx_destroy_display(game->mlx);
		free_map(game->map);
		free(game->player);
		free(game->mlx);
		free(game);
		error_exit("mlx_xpm_to_file_image failed");
	}
}
