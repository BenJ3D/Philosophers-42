/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:21:02 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/24 16:59:35 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void *monitoring(void *arg)
{
	t_data *data;
	long time;
	int i;

	data = arg;
	while (1)
	{
		if (data->somebody_is_dead == TRUE)
			break;
		i = 0;
		time = time_get(data);
		if ((time - data->philos[i].last_ate) > data->time_rules.time_to_die / 1000)
		{
			print_message(STATE_DIED, i + 1, data->philos->tid, data, 0);
			pthread_mutex_lock(&data->mtx_lock_message);
			i = 0;
			data->somebody_is_dead = TRUE;
			// while(i < data->number_of_philo)
			// 	pthread_detach(data->philos[i++].tid);
			i = 0;
			// while(i < data->number_of_philo)
			// {
			// 	data->forks[i].availability = FORK_NOT_AVAILABLE;
			// 	pthread_mutex_destroy(&data->forks[i++].mtx_forks);
			// }
			break ;
		}
		i++;
		usleep(1);
	}
	printf("(DBG) fin du monitoring\n");
	pthread_mutex_unlock(&data->mtx_lock_message);
	return (0);
}

int init_monitoring(t_data *data)
{
	int i;

	data->monitor.time_control = malloc(sizeof(long) * data->number_of_philo);
	if (!data->monitor.time_control)
		return (EXIT_FAILURE);
	i = 0;
	while (i < data->number_of_philo)
		data->monitor.time_control[i++] = 0;
	if (pthread_create(&data->monitor.tid, NULL, &monitoring, data))
		return (EXIT_FAILURE);
	pthread_detach(data->monitor.tid);
	return (0);
}