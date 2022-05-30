/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:07:14 by bducrocq          #+#    #+#             */
/*   Updated: 2022/05/30 14:59:38 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/philosophers.h"

int	run_philo(t_data *data, int ac, char **argv)
{
	parsing_check(data, ac, argv);
	dbg_print_rules(data); //FIXME:
	if(!(data->philo = malloc(sizeof(t_philo) * data->number_of_philo + 1)))
		exit(EXIT_FAILURE);
	return (0);
}

int main(int ac, char **argv)
{
	pthread_t id;
	t_data	data;
	
	printf("arg ac = %i\n", ac);
	if (ac >= 5 && ac <= 6)
		run_philo(&data, ac, argv);
	else if (ac > 6)
		write_error_type(ERROR_NB_ARGS);
	else
		write_error_type(ERROR_MISSING_ARG);
	free(data.philo);
	return (0);
}