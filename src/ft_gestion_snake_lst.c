/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion_snake_lst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:16:59 by aptive            #+#    #+#             */
/*   Updated: 2022/10/17 01:22:28 by aptive           ###   ########.fr       */
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
	snake_tmp->touch = snake->direction;
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

t_snake	*ft_go_to_last_maille(t_snake *snake)
{
	while (snake->next)
		snake = snake->next;
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

void	affiche_snake(t_snake *snake)
{
	int i;

	i = 0;
	while (snake)
	{
		printf("***********************\n");
		printf("maille : %i\n", i);
		printf("snake : %p\n", snake);
		printf("direction : %i\n", snake->direction);
		printf("len_snake : %i\n", snake->len_snake);
		printf("position_x : %i\n", snake->position_x);
		printf("position_y : %i\n", snake->position_y);
		printf("touch : %i\n", snake->touch);
		printf("next : %p\n", snake->next);
		printf("prev : %p\n", snake->prev);
		snake = snake->next;
		i++;
	}
	printf("_______________________________\n");
}
