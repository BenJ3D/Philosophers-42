/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:53:48 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/23 12:31:22 by bducrocq         ###   ########.fr       */
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
int		print_message(e_state state, int pid, pthread_t tid,
	t_data *data, int dbgfork)
{	
	pthread_mutex_lock(&data->mtx_lock_message);
	printf("%li\t", time_get(data));
	if (state == STATE_EATING && data->somebody_is_dead == FALSE)
	{
		data->philos[pid - 1].last_ate = (time_get(data));
		printf("%i is eating\n", pid);
	}
	else if (state == STATE_DIED)
		printf("%i is died\n", pid);
	else if (state == STATE_FORK && data->somebody_is_dead == FALSE)
		printf("%i has taken a fork %i\n", pid, dbgfork);
	else if (state == STATE_SLEEP && data->somebody_is_dead == FALSE)
		printf("%i is sleeping\n", pid);
	else if (state == STATE_THINK && data->somebody_is_dead == FALSE)
		printf("%i is thinking\n", pid);
	else if (state == STATE_OVER && data->somebody_is_dead == FALSE)
		printf("%i must eat count reached\n", pid);
	// time_print_dbg(data);
	pthread_mutex_unlock(&data->mtx_lock_message);
	if (state == STATE_DIED)
		return (EXIT_FAILURE);
	return (0);
}
