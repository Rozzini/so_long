/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 02:50:50 by mraspors          #+#    #+#             */
/*   Updated: 2022/06/24 07:02:27 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define COIN "./img/coin.xpm"
# define ENEMY "./img/enemy.xpm"
# define EXIT "./img/exit.xpm"
# define ME1 "./img/me1.xpm"
# define ME2 "./img/me2.xpm"
# define PASS "./img/pass.xpm"
# define WALL "./img/wall.xpm"

typedef struct s_pos {
	int		x;
	int		y;
}				t_pos;

typedef struct s_wme {
	t_pos	*pos;
	int		dir;
}				t_wme;

typedef struct s_map {
	t_pos	*player;
	int		w;
	int		h;
	char	**map;
	int		coins;
	int		wme;
}				t_map;

typedef struct s_game {
	void	*img;
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
	t_wme	**wme;
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

void	draw_map(t_map *map, t_game *game, t_wme **wme);
void	pick_img(t_game *game, char c, int x, int y);
void	draw_img(t_game *game, char *path, int x, int y);
int		close_game(t_game *game);
void	free_staf(t_game *game, t_map *map, t_wme **wme);
void	free_split(char **s);
void	free_wme(t_wme **wme, int count);

void	init_window(t_map *map, t_game *game);
void	init_structs(t_map *map, t_game *game);
void	init_wme(t_game *game, t_wme **wme);
void	init_wme_pos(t_wme *wme, int x, int y);
int		count_wme(t_map *map);
void	pick_dir_for_wme(t_game *game, t_wme **wme);
void	find_player(t_map *map);

int		move_wme(t_game *game);
void	put_wme(t_game *game, t_wme *wme, int change_dir);
int		move(int key, t_game *game);
int		try_move(int x, int y, t_game *game);
int		move_error(t_game *game, int x, int y);
void	show_moves(t_game *game);

#endif