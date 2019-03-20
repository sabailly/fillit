/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:15:26 by armoulin          #+#    #+#             */
/*   Updated: 2019/01/31 15:21:24 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*ft_create_grid(int min_size, char *grid)
{
	int		i;
	int		max;

	if (grid)
		free(grid);
	max = min_size * (min_size + 1);
	grid = ft_strnew(max);
	i = 0;
	while (i < max)
	{
		if ((i + 1) % (min_size + 1) == 0)
			grid[i] = '\n';
		else
			grid[i] = '.';
		i++;
	}
	return (grid);
}

static t_bool	ft_check_space(t_tetri tetri, char *grid, int min_size, int pos)
{
	int		i;
	int		test_pos;

	i = 0;
	if ((pos + tetri.cocos[3].x + tetri.cocos[3].y * (min_size + 1))
			> min_size * (min_size + 1))
		return (FALSE);
	while (i < 4)
	{
		test_pos = pos + tetri.cocos[i].x + tetri.cocos[i].y * (min_size + 1);
		if (grid[test_pos] != '.')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void			ft_put_tetri(char *grid, int pos, t_tetri tetri, char letter)
{
	int		i;
	int		coord;
	int		min_size;

	min_size = 0;
	i = 0;
	while (grid[i++] != '\n')
		min_size++;
	i = 0;
	while (i < 4)
	{
		coord = pos + tetri.cocos[i].x + tetri.cocos[i].y * (min_size + 1);
		grid[coord] = letter;
		i++;
	}
}

static t_bool	ft_backtracking(t_tetri *tetris, int nb_tetri, int min_size,
		char *grid)
{
	int		pos;
	t_bool	is_fixed;

	if (nb_tetri == tetris[0].total)
		return (TRUE);
	pos = 0;
	is_fixed = FALSE;
	while (pos < (min_size + 1) * min_size)
	{
		if (ft_check_space(tetris[nb_tetri], grid, min_size, pos))
		{
			is_fixed = TRUE;
			ft_put_tetri(grid, pos, tetris[nb_tetri], 'A' + nb_tetri);
			if (ft_backtracking(tetris, nb_tetri + 1, min_size, grid))
				return (TRUE);
		}
		if (is_fixed)
		{
			ft_put_tetri(grid, pos, tetris[nb_tetri], '.');
			is_fixed = FALSE;
		}
		pos++;
	}
	return (FALSE);
}

void			ft_fillit(t_tetri *tetris)
{
	int		min_size;
	char	*grid;

	grid = NULL;
	min_size = (ft_sqrt(tetris[0].total * 4));
	grid = ft_create_grid(min_size, grid);
	while (!(ft_backtracking(tetris, 0, min_size, grid)))
	{
		min_size++;
		grid = ft_create_grid(min_size, grid);
	}
	ft_putstr(grid);
	free(grid);
}
