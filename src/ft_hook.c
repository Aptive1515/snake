/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:47:53 by tdelauna          #+#    #+#             */
/*   Updated: 2022/10/16 17:10:13 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/snake.h"

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (EXIT_SUCCESS);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65363 && data->snake->touch == 1)
	{
		if (data->snake->direction == 'N')
			data->snake->direction = 'E';
		else if (data->snake->direction == 'E')
			data->snake->direction = 'S';
		else if (data->snake->direction == 'S')
			data->snake->direction = 'W';
		else if (data->snake->direction == 'W')
			data->snake->direction = 'N';
		data->snake->touch = 0;
	}
	else if (keycode == 65361 && data->snake->touch == 1)
	{
		if (data->snake->direction == 'N')
			data->snake->direction = 'W';
		else if (data->snake->direction == 'E')
			data->snake->direction = 'N';
		else if (data->snake->direction == 'S')
			data->snake->direction = 'E';
		else if (data->snake->direction == 'W')
			data->snake->direction = 'S';
		data->snake->touch = 0;
	}
	return (0);
}
