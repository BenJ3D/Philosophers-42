/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:22:31 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/26 15:53:03 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// int	philo_eating_dbg(t_data *data, int id)
// {
// 	int	forkrid;

// 	forkrid = id;
// 	if (id == data->number_of_philo)
// 		forkrid = 0;
// 	pthread_mutex_lock(&data->forks[id - 1].mtx_forks);
// 	data->forks[id - 1].availability = FORK_NOT_AVAILABLE;
// 	print_message(STATE_FORK, id, data->philos->tid, data, id - 1);
// 	pthread_mutex_lock(&data->forks[forkrid].mtx_forks);
// 	data->forks[forkrid].availability = FORK_NOT_AVAILABLE;
// 	print_message(STATE_FORK, id, data->philos->tid, data, id);
// 	print_message(STATE_EATING, id, data->philos->tid, data, 0);
// 	usleep(data->time_rules.time_to_eat);
// 	data->forks[id - 1].availability = FORK_AVAILABLE;
// 	data->forks[forkrid].availability = FORK_AVAILABLE;
// 	pthread_mutex_unlock(&data->forks[id - 1].mtx_forks);
// 	pthread_mutex_unlock(&data->forks[forkrid].mtx_forks);
// 	if (data->time_rules.ate_max_imposed == TRUE)
// 		data->philos[id - 1].ate_nb++;
// 	if (data->somebody_is_dead == TRUE)
// 		return (EXIT_FAILURE);
// 	return (0);
// }

int	philo_eating(t_data *data, int id)
{
	int	forkrid;

	forkrid = id;
	if ((id) == data->number_of_philo)
	{	
		// printf("je suis le dernier philo %i\n", id);
		forkrid = 0;
	}
						// printf("forkid = %i\n", forkrid);
	pthread_mutex_lock(&data->forks[id - 1].mtx_forks);
	print_message(STATE_FORK, id, data->philos->tid, data);
						// printf("\033[31m%i\033[0m\n", id - 1);			//FIXME:
	pthread_mutex_lock(&data->forks[forkrid].mtx_forks);
	print_message(STATE_FORK, id, data->philos->tid, data);
						// printf("forkid middle= %i\n", forkrid);
						// printf("\033[31m%i\033[0m\n", forkrid);			//FIXME:
	print_message(STATE_EATING, id, data->philos->tid, data);
	usleep(data->time_rules.time_to_eat);
	pthread_mutex_unlock(&data->forks[id - 1].mtx_forks);
	pthread_mutex_unlock(&data->forks[forkrid].mtx_forks);
	if (data->time_rules.ate_max_imposed == TRUE)
		data->philos[id - 1].ate_nb++;
	if (data->somebody_is_dead == TRUE)
		return (EXIT_FAILURE);
						// printf("forkid fin= %i\n", forkrid);
	return (0);
}

// int	philo_eating(t_data *data, int id)
// {
// 	int	forkrid;

// 	forkrid = id;
// 	if ((id) == data->number_of_philo)
// 		forkrid = 0;
// 	pthread_mutex_lock(&data->forks[id - 1].mtx_forks);
// 	print_message(STATE_FORK, id, data->philos->tid, data);
// 	pthread_mutex_lock(&data->forks[forkrid].mtx_forks);
// 	print_message(STATE_FORK, id, data->philos->tid, data);
// 	print_message(STATE_EATING, id, data->philos->tid, data);
// 	usleep(data->time_rules.time_to_eat);
// 	pthread_mutex_unlock(&data->forks[id - 1].mtx_forks);
// 	pthread_mutex_unlock(&data->forks[forkrid].mtx_forks);
// 	if (data->time_rules.ate_max_imposed == TRUE)
// 		data->philos[id - 1].ate_nb++;
// 	if (data->somebody_is_dead == TRUE)
// 		return (EXIT_FAILURE);
// 	return (0);
// }

int	philo_sleeping(t_data *data, int id)
{
	print_message(STATE_SLEEP, id, data->philos->tid, data);
	usleep(data->time_rules.time_to_sleep);
	return (0);
}

int	philo_thinking(t_data *data, int id)
{	
	print_message(STATE_THINK, id, data->philos->tid, data);
	return (0);
}

long	philo_check_is_died(t_data *data, int id)
{
	long	res_last_ate;

	res_last_ate = ((data->philos[id - 1].last_ate - time_get(data)) * -1);
	if ((res_last_ate) > data->time_rules.time_to_die / 1000)
	{
		data->philos[id - 1].is_died = TRUE;
		data->somebody_is_dead = TRUE;
		print_message(STATE_DIED, id, data->philos->tid, data);
	}
	return (res_last_ate);
}
