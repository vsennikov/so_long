/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:55:47 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/02 11:33:33 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>

typedef struct s_map
{
	int			map_h;
	int			map_w;
	char		**values;
	int			num_ex;
	int			num_con;
	int			num_pl;
	int			col_for_valid;
}				t_map;

typedef struct s_player
{
	int			x_pos;
	int			y_pos;
	int			old_x;
	int			old_y;
}				t_player;

typedef struct s_game
{
	t_map		*map;
	t_player	*player;
	void		*s_floor;
	void		*s_wall;
	void		*s_player;
	void		*s_coin;
	void		*s_exit;
	void		*mlx;
	void		*mlx_win_ptr;
	int			mooves;
	int			end;
	int			ex_x;
	int			ex_y;
}				t_game;

void			error_exit(char *msg);
void			free_map(t_map *map);

// map validation
int				name_validation(char *name);
void			map_parsing(char *map_name, t_game *game);
void			map_validation(t_game *game);
void			flood_check(t_game *game);
void			error_pars(t_game *game, char *msg, int fd);
void			error_ass(t_game *game, char *msg);

// game
void			init_map(t_game *game);
void			display_map(t_game *game);
int				key_hook(int keycode, t_game *game);
int				close_window(t_game *game);
void			delete_images(t_game *game);
void			check_displaying(t_game *game);
#endif
