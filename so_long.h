/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:01:54 by akouame           #+#    #+#             */
/*   Updated: 2022/08/18 18:55:56 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"

typedef struct	s_data_img
{
	void	*img;
	char	*addre;
	int		h;
	int		w;
	// int		bits_px;
	// int		line_lent;
	// int		endian;
}	t_data_img;

typedef struct s_mlx
{
	void		*init;
	void		*wind;
	t_data_img	*ptr_img;
	int		memory_offset;
}	t_mlx;

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

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};


// typedef struct s_mov_p
// {
	
// }
t_elem_game		ft_zero_elem(t_elem_game elem);
int				create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_b(int trgb);
unsigned char	get_g(int trgb);
int	ft_check_file(char **argv);
int	ft_check_map(char *file);

#endif