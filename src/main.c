/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:30:42 by tdelauna          #+#    #+#             */
/*   Updated: 2022/10/16 18:54:05 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/snake.h"

t_data	*ft_init_data(t_data *data)
{
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->snake = malloc(sizeof(t_snake));
	if (!data->snake)
		return (NULL);



	data->screen_w = 20 * SQUARE;
	data->screen_h = 12 * SQUARE;
	data->map_y_up = SQUARE;
	data->map_y_down = SQUARE * 11;
	data->map_x_left = data->screen_w - SQUARE * 10;
	data->map_x_right = data->screen_w - SQUARE;

	data->snake->direction = 'E';
	data->snake->len_snake = 3;

	data->snake->position_x = data->map_x_left + SQUARE * 0;
	data->snake->position_y = data->map_y_up + SQUARE * 0;

	data->snake->touch = 1;
	data->snake->next = NULL;
	data->snake->prev = NULL;

	return (data);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->img = mlx_new_image(data->mlx, data->screen_w, data->screen_h);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	data->mlx_win = mlx_new_window(data->mlx, data->screen_w, data->screen_h, "Cub3D");
}

int	render_next_frame(t_data *data)
{
	ft_snake(data);
	usleep(500000);
	data->snake->touch = 1;
	return (1);
}

void	init_maille(t_snake *snake)
{
	t_snake	*snake_tmp;

	if (snake->next)
	{
		snake_tmp = snake;
		snake = snake->next;
		snake->position_x -= snake_tmp->position_x - SQUARE;
		snake->position_y = snake_tmp->position_y;
	}
}

int	main(void)
{
	t_data	*data;

	data = NULL;


	// data->map = ft_map(argv[1]);
	data = ft_init_data(data);
	init_mlx(data);

	ft_add_snake_list(data->snake);
	init_maille(data->snake);
	update_maille(data->snake);

	ft_affiche_map(data);
	// mlx_hook(data->mlx_win, 17, 1L << 0, ft_close, data);
	mlx_key_hook(data->mlx_win, key_hook, data);
	mlx_loop_hook(data->mlx, render_next_frame, data);
	mlx_loop(data->mlx);
	return (1);
}
