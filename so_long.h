/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:01:54 by akouame           #+#    #+#             */
/*   Updated: 2022/08/19 16:58:36 by akouame          ###   ########.fr       */
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
	void	*img_player;
	char	*name_player;
	void	*img_coin;
	char	*name_coin;
	void	*img_exit;
	char	*name_exit;
	void	*img_fre_spc;
	char	*name_free_spc;
	
	void		*init;
	void		*wind;
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
// void	ft_initial(t_elem_game	*elem, t_mlx mlx, t_data_img img, t_size size);

// typedef struct s_mov_p
// {
	
// }
int				create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_b(int trgb);
unsigned char	get_g(int trgb);
int	ft_check_file(char **argv);
int	ft_check_map(char *file);
int	ft_check_exit(char *str, char c);
char	*ft_add_str(char *map, char *file);
int	ft_length(char **map_splited);
t_size	ft_size(char *file);
void	ft_initial(t_data *data);


#endif