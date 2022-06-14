/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:22:31 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/14 17:09:03 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	philo_taken_fork(t_data *data, int id)
{
	print_pstate_change(STATE_FORK, id, data->philos->tid, data, id);
	//usleep(50);
	return(0);
}

/**
 * @brief 
 * 
 * @param data 
 * @param id index philo
 * @return int 
 */
int	last_philo_eating(t_data *data, int id)
{
	pthread_mutex_lock(&data->forks[id - 1].mtx_forks);
	data->forks[id - 1].availability = FORK_NOT_AVAILABLE;
	print_pstate_change(STATE_FORK, id, data->philos->tid, data, id - 1);
	pthread_mutex_lock(&data->forks[0].mtx_forks);
	data->forks[id].availability = FORK_NOT_AVAILABLE;
	print_pstate_change(STATE_FORK, id, data->philos->tid, data, 0);
	data->philos[id - 1].last_ate = time_get(data); // ET ICIIIIIIIIIIIIIIIIIIIIIIIIIIII
	print_pstate_change(STATE_EATING, id, data->philos->tid, data, 0);
	usleep(data->time_rules.time_to_eat);
	data->forks[0].availability = FORK_AVAILABLE;
	data->forks[id - 1].availability = FORK_AVAILABLE;
	pthread_mutex_unlock(&data->forks[0].mtx_forks);
	pthread_mutex_unlock(&data->forks[id - 1].mtx_forks);
	if (data->time_rules.ate_max_imposed == TRUE)
		data->philos[id - 1].ate_nb++;
	return(0);
}

// void print_last_eat(t_data *data,  )

int	philo_eating(t_data *data, int id)
{
	long	res_last_ate;
	
	pthread_mutex_lock(&data->mtx_lock_message);
	res_last_ate = ((data->philos[id - 1].last_ate - time_get(data)) * -1);
	printf("res last ate = %li\n", res_last_ate);
	pthread_mutex_unlock(&data->mtx_lock_message);
	if((res_last_ate * 1000) > data->time_rules.time_to_die)
	{
		pthread_mutex_lock(&data->mtx_lock_message);
		printf("\033[31mIL EST MORT !!!!!!!!!!!!!!!!!!!!!!\033[0m\n");
		print_pstate_change(STATE_DIED, id, data->philos->tid, data, 0);
		exit_clean(data);
		pthread_mutex_unlock(&data->mtx_lock_message);
		return (-1);
	}
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
				data->philos[id - 1].last_ate = time_get(data); // ET ICIIIIIIIIIIIIIIIIIIIIIIIIIIII
		print_pstate_change(STATE_EATING, id, data->philos->tid, data, 0);
		usleep(data->time_rules.time_to_eat);
		data->forks[id - 1].availability = FORK_AVAILABLE;
		data->forks[id].availability = FORK_AVAILABLE;
		pthread_mutex_unlock(&data->forks[id - 1].mtx_forks);
		pthread_mutex_unlock(&data->forks[id].mtx_forks);
		if (data->time_rules.ate_max_imposed == TRUE)
			data->philos[id - 1].ate_nb++;
	}
	return(0);
}

int	philo_sleeping(t_data *data, int id)
{
	print_pstate_change(STATE_SLEEP, id, data->philos->tid, data, 0);
	usleep(data->time_rules.time_to_sleep);
	return(0);
}

int	philo_thinking(t_data *data, int id)
{
	print_pstate_change(STATE_THINK, id, data->philos->tid, data, 0);
	return(0);
}

int	philo_check_is_died(t_data *data, int id)
{
	
	print_pstate_change(STATE_DIED, id, data->philos->tid, data, 0);
	return(0);
}

