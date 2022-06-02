/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:21:24 by bducrocq          #+#    #+#             */
/*   Updated: 2022/06/02 19:23:30 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	free_all(t_data	*data)
{
	
	return(0);
}

void	exit_clean(t_data	*data)
{
	free_all(data);
	exit(0);
}