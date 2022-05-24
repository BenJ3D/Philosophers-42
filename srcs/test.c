/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:36:42 by bducrocq          #+#    #+#             */
/*   Updated: 2022/05/24 17:35:05 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void *routine(t_data *data)
{
	int y = 0;

	while (y < 10)
	{
		printf("Hello !\nI'm thread number %i !\n", data->i);
		sleep(1);
		y++;
	}
}

int	init_thread(t_data *data)
{
	data->i = 1;
	pthread_create(&data->thread1[data->i], NULL, routine, data);
	return(0);
}

// int main()
// {
// 	t_data	data;

// 	printf("Hello World !\nI'm main thread !\n");
// 	init_thread(&data);
// 	return (0);
// }