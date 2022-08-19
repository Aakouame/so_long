/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:52:38 by akouame           #+#    #+#             */
/*   Updated: 2022/08/18 19:17:16 by akouame          ###   ########.fr       */
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

	i = 0;
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
		i++;
	}
	if (elm.coin < 1 || elm.exit != 1 || elm.player != 1 || elm.fre_spc < 1)
		return (0);
	return (1);
}

int	ft_split_map(char *map)
{
	int		max_length;
	int		i;
	char	**map_splited;

	map_splited = NULL;
	i = 0;
	map_splited = ft_split(map, '\n');
	max_length = ft_strlen(map_splited[i]);
	printf("max_length = %d\n", max_length);
	printf("s[0] = %s\n", map_splited[i]);
	return (0);
}

int	ft_check_map(char *file)
{
	char	*map;
	int		x;
	
	map = NULL;
	map = ft_add_str(map, file);
	printf("map = \n%s\n", map);
	if (ft_check_elem(map) == 0) // != 0
	{
		x = ft_split_map(map);
	}
	
	return (1);
}