/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:01:54 by akouame           #+#    #+#             */
/*   Updated: 2022/08/20 21:26:30 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"


typedef	struct s_elem_game
{
	int	wall;
	int	coin;
	int	player;
	int	exit;
	int	fre_spc;
}	t_elem_game;


typedef	struct s_size
{
	int	x;
	int	y;
}	t_size;

typedef struct	s_data
{
	void	*img_wall;
	char	*name_wall;
	void	*img_player_face;
	char	*name_player_face;
	void	*img_player_left;
	char	*name_player_left;
	void	*img_player_right;
	char	*name_player_right;
	void	*img_player_up;
	char	*name_player_up;
	void	*img_player_down;
	char	*name_player_down;
	void	*img_coin;
	char	*name_coin;
	void	*img_exit;
	char	*name_exit;
	void	*img_fre_spc;
	char	*name_free_spc;
	int		width;
	int		length;
	void		*init;
	void		*wind;
	int			key;
	char		**map_splited;
	int			coin;
	int			max_c;
	int			cpt;
	t_size		size;

	
	
}	t_data;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// check.c
int	ft_check_file(char **argv);
int	ft_check_map(char *file);
int	ft_check_exit(char *str, char c);
char	*ft_add_str(char *map, char *file);
int	ft_length(char **map_splited);
t_size	ft_size(char *file);
//build.c
void	ft_initial(t_data *data);
void	ft_build_map(char **map_splited, t_data data);
char	**ft_map(char *file);
//play.c
t_size	ft_position(char **map_splited);
void	ft_mov_right(t_data data, char **map_splited, int *coin);
void	ft_play(t_data data, char **map_splited);
int		ft_all_coins(char **map_splited);
void	ft_mov_left(t_data data, char **map_splited, int *coin);


#endif