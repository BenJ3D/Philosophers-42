/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:00:43 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/23 17:03:14 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int main(int ac, char **argv)
{
	t_data	data;
	
	if (ac >= 5 && ac <= 6)
		run_philo(&data, ac, argv);
	else if (ac > 6)
		write_error_type(ERROR_NB_ARGS);
	else
		write_error_type(ERROR_MISSING_ARG);
//	free(data.philos);
	//exit_clean(&data); //FIXME:
	return (0);
}