/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:07:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/28 14:28:54 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philo_routine(void *arg)
{
	t_data		*data;
	int			index_philo;

	data = arg;
	//pthread_mutex_lock(&data->mtx_lock_m1);
	index_philo = data->id_philo;
	data->philos[index_philo - 1].id = index_philo;
//	pthread_mutex_unlock(&data->mtx_lock_m1);
	while (1)
	{
		if (data->somebody_is_dead == TRUE)
			break ;
		philo_eating(data, index_philo);
		if (data->time_rules.ate_max_imposed == TRUE \
		&& data->philos[index_philo - 1].ate_nb \
		== data->time_rules.max_philo_must_eat)
			break ;
		philo_sleeping(data, index_philo);
		philo_thinking(data, index_philo);
	}
	print_message(STATE_OVER, index_philo, data);
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->id_philo = 0;
	while (i < data->number_of_philo)
	{
	//	pthread_mutex_lock(&data->mtx_lock_m1);
		data->id_philo++;
	//	pthread_mutex_unlock(&data->mtx_lock_m1);
		if (pthread_create(&data->philos[i].tid, NULL, &philo_routine, data))
			return (EXIT_FAILURE);
		data->philos[i].is_died = FALSE;
		data->philos[i].ate_nb = 0;
		data->philos[i].last_ate = time_get(data);
	//	pthread_mutex_lock(&data->mtx_lock_m1);
		data->philos[i].id = data->id_philo;
	//	pthread_mutex_unlock(&data->mtx_lock_m1);
		if (data->time_rules.ate_max_imposed == TRUE)
			data->philos[i].ate_max = data->time_rules.max_philo_must_eat;
		i++;
		usleep(150);
	}
	while (data->id_philo > 0)
	{
		pthread_join(data->philos[data->id_philo - 1].tid, NULL);
		data->id_philo--;
	}
	return (0);
}

int	run_one_philo(t_data *data)
{
	time_print(data);
	printf("%i has taken a fork\n", 1);
	usleep(data->time_rules.time_to_die);
	time_print(data);
	printf("%i is died\n", 1);
	exit_clean(data);
	return (EXIT_FAILURE);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
		pthread_mutex_init(&data->forks[i++].mtx_forks, 0);
	return (0);
}

int	run_philo(t_data *data, int ac, char **argv)
{
	parsing_check(data, ac, argv);
	if (ac == 6 && (ft_atoi_long(argv[5]) > 0))
		data->time_rules.ate_max_imposed = TRUE;
	else
		data->time_rules.ate_max_imposed = FALSE;
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->number_of_philo);
	if (!(data->philos))
		return (EXIT_FAILURE);
	data->tid = (pthread_t *)malloc(sizeof(pthread_t) * data->number_of_philo);
	if (!(data->tid))
		return (EXIT_FAILURE);
	data->forks = (t_fork *)malloc(sizeof(t_fork) * data->number_of_philo);
	if (!(data->forks))
		return (EXIT_FAILURE);
	init_mutex(data);
	time_init(data);
	init_forks(data);
	if (data->number_of_philo == 1)
		if (run_one_philo(data))
			return (0);
	data->somebody_is_dead = FALSE;
	init_monitoring(data);
	init_philo(data);
	return (0);
}
