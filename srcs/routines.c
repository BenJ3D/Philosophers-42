/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:22:31 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/05 12:58:51 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"


int	philo_taken_fork(t_data *data, int id)
{
	print_pstate_change(STATE_FORK, id, data->philo->tid, data);
	sleep(1);
	//TODO: prendre les fourchettes droite et gauche
	return(0);
}

int	philo_eating(t_data *data, int id)
{
	print_pstate_change(STATE_EATING, id, data->philo->tid, data);
	//usleep(data->time_rules.time_to_eat);
	sleep(1);
	return(0);
}

int	philo_sleeping(t_data *data, int id)
{
	print_pstate_change(STATE_SLEEP, id, data->philo->tid, data);
	//usleep(data->time_rules.time_to_sleep);
	sleep(1);
	return(0);
}

int	philo_thinking(t_data *data, int id)
{
	print_pstate_change(STATE_THINK, id, data->philo->tid, data);
	return(0);
}

int	philo_died(t_data *data, int id)
{
	print_pstate_change(STATE_DIED, id, data->philo->tid, data);
	return(0);
}

