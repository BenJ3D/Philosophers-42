/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:36:42 by bducrocq          #+#    #+#             */
/*   Updated: 2022/05/27 17:39:17 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void *routine(void *arg, t_data *data)
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
	if (pthread_mutex_init(&data->lock, NULL))
	{
		printf("\n mutex init failed\n");
		return (1);
	}
	
	data->i = 0;
	pthread_create(&data->tid[data->i], NULL, routine, data);
	data->i++;
	pthread_create(&data->tid[data->i], NULL, routine, data);

	while(data->i >= 0)
	{
		pthread_join(data->tid[i], NULL);
		data->i--;
	}
	pthread_attr_destroy(data->lock);
	return(0);
}

// int main()
// {
// 	t_data	data;

// 	printf("Hello World !\nI'm main thread !\n");
// 	init_thread(&data);
// 	return (0);
// }