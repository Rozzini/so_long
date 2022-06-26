/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 00:06:42 by mraspors          #+#    #+#             */
/*   Updated: 2022/06/24 06:46:36 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define COIN "./img/coin.xpm"
# define EXIT "./img/exit.xpm"
# define ME1 "./img/me1.xpm"
# define ME2 "./img/me2.xpm"
# define PASS "./img/pass.xpm"
# define WALL "./img/wall.xpm"

typedef struct s_pos {
	int		x;
	int		y;
}				t_pos;

typedef struct s_map {
	t_pos	*player;
	int		w;
	int		h;
	char	**map;
	int		coins;
}				t_map;

typedef struct s_game {
	void	*img;
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
	int		steps;
}				t_game;

int		read_map_from_fd(char *file, t_map *map);
int		call_checkers(char *s, t_map *map);
int		split_map_check_lines(char *s, t_map *map);
int		check_top_bot_boundaries(t_map *map);
int		check_side_boundaries(t_map *map);
int		check_symbols(t_map *map);
int		check_coins(t_map *map);
int		check_exit(t_map *map);
int		check_player(t_map *map);

void	draw_map(t_map *map, t_game *game);
void	pick_img(t_game *game, char c, int x, int y);
void	draw_img(t_game *game, char *path, int x, int y);
int		close_game(t_game *game);
void	free_staf(t_game *game, t_map *map);
void	free_split(char **s);

void	init_window(t_map *map, t_game *game);
void	init_structs(t_map *map, t_game *game);
void	find_player(t_map *map);

int		move(int key, t_game *game);
int		try_move(int x, int y, t_game *game);
int		move_error(t_game *game, int x, int y);

#endif