/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:20:36 by akouame           #+#    #+#             */
/*   Updated: 2022/08/22 10:57:29 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initial(t_data *data)
{
	data->map_splited = NULL;
	data->init = mlx_init();
	data->wind = mlx_new_window(data->init, (data->size.x * 32), (data->size.y * 32), "SO_LONG");
	data->img_coin = mlx_xpm_file_to_image(data->init, "./pict/coin.xpm", &data->width, &data->length);
	data->img_wall = mlx_xpm_file_to_image(data->init, "./pict/wall.xpm", &data->width, &data->length);
	data->img_fre_spc = mlx_xpm_file_to_image(data->init, "./pict/free_spc.xpm", &data->width, &data->length);
	data->img_player_face = mlx_xpm_file_to_image(data->init, "./pict/player_face.xpm", &data->width, &data->length);
	data->img_player_down = mlx_xpm_file_to_image(data->init, "./pict/player_down.xpm", &data->width, &data->length);
	data->img_player_up = mlx_xpm_file_to_image(data->init, "./pict/player_up.xpm", &data->width, &data->length);
	data->img_player_left = mlx_xpm_file_to_image(data->init, "./pict/player_left.xpm", &data->width, &data->length);
	data->img_player_right = mlx_xpm_file_to_image(data->init, "./pict/player_right.xpm", &data->width, &data->length);
	data->img_exit = mlx_xpm_file_to_image(data->init, "./pict/exit.xpm", &data->width, &data->length);
	data->name_player_face = "./pict/player_face.xpm";
	data->coin = 0;
	data->key = -1;
	data->cpt = 0;
}

void	ft_put_player(t_data data, t_size index)
{
	if (data.key == -1)
						mlx_put_image_to_window(data.init, data.wind, data.img_player_face, 32 * (index.x), 32 * index.y);
					if (data.key == 2)
						mlx_put_image_to_window(data.init, data.wind, data.img_player_right, 32 * (index.x), 32 * index.y);
					if (data.key == 1)
						mlx_put_image_to_window(data.init, data.wind, data.img_player_down, 32 * (index.x), 32 * index.y);
					if (data.key == 0)
						mlx_put_image_to_window(data.init, data.wind, data.img_player_left, 32 * (index.x), 32 * index.y);
					if (data.key == 13)
						mlx_put_image_to_window(data.init, data.wind, data.img_player_up, 32 * (index.x), 32 * index.y);
}

void	ft_put_elem(char **map_splited, t_data data, t_size index)
{
	while (map_splited[index.y])
		{
			index.x = 0;
			while (map_splited[index.y][index.x])
			{
				if (map_splited[index.y][index.x] == '1')
					mlx_put_image_to_window(data.init, data.wind, data.img_wall, 32 * (index.x), 32 * index.y);
				if (map_splited[index.y][index.x] == '0')
					mlx_put_image_to_window(data.init, data.wind, data.img_fre_spc, 32 * (index.x), 32 * index.y);
				if (map_splited[index.y][index.x] == 'C')
					mlx_put_image_to_window(data.init, data.wind, data.img_coin, 32 * (index.x), 32 * index.y);
				if (map_splited[index.y][index.x] == 'E')
					mlx_put_image_to_window(data.init, data.wind, data.img_exit, 32 * (index.x), 32 * index.y);
				if (map_splited[index.y][index.x] == 'P')
					ft_put_player(data, index);
				index.x++;
			}
			index.y++;
		}
}
char	**ft_map(char *file)
{
	char		*map;
	char		**map_splited;
	
	map = NULL;
	map = ft_add_str(map, file);
	map_splited = NULL;
	map_splited = ft_split(map, '\n');
	if (!map_splited)
		return (NULL);
	free(map);
	return (map_splited);
}

void	ft_build_map(char **map_splited, t_data data)
{
	t_size		index;
	
	index.y = 0;
	while (map_splited[index.y])
	{
		index.x = 0;
		while (map_splited[index.y][index.x])
		{
			mlx_put_image_to_window(data.init, data.wind, data.img_fre_spc, 32 * (index.x), 32 * index.y);
			index.x++;
		}
		index.y++;
	}
	index.y = 0;
	ft_put_elem(map_splited, data, index);
}