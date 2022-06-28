/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:11:53 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/28 14:12:12 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	init_mutex(t_data *data)
{
	pthread_mutex_init(&data->mtx_lock_message, 0);
	pthread_mutex_init(&data->mtx_get_time, 0);
	pthread_mutex_init(&data->mtx_lock_m1, 0);
	return (0);
}
