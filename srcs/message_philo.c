/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:53:48 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/22 13:50:52 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief print in the standart output a message when a philo changes state
 * 
 * @param state state philo
 * @param pid philo index
 * @param tid thread id
 * @param data 
 * @return int 
 */
int		print_pstate_change(e_state state, int pid, pthread_t tid,
	t_data *data, int dbgfork)
{
	long	time;
	
	time = time_get(data);
	if (data->somebody_is_dead == TRUE)
	{
		pthread_mutex_unlock(&data->mtx_lock_message);
		return (EXIT_FAILURE);
	}
	pthread_mutex_lock(&data->mtx_lock_message);
	time = time_get(data);
	if (data->somebody_is_dead == TRUE)
	{
		pthread_mutex_unlock(&data->mtx_lock_message);
		return (EXIT_FAILURE);
	}
	// gettimeofday(&data->current_time, NULL);
	printf("%ld ms  ", time);
	if (data->philos[pid].last_ate > data->time_rules.time_to_die / 1000)
		state = STATE_DIED;
	if (state == STATE_DIED)
		printf("\033[31m%03i is died (msg_philo:39)\033[0m\n", pid);
	else if (state == STATE_EATING && data->somebody_is_dead == FALSE)
		printf("%03i is eating\n", pid);
	else if (state == STATE_FORK && data->somebody_is_dead == FALSE)
		printf("%03i has taken a fork %i\n", pid, dbgfork);
	else if (state == STATE_SLEEP && data->somebody_is_dead == FALSE)
		printf("%03i is sleeping\n", pid);
	else if (state == STATE_THINK && data->somebody_is_dead == FALSE)
		printf("%03i is thinking\n", pid);
	else if (state == STATE_OVER && data->somebody_is_dead == FALSE)
		printf("%03i over message\n", pid);
	pthread_mutex_unlock(&data->mtx_lock_message);
	return (0);
}
