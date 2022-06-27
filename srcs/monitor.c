/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:21:02 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/27 18:07:01 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_eat_time(t_data *data, long time, int i)
{
	while (i < data->number_of_philo)
	{
		time = time_get(data);
		if ((time - data->philos[i].last_ate) > \
		data->time_rules.time_to_die / 1000)
		{
			print_message(STATE_DIED, i + 1, data->philos->tid, data);
			pthread_mutex_lock(&data->mtx_lock_message);
			data->somebody_is_dead = TRUE;
			break ;
		}
		i++;
		usleep(10);
	}
	return (0);
}

void	*monitoring(void *arg)
{
	t_data	*data;
	long	time;

	data = arg;
	while (1)
	{
		if (data->somebody_is_dead == TRUE)
			break ;
		if ((data->philos[data->number_of_philo - 1].ate_nb \
		== data->time_rules.max_philo_must_eat) \
		&& data->time_rules.max_philo_must_eat > 0)
			break ;
		check_eat_time(data, time, 0);
		usleep(20);
	}
	pthread_mutex_unlock(&data->mtx_lock_message);
	return (0);
}

int	init_monitoring(t_data *data)
{
	int	i;

	data->monitor.time_control = malloc(sizeof(long) * data->number_of_philo);
	if (!data->monitor.time_control)
		return (EXIT_FAILURE);
	i = 0;
	while (i < data->number_of_philo)
		data->monitor.time_control[i++] = 0;
	if (pthread_create(&data->monitor.tid, NULL, &monitoring, data))
		return (EXIT_FAILURE);
	return (0);
}
