/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:32:09 by tdelauna          #+#    #+#             */
/*   Updated: 2022/10/16 18:14:01 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_H
# define SNAKE_H
# include <string.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../miniLibX_X11/mlx.h"
//# include <mlx.h>
# define WIDTH	1980
# define HEIGHT	1200
# define SQUARE	32
# define GREEN	0X2fff00
# define BLACK	0X000000




typedef struct s_snake{
	int		direction;
	int		len_snake;
	int		position_x;
	int		position_y;
	int		touch;
	struct s_snake *next;
	struct s_snake *prev;

}				t_snake;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;


	int		screen_w;
	int		screen_h;


	int	map_y_up;
	int	map_y_down;

	int	map_x_left;
	int	map_x_right;




	t_snake *snake;
}				t_data;

/*
FT_AFFICHAGE---------------------------------------------------------------------
*/
void	ft_affiche_map(t_data *vars);
int		ft_affichage_wall(t_data *vars, int y, int x);
int		ft_affichage_floor(t_data *vars, int y, int x);
void	ft_full(t_data *data, int x_beg, int y_beg, int color);
void	ft_snake(t_data *data);

/*
FT_HOOK--------------------------------------------------------------------------
*/
int		ft_close(t_data *vars);
int		key_hook(int keycode, t_data *data);

/*
FT_UTILS-------------------------------------------------------------------------
*/
int		ft_doubletab_len(char **tab);
int		ft_free_doubletab(char **tab);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*
FT_GESTION_SNAKE_LST.C-----------------------------------------------------------
*/
t_snake	*ft_add_snake_list(t_snake *snake);
t_snake	*ft_go_to_first_maille(t_snake *snake);
t_snake	*update_maille(t_snake *snake);

#endif
