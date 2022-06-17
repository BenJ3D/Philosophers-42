/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:21:24 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/17 14:32:54 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_mutex_destroy(&data->forks[i].mtx_forks);
		i++;
	}
	pthread_mutex_destroy(&data->mtx_lock_message);
	free(data->philos);
	free(data->forks);
	return(0);
}

int	exit_clean(t_data *data)
{
	free_all(data);
	return (0);
}