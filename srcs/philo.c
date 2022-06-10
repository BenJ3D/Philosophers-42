/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:07:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/10 16:12:46 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philo_routine(void *arg)
{
	t_data		*data;
	int			index_philo;

	data = arg;
	index_philo = data->id_philo;
	
	pthread_mutex_lock(&data->mtx_lock_message);
	gettimeofday(&data->current_time, NULL);
	printf("%ld ms  ", time_get(data));
	printf("philo %i is born\n", index_philo);
	pthread_mutex_unlock(&data->mtx_lock_message);
	
	while (1)
	{
		philo_eating(data, index_philo);
		philo_sleeping(data, index_philo);
		philo_thinking(data, index_philo);
	}
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->id_philo = 0;
	while(i < data->number_of_philo)
	{
		data->id_philo++;
		if(pthread_create(&data->philos[i].tid, NULL, &philo_routine, data))
			exit(-1);
		data->philos[i].is_died = FALSE;
		data->philos[i].ate_nb = 0;
		if (data->time_rules.ate_max_imposed == TRUE);
			data->philos[i].ate_max = data->time_rules.max_philo_must_eat;
		i++;
		usleep(3); /////////////////////////////// INTERVAL BORN PHILO
	}
	while(1);
	while (data->id_philo >= 0)
	{
		pthread_join(data->tid[data->id_philo], NULL);
		data->id_philo--;
	}
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
		pthread_mutex_init(&data->forks[i++].mtx_forks, NULL);
	i = 0;
	while (i < data->number_of_philo)
		data->forks[i++].availability = FORK_AVAILABLE;
	return (0);
}
