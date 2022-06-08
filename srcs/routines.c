/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:22:31 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/08 21:50:49 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"


int	philo_taken_fork(t_data *data, int id)
{
	print_pstate_change(STATE_FORK, id, data->philos->tid, data, id);
	usleep(50);
	return(0);
}

int	last_philo_eating(t_data *data, int id)
{
	pthread_mutex_lock(&data->forks[id - 1].mtx_forks);
	data->forks[id - 1].availability = FORK_NOT_AVAILABLE;
	print_pstate_change(STATE_FORK, id, data->philos->tid, data, id - 1);
	pthread_mutex_lock(&data->forks[0].mtx_forks);
	data->forks[id].availability = FORK_NOT_AVAILABLE;
	print_pstate_change(STATE_FORK, id, data->philos->tid, data, 0);

	print_pstate_change(STATE_EATING, id, data->philos->tid, data, 0);
	usleep(data->time_rules.time_to_eat);
	
	data->forks[0].availability = FORK_AVAILABLE;
	data->forks[id - 1].availability = FORK_AVAILABLE;
	pthread_mutex_unlock(&data->forks[0].mtx_forks);
	pthread_mutex_unlock(&data->forks[id - 1].mtx_forks);

	return(0);
}

int	philo_eating(t_data *data, int id)
{
	if (id == data->number_of_philo)
		last_philo_eating(data, id);
	else
	{
		pthread_mutex_lock(&data->forks[id - 1].mtx_forks);
		data->forks[id - 1].availability = FORK_NOT_AVAILABLE;
		print_pstate_change(STATE_FORK, id, data->philos->tid, data, id - 1);

		pthread_mutex_lock(&data->forks[id].mtx_forks);
		data->forks[id].availability = FORK_NOT_AVAILABLE;
		print_pstate_change(STATE_FORK, id, data->philos->tid, data, id);
		data->philos[id - 1].last_ate = get_time(data);
		print_pstate_change(STATE_EATING, id, data->philos->tid, data, 0);
		usleep(data->time_rules.time_to_eat);

		data->forks[id - 1].availability = FORK_AVAILABLE;
		data->forks[id].availability = FORK_AVAILABLE;
		pthread_mutex_unlock(&data->forks[id - 1].mtx_forks);
		pthread_mutex_unlock(&data->forks[id].mtx_forks);
	}

	return(0);
}

int	philo_sleeping(t_data *data, int id)
{
	print_pstate_change(STATE_SLEEP, id, data->philos->tid, data, 0);
	usleep(data->time_rules.time_to_sleep);
	// usleep(50000);
	return(0);
}

int	philo_thinking(t_data *data, int id)
{
	print_pstate_change(STATE_THINK, id, data->philos->tid, data, 0);
	return(0);
}

int	philo_died(t_data *data, int id)
{
	print_pstate_change(STATE_DIED, id, data->philos->tid, data, 0);
	return(0);
}

