/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:02:09 by akouame           #+#    #+#             */
/*   Updated: 2022/08/15 18:07:06by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	colors_baby(int color)
// {
// 	printf("%d\n", color);
// 	return (color << 8);
// }

// int	key(int c, t_mlx *mlx)
// {
// 	ft_putnbr_fd(c, 0);
// 	printf("\n");
// 	if (c == 53)
// 		exit(0);
// 	if (c == 2)
// 	{
// 		mlx_destroy_image(mlx->init, mlx->ptr_img->img);
// 		mlx->ptr_img->img1 = mlx_xpm_file_to_image(mlx->init, "./player_face.xpm", &mlx->ptr_img->w, &mlx->ptr_img->h);
// 		mlx_put_image_to_window(mlx->init, mlx->wind, mlx->ptr_img->img1, 0, 150);
// 	}
// 	//if (c == 'd')
// 	//	exit(0);
// 	return (1);
// }

// int main ()
// {
// 	t_data_img	img;
// 	t_mlx		mlx;
// 	int	color;
// 	int	i;
	
// 	i = 0;
// 	color = 0x000000;
// 	mlx.init = mlx_init();
// 	mlx.wind = mlx_new_window(mlx.init, 800, 660, "SO_LONG");
// 	img.img = mlx_xpm_file_to_image(mlx.init, "./player_face.xpm", &img.w, &img.h);
// 	//mlx.ptr_img = &img;
// 	mlx_put_image_to_window(mlx.init, mlx.wind, img.img, 0, 150);
// 	//mlx_put_image_to_window(mlx.init, mlx.wind, img.img, 0, 0);
// 	mlx_key_hook(mlx.wind, key, &mlx);
// 	//mlx_string_put(mlx.init, mlx.wind, 0, 10, 0xff77ff, "WEwewe");
// 	mlx_loop(mlx.init);
// }

			// mlx_put_image_to_window(data.init, data.wind, data.img_coin, 0, 0);
int	ft_exit(t_data data)
{	
	(void) data;
	exit(0);
	return (0);
}

int key_hook(int key_code, t_data *data)
{
	data->key = key_code;
	if (key_code ==  2)
		ft_mov_right(data, data->map_splited, &data->coin);
	if (key_code == 1)
		ft_mov_down(data, data->map_splited, &data->coin);
	if (key_code == 0)
		ft_mov_left(data, data->map_splited, &data->coin);
	if (key_code == 13)
		ft_mov_up(data, data->map_splited, &data->coin);
	// printf ("key --> = %d\n", key_code);
	ft_putstr_fd("MOVES : ", 1);
	ft_putnbr_fd(data->cpt, 1);
	if (key_code == 53)
		{
			exit(0);
		}
	return (0);
}

int main (int argc, char **argv)
{
	t_data	data;

	if (argc == 2 && ft_check_file(argv))
	{
		if (ft_check_map(argv[1]) != 0)
		{
			data.size = ft_size(argv[1]);
			ft_initial(&data);
			
			data.map_splited = ft_map(argv[1]);
			data.max_c = ft_all_coins(data.map_splited);

			ft_build_map(data.map_splited, data);
			mlx_key_hook(data.wind, key_hook, &data);
			mlx_hook(data.wind, 17, 1L << 0, ft_exit, &data);
			mlx_hook(data.wind, 2, 0L, key_hook, &data);
			printf("rak nadi canadi \n");
			mlx_loop(data.init);
		}
		else
			printf("3ayan 3ayan \n");
	}
	else
		ft_putstr_fd("Error  : Check ur file name !\n",1);
	
	while (1)
	{

	}
	return (0);
}

			// mlx_put_image_to_window(data.init, data.wind, data.img_fre_spc, 32, 32);
			// mlx_put_image_to_window(data.init, data.wind, data.img_fre_spc, 32 * 2, 32 * 2);
			// mlx_put_image_to_window(data.init, data.wind, data.img_player_down, 32, 32);
			// mlx_put_image_to_window(data.init, data.wind, data.img_player_up, 2 * 32, 2 * 32);
			// mlx_put_image_to_window(data.init, data.wind, data.img_wall, 100, 100);
			// // mlx_put_image_to_window(data.init, data.wind, data.img_coin, 0, 0);
			// // ft_initial(&data);