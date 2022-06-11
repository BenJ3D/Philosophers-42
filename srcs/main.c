/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:07:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/11 08:57:00 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

//TODO: if number of philo = 1 ==>> thinks and sleep time life before mutex
int main(int ac, char **argv)
{
	pthread_t id;
	t_data	data;
	
	//printf("arg ac = %i\n", ac);
	if (ac >= 5 && ac <= 6)
		run_philo(&data, ac, argv);
	else if (ac > 6)
		write_error_type(ERROR_NB_ARGS);
	else
		write_error_type(ERROR_MISSING_ARG);
	free(data.philos);
	return (0);
}