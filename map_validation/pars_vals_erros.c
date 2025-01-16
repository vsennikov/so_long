/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_vals_erros.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:52:42 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/29 15:32:34 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_pars(t_game *game, char *msg, int fd)
{
	if (game->map->values)
		free(game->map->values);
	free(game->map);
	free(game->player);
	close(fd);
	free(game);
	error_exit(msg);
}

void	error_ass(t_game *game, char *msg)
{
	free_map(game->map);
	free(game->player);
	free(game);
	error_exit(msg);
}
