/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:07:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/10 16:34:09 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_last_ate(t_data data, int id)
{
	
	return (0);
}

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
		if (data->time_rules.ate_max_imposed == TRUE &&\
		data->philos[index_philo].ate_nb == data->philos[index_philo].ate_max)
			break;
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
		if (data->time_rules.ate_max_imposed == TRUE)
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

int	run_philo(t_data *data, int ac, char **argv)
{
	parsing_check(data, ac, argv);
	dbg_print_rules(data); //FIXME:
	if (ac == 6)
		data->time_rules.ate_max_imposed = TRUE;
	else
		data->time_rules.ate_max_imposed = FALSE;
	if (!(data->philos = malloc(sizeof(t_philo) * data->number_of_philo)))
		exit(EXIT_FAILURE);
	if (!(data->forks = malloc(sizeof(t_fork) * data->number_of_philo)))
		exit(EXIT_FAILURE);
	time_init(data);
	pthread_mutex_init(&data->mtx_lock_message, NULL);
	init_forks(data);
	init_philo(data);
	return (0);
}