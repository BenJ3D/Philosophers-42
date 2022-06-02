/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:36:42 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/02 19:11:33 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// void *routine(void *arg)
// {
// 	int y;
// 	t_data	*data;

// 	data = arg;
// 	y = 0;
// 	while (y < 3)
// 	{
// 		printf("Hello !\nI'm thread number %i !\n", data->i);
// 		usleep(100000);
// 		y++;
// 	}
// 	pthread_mutex_lock(&(data)->lock);
// 	pthread_mutex_unlock(&(data)->lock);
// 	return (0);
// }

// int	init_thread(t_data *data)
// {
// 	if (pthread_mutex_init(&data->lock, NULL))
// 	{
// 		printf("\n mutex init failed\n");
// 		return (1);
// 	}
	
// 	data->i = 0;
// 	pthread_create(&data->tid[data->i], NULL, &routine, data);
// 	data->i++;
// 	pthread_create(&data->tid[data->i], NULL, &routine, data);

// 	while(data->i >= 0)
// 	{
// 		pthread_join(data->tid[data->i], NULL);
// 		data->i--;
// 	}
// 	return(0);
// }

// int main()
// {
// 	t_data	data;

// 	init_thread(&data);
// 	return (0);
// }