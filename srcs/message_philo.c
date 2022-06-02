/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:53:48 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/02 20:17:17 by bducrocq         ###   ########.fr       */
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

	if (state == STATE_DIED)
		printf("timestamp_in_ms %i is eating\n", pid);
	else if (state == STATE_EATING)
		printf("timestamp_in_ms %i has taken a fork\n", pid);
	else if (state == STATE_FORK)
		printf("timestamp_in_ms %i is eating\n", pid);
	else if (state == STATE_SLEEP)
		printf("timestamp_in_ms %i is sleeping\n", pid);
	else if (state == STATE_THINK)
		printf("timestamp_in_ms %i is thinking\n", pid);
	else if (state == STATE_OVER)
		printf("over message\n", pid);
	return (0);
} 
