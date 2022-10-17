/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:42:34 by aptive            #+#    #+#             */
/*   Updated: 2022/10/17 01:13:37 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/snake.h"

void	ft_lign_horizontal(t_data *data, int x, int x_end, int y,int color)
{
	while (x < x_end)
	{
		my_mlx_pixel_put(data, x, y, color);
		x++;
	}
}

void	ft_lign_vertical(t_data *data, int x, int y, int y_end, int color)
{
	while (y < y_end)
	{
		my_mlx_pixel_put(data, x, y, color);
		y++;
	}
}

void	ft_map_line(t_data *data)
{


	printf("data->screen_w - SQUARE * 10 : %i\n", data->screen_w);
	ft_lign_horizontal(data, data->map_x_left, data->map_x_right, data->map_y_up, GREEN);
	ft_lign_horizontal(data, data->map_x_left, data->map_x_right, data->map_y_down, GREEN);
	ft_lign_vertical(data, data->map_x_left, data->map_y_up, data->map_y_down, GREEN);
	ft_lign_vertical(data, data->map_x_right, data->map_y_up, data->map_y_down, GREEN);
}

void	ft_back_last_maille(t_data *data)
{
	while (data->snake->next)
		data->snake = data->snake->next;
	printf("data->snake->position_x last: %i\n", data->snake->position_x);
	ft_full(data, data->snake->position_x, data->snake->position_y, BLACK);
	ft_go_to_first_maille(data->snake);
}

void	ft_all_screen_color(t_data *data, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->screen_h)
	{
		x = -1;
		while (++x < data->screen_w)
			my_mlx_pixel_put(data, x, y, color);
	}
}


void	ft_snake(t_data *data)
{
	printf("data->snake->position_x : %i\n", data->snake->position_x);




	update_maille(data->snake);
	if (data->snake->direction == 'N')
		data->snake->position_y -= SQUARE;
	else if (data->snake->direction == 'S')
		data->snake->position_y += SQUARE;
	else if (data->snake->direction == 'E')
		data->snake->position_x += SQUARE;
	else if (data->snake->direction == 'W')
		data->snake->position_x -= SQUARE;




	ft_full(data, data->snake->position_x, data->snake->position_y, GREEN);
	while (data->snake->next)
	{
		printf("here\n");
		data->snake = data->snake->next;
		ft_full(data, data->snake->position_x, data->snake->position_y, GREEN);
	}
	ft_map_line(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);

	data->snake = ft_go_to_first_maille(data->snake);
}

int	nbAlea(int min, int max)
{
	int	n;
	n = rand() % max + min;
	printf("rand : %d\n", n);
	return (n);

}

void	ft_meet(t_data *data)
{
	if (data->meet != 1)
	{
		data->meet_x = data->map_x_left + SQUARE * nbAlea(0, 9);
		data->meet_y = data->map_y_up + SQUARE * nbAlea(0, 9);
		data->meet = 1;
	}
	ft_full(data, data->meet_x, data->meet_y, RED);

}

void	ft_affiche_map(t_data *data)
{




	ft_meet(data);

	ft_map_line(data);
	ft_full(data, data->snake->position_x, data->snake->position_y, GREEN);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	ft_full(t_data *data, int x_beg, int y_beg, int color)
{
	int	x_end;
	int	y_end;

	x_end = x_beg + SQUARE;
	y_end = y_beg + SQUARE;
	while (x_beg < x_end)
	{
		ft_lign_vertical(data, x_beg, y_beg + 1, y_end, color);
		x_beg++;
	}
}
