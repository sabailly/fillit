/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:59:29 by armoulin          #+#    #+#             */
/*   Updated: 2019/02/05 14:01:49 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_coord
{
	int x;
	int y;
}				t_coord;

typedef struct	s_tetri
{
	t_coord	cocos[4];
	int		total;
}				t_tetri;

int				ft_parsing(const int fd, int coords[26][4]);
t_tetri			*ft_store_coords(int coords[26][4], int tetri_total);
void			ft_fillit(t_tetri *tetris);

#endif
