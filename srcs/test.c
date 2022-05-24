/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:36:42 by bducrocq          #+#    #+#             */
/*   Updated: 2022/05/24 14:51:50 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"



int	init_thread(t_data *data)
{
	data->i = 1;
	pthread_create(data->thread1,)
	
	printf("Hello !\nI'm thread number %i !\n", data->i);
	return(0);
}

int main()
{
	t_data	data;

	printf("Hello World !\nI'm main thread !\n");
	init_thread(&data);
	return (0);
}