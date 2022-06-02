/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:22:31 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/02 20:15:51 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"


int	philo_taken_fork(t_data *data)
{
	print_pstate_change(STATE_FORK, data->philo->id, data->philo->tid, data);
	//TODO: prendre les fourchettes droite et gauche
	return(0);
}

int	philo_eating(t_data *data)
{
	print_pstate_change(STATE_EATING, data->philo->id, data->philo->tid, data);
	usleep(data->time_rules.time_to_eat);
	return(0);
}

int	philo_sleeping(t_data *data)
{
	print_pstate_change(STATE_SLEEP, data->philo->id, data->philo->tid, data);
	usleep(data->time_rules.time_to_sleep);
	return(0);
}

int	philo_thinking(t_data *data)
{
	print_pstate_change(STATE_THINK, data->philo->id, data->philo->tid, data);
	return(0);
}

int	philo_died(t_data *data)
{
	print_pstate_change(STATE_DIED, data->philo->id, data->philo->tid, data);
	
	return(0);
}

