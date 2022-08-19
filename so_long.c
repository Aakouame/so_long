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


int main (int argc, char **argv)
{
	if (argc == 2 && ft_check_file(argv))
	{
		printf("mok 2\n");
		if (ft_check_map(argv[1]))
		{
			printf("rak nadi canadi \n");
		}
	}
	else
		printf("3ayan 3ayaan \n");
	return (0);
}