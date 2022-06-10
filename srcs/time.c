/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:07:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/10 15:19:46 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	time_init(t_data *data)
{
	gettimeofday(&data->current_time, NULL);
	printf("time is : %lu\n", time_get(data));	//FIXME:
	return (0);
}

void	time_print(t_data *data)
{
	long long timeusec;
	
	gettimeofday(&data->current_time, NULL);
	timeusec = (data->current_time.tv_sec) % 1000000;
	timeusec *= 1000;
	timeusec += data->current_time.tv_usec / 1000;
	printf("%lld || %06d\n", timeusec, data->current_time.tv_usec);
}

long	time_get(t_data *data)
{
	long timesec;
	
	gettimeofday(&data->current_time, NULL);
	timesec = (data->current_time.tv_sec) % 1000000;
	timesec *= 1000;
	timesec += data->current_time.tv_usec / 1000;
	return (timesec);
}