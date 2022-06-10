/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testtime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:04:27 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/10 15:15:51 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosophers.h"

unsigned long	get_time(t_data	*data)
{
	unsigned long long	time;
	
	gettimeofday(&data->current_time, NULL);
	time = (data->current_time.tv_sec) /*+ (data->current_time.tv_usec / 1000)*/;
	printf("time is : %llu | %li", time, (data->current_time.tv_sec));	
	
	return (time);
}

int	init_time(t_data *data)
{
	double time;
	gettimeofday(&data->current_time, NULL);
	data->start_sec = data->current_time.tv_sec;

	printf("timestamp start = : %04ld ms = %03i\n", data->current_time.tv_sec % 1000,\
		data->current_time.tv_usec / 1000);
	get_time(data);
	return (0);
}

int main()
{
	t_data	data;

	while(1)
	{
		long long timeusec;

		gettimeofday(&data.current_time, NULL);
		timeusec = (data.current_time.tv_sec) % 1000000;
		timeusec *= 1000;
		timeusec += data.current_time.tv_usec / 1000;
		printf("%lld || %06d\n", timeusec, data.current_time.tv_usec);
		usleep(100000);
	}	
	// printf("timestamp start = : %04ld ms = %03i\n", data.current_time.tv_sec % 1000, data.current_time.tv_usec / 1000);
	
	return (0);
}