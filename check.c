/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:52:38 by akouame           #+#    #+#             */
/*   Updated: 2022/08/19 15:44:16 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_file(char **argv)
{
	int	i;
	int	j;
	char	*str;

	j = 4;
	str = ".ber";
	i = (int)ft_strlen(argv[1]) - 1;
	while(j != 0)
	{
		if (str[j - 1] != argv[1][i])
		{
				ft_putstr_fd("Error  : Check file name !\n", 1);
			return (0);
		}
		j--;
		i--;
	}
	return(1);
}

char	*ft_add_str(char *map, char *file)
{
	char	*line;
	int		fd;
	
	line = NULL;
	fd = open(file, O_RDONLY);
	map = ft_strjoin(line,get_next_line(fd));
	if (!map)
		return (NULL);
	while(1)
	{
		
		line = get_next_line(fd);
		if (!line)
			break ;
		map = ft_strjoin(map, line);
		free(line);
	}
	free(line);
	return (map);
}

int	ft_check_elem(char *map)
{
	int			i;
	t_elem_game	elm;
	int			error;

	i = 0;
	error = 0;
	elm.coin = 0;
	elm.exit = 0;
	elm.player = 0;
	elm.fre_spc = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			elm.coin++;	
		if (map[i] == 'E')
			elm.exit++;
		if (map[i] == '0')
			elm.fre_spc++;
		if (map[i] == 'P')
			elm.player++;
		if (ft_check_exit("01CPE\n", map[i]) == 0)
			return (1);
		i++;
	}
	if (elm.coin >= 1 && elm.exit == 1 && elm.player == 1 && elm.fre_spc >= 1)
		return (0);
	return (1);
}

int	ft_length(char **map_splited)
{
	int	l;

	l = 0;
	while (map_splited[l])
		l++;
	return (l);
}

int	ft_split_map(char *map)
{
	t_size		max;
	t_size		indx;
	char		**map_splited;
	
	map_splited = NULL;
	indx.y = 0;
	map_splited = ft_split(map, '\n');
	max.x = ft_strlen(map_splited[0]) - 1;
	max.y = ft_length(map_splited) - 1;
	if ((max.x < 3) || (max.y < 3))
		return (1);
	while(map_splited[indx.y])
	{
		if ((ft_strlen(map_splited[indx.y]) - 1) != ((size_t)max.x))
			return (1);
		indx.x = 0;
		while (map_splited[indx.y][indx.x])	
		{
			if (map_splited[0][indx.x] != '1' || map_splited[indx.y][0] != '1'
				|| map_splited[max.y][indx.x] != '1' || map_splited[indx.y][max.x] != '1')
				return (1);
			(indx.x)++;
		}
		(indx.y)++;
	}
	return (0);
}

int	ft_check_map(char *file)
{
	char	*map;
	// int		x;
	
	map = NULL;
	map = ft_add_str(map, file);
	if (!map)
		return (0);
	if (ft_check_elem(map) != 0) // Error elements
		return (0);
	if (ft_split_map(map) != 0)
		return (0);
	free(map);
	return (1);
}

t_size	ft_size(char *file)
{
	char		*map;
	t_size		max;
	char		**map_splited;
	
	map = NULL;
	map = ft_add_str(map, file);
	map_splited = NULL;
	map_splited = ft_split(map, '\n');
	max.x = ft_strlen(map_splited[0]);
	max.y = ft_length(map_splited);
	return(max);
}