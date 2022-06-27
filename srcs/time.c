/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:07:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/27 15:19:04 by bducrocq         ###   ########.fr       */
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

	gettimeofday(&data->current_time, NULL);
	timesec = (data->current_time.tv_sec) % 1000000;
	timesec *= 1000;
	timesec += data->current_time.tv_usec / 1000;
	return (timesec - data->start_time);
}

void	time_print(t_data *data)
{
	gettimeofday(&data->current_time, NULL);
	printf("%lu\t", time_get(data));
}

void	time_print_dbg(t_data *data)
{
	printf("\n%lu\n", time_get(data));
}
