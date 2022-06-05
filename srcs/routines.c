/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:22:31 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/05 17:12:53 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"


int	philo_taken_fork(t_data *data, int id)
{
	print_pstate_change(STATE_FORK, id, data->philos->tid, data);
	usleep(50);
	//TODO: prendre les fourchettes droite et gauche
	return(0);
}

int	philo_eating(t_data *data, int id)
{
	pthread_mutex_lock(&data->forks[id].mtx_forks);
	data->forks[id].availability = FORK_NOT_AVAILABLE;
	if (id != data->number_of_philo)
	{
		pthread_mutex_lock(&data->forks[id + 1].mtx_forks);
		data->forks[id + 1].availability = FORK_NOT_AVAILABLE;
	}
	else
	{
		pthread_mutex_lock(&data->forks[0].mtx_forks);
		data->forks[0].availability = FORK_NOT_AVAILABLE;
	}
	print_pstate_change(STATE_EATING, id, data->philos->tid, data);
	usleep(data->time_rules.time_to_eat);
	pthread_mutex_unlock(&data->forks[id + 1].mtx_forks);
	if (id != data->number_of_philo)
	{
		pthread_mutex_unlock(&data->forks[id + 1].mtx_forks);
		data->forks[id + 1].availability = FORK_AVAILABLE;
	}
	else
	{
		pthread_mutex_unlock(&data->forks[0].mtx_forks);
		data->forks[0].availability = FORK_AVAILABLE;
	}
	return(0);
}

int	philo_sleeping(t_data *data, int id)
{
	print_pstate_change(STATE_SLEEP, id, data->philos->tid, data);
	usleep(data->time_rules.time_to_sleep);
	// usleep(50000);
	return(0);
}

int	philo_thinking(t_data *data, int id)
{
	print_pstate_change(STATE_THINK, id, data->philos->tid, data);
	return(0);
}

int	philo_died(t_data *data, int id)
{
	print_pstate_change(STATE_DIED, id, data->philos->tid, data);
	return(0);
}

