/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:07:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/28 12:01:26 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	time_init(t_data *data)
{
	data->start_time = time_get(data);
	return (0);
}

long int	get_current_millisecond(void)
{
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	return (timeval.tv_sec * 1000 + timeval.tv_usec / 1000);
}

void	ft_usleep(long int time)
{
	long int	start_action;

	start_action = get_current_millisecond();
	while ((get_current_millisecond() - start_action) < time)
		usleep(10);
}

long	time_get(t_data *data)
{
	long	timesec;

	pthread_mutex_lock(&data->mtx_get_time);
	gettimeofday(&data->current_time, NULL);
	timesec = (data->current_time.tv_sec) % 1000000;
	timesec *= 1000;
	timesec += data->current_time.tv_usec / 1000;
	pthread_mutex_unlock(&data->mtx_get_time);
	return (timesec - data->start_time);
}

void	time_print(t_data *data)
{
	gettimeofday(&data->current_time, NULL);
	printf("%lu\t", time_get(data));
}
