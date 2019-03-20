/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:53:46 by armoulin          #+#    #+#             */
/*   Updated: 2019/01/31 14:52:13 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"

t_tetri		*ft_store_coords(int coords[26][4], int tetri_total)
{
	t_tetri		*tetris;
	int			nb_tetri;
	int			i;

	if (!(tetris = (t_tetri*)malloc(sizeof(t_tetri) * tetri_total)))
		return (NULL);
	nb_tetri = 0;
	while (nb_tetri < tetri_total)
	{
		i = 0;
		while (i < 4)
		{
			tetris[nb_tetri].cocos[i].x = coords[nb_tetri][i] % 5;
			tetris[nb_tetri].cocos[i].y = coords[nb_tetri][i] / 5;
			i++;
		}
		tetris[nb_tetri].total = tetri_total;
		nb_tetri++;
	}
	return (tetris);
}

static void	ft_usage(void)
{
	ft_putstr("usage: fillit source_file\n");
}

static void	ft_error(void)
{
	ft_putstr("error\n");
}

int			main(int argc, const char **argv)
{
	int			fd;
	int			coords[26][4];
	int			tetri_total;
	t_tetri		*tetris;

	if (argc != 2)
	{
		ft_usage();
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0 ||
			!(tetri_total = ft_parsing(fd, coords)))
	{
		ft_error();
		return (0);
	}
	close(fd);
	tetris = ft_store_coords(coords, tetri_total);
	ft_fillit(tetris);
	free(tetris);
	return (0);
}
