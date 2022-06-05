/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:53:48 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/05 12:52:36 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * @brief print in the standart output a message when a philo changes state
 * 
 * @param state state philo
 * @param pid philo id
 * @param tid thread id
 * @param data 
 * @return int 
 */
int		print_pstate_change(e_state state, int pid, pthread_t tid,
	t_data *data)
{
	printf("tu es le philo num : %i\n", pid);
//	pthread_mutex_lock(&data->mtx_lock_message);
	gettimeofday(&data->current_time, NULL);
//	pthread_mutex_lock(&data->mtx_lock_message);
	printf("%04ld%03i ms  ", data->current_time.tv_sec % 10000,\
		data->current_time.tv_usec / 1000);
	if (state == STATE_DIED)
		printf("%i is eating\n", pid);
	else if (state == STATE_EATING)
		printf("%i has taken a fork\n", pid);
	else if (state == STATE_FORK)
		printf("%i is eating\n", pid);
	else if (state == STATE_SLEEP)
		printf("%i is sleeping\n", pid);
	else if (state == STATE_THINK)
		printf("%i is thinking\n", pid);
	else if (state == STATE_OVER)
		printf("%i over message\n", pid);
	return (0);
} 
