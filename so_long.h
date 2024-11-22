/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:55:47 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/22 17:41:31 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>

// map structures

typedef struct s_position
{
	int			x_pos;
	int			y_pos;
	char		value;
	int			was_here;
}				t_position;

typedef struct s_map
{
	int		map_h;
	int		map_w;
	char	**values;
	int		num_ex;
	int		num_con;
	int		num_pl;
	int		col_for_valid;
}			t_map;

typedef struct s_player
{
	int		x_pos;
	int		y_pos;
}			t_player;

void		error_exit(char *msg);
void		free_map(t_map *map);

// map validation
int			name_validation(char *name);
void		map_parsing(char *map_name, t_map *map);
void		map_validation(t_map *map, t_player *player);
void		flood_check(t_map *map, t_player *player);
#endif
