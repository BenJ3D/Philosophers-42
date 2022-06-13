/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:53:48 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/14 00:35:42 by bducrocq         ###   ########.fr       */
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
	pthread_mutex_lock(&data->mtx_lock_message);
	gettimeofday(&data->current_time, NULL);
	printf("%ld ms  ", time_get(data));
	if (state == STATE_DIED)
		printf("%03i is died (msg_philo:31)\n", pid);
	else if (state == STATE_EATING)
	{
		printf("last time ate %li  - time get %li = %li || %li \n", data->philos[pid - 1].last_ate,
			   time_get(data), (data->philos[pid - 1].last_ate - time_get(data)), data->time_rules.time_to_die);

		printf("\033[31mpid message = %i\033[0m\n\n", pid);
		printf("\033[31m philo %i a manger %i fois\033[0m\n", pid, data->philos[pid - 1].ate_nb);
		if (data->philos[pid - 1].ate_nb > data->time_rules.max_philo_must_eat)
			printf("\033[31m ALERTE PHILO %i A DEPASSER LE NOMBRES DE REPAS %i (max = %i)\n\033[0m", pid, \
			data->philos[pid - 1].ate_nb, data->time_rules.max_philo_must_eat);
			
		printf("%03i is eating\n", pid);
	}
	else if (state == STATE_FORK)
		printf("%03i has taken a fork %i\n", pid, dbgfork);
	else if (state == STATE_SLEEP)
		printf("%03i is sleeping\n", pid);
	else if (state == STATE_THINK)
		printf("%03i is thinking\n", pid);
	else if (state == STATE_OVER)
		printf("%03i over message\n", pid);
	pthread_mutex_unlock(&data->mtx_lock_message);
	return (0);
}
