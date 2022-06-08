/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:07:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/08 21:51:40 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

double	get_time(t_data	*data)
{
	double	time;
	
	gettimeofday(&data->current_time, NULL);
	time = (data->current_time.tv_sec) * 1000 + (data->current_time.tv_usec) / 1000;
	printf("time is : %lf", time);	
	
}

int	init_time(t_data *data)
{
	double time;
	gettimeofday(&data->current_time, NULL);
	data->start_sec = data->current_time.tv_sec;
	data->start_usec = data->current_time.tv_usec;

	
	// printf("timestamp start = : %04ld ms = %03i\n", data->current_time.tv_sec % 1000,\
	// data->current_time.tv_usec / 1000);
	get_time(data);
	return (0);
}