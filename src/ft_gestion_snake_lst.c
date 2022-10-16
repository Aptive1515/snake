/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion_snake_lst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:16:59 by aptive            #+#    #+#             */
/*   Updated: 2022/10/16 18:54:59 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/snake.h"


t_snake	*ft_add_snake_list(t_snake *snake)
{
	t_snake	*snake_tmp;

	snake_tmp = malloc(sizeof(t_snake));
	if (!snake_tmp)
		return (NULL);
	snake_tmp->next = NULL;
	snake_tmp->touch = 1000000;
	snake->next = snake_tmp;
	snake_tmp->prev = snake;

	return (snake);
}

t_snake	*ft_go_to_first_maille(t_snake *snake)
{
	while (snake->prev)
		snake = snake->prev;
	return (snake);
}

t_snake	*update_maille(t_snake *snake)
{
	t_snake	*snake_tmp;

	while (snake->next)
	{
		snake_tmp = snake;
		snake = snake->next;
		snake->position_x = snake_tmp->position_x;
		snake->position_y = snake_tmp->position_y;
	}
	ft_go_to_first_maille(snake);
	return (snake);
}
