/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:22:31 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/23 19:02:12 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	philo_eating(t_data *data, int id)
{
	int	forkrid;
	
	forkrid = id;
	if ((id) == data->number_of_philo)
		forkrid = 0;
	pthread_mutex_lock(&data->forks[id - 1].mtx_forks);
	//data->forks[id - 1].availability = FORK_NOT_AVAILABLE;
	print_message(STATE_FORK, id, data->philos->tid, data, id - 1);
	pthread_mutex_lock(&data->forks[forkrid].mtx_forks);
	//data->forks[forkrid].availability = FORK_NOT_AVAILABLE;
	print_message(STATE_FORK, id, data->philos->tid, data, forkrid);
	print_message(STATE_EATING, id, data->philos->tid, data, 0);
	usleep(data->time_rules.time_to_eat); //FIXME:
	//data->forks[id - 1].availability = FORK_AVAILABLE;
	//data->forks[forkrid].availability = FORK_AVAILABLE;
	pthread_mutex_unlock(&data->forks[id - 1].mtx_forks);
	pthread_mutex_unlock(&data->forks[forkrid].mtx_forks);
	if (data->time_rules.ate_max_imposed == TRUE)
		data->philos[id - 1].ate_nb++;
	if (data->somebody_is_dead == TRUE)
		return (EXIT_FAILURE);
	return (0);
}

int	philo_sleeping(t_data *data, int id)
{

	print_message(STATE_SLEEP, id, data->philos->tid, data, 0);
	usleep(data->time_rules.time_to_sleep);
	return(0);
}

int	philo_thinking(t_data *data, int id)
{	
	print_message(STATE_THINK, id, data->philos->tid, data, 0);
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
		print_message(STATE_DIED, id, data->philos->tid, data, 0);
	}
	//printf("\033[31m%03i res last ate mtx= %li\n\033[0m", id, res_last_ate);
	return(res_last_ate);
}