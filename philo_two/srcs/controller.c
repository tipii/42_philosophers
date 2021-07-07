/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:54:28 by tpalhol           #+#    #+#             */
/*   Updated: 2020/11/26 14:38:47 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		check_death_condition(t_philosopher *philo)
{
	t_timeval now;

	gettimeofday(&now, NULL);
	if (diff_ms(now, philo->last_meal) > philo->args->time_to_die)
		return (1);
	else
		return (0);
}

void	*controller(void *a)
{
	t_all	*all;
	int		i;

	i = 0;
	all = a;
	while (!all->someone_dead)
	{
		while (i < all->args->nbr_of_philos)
		{
			sem_wait(all->philosophers[i]->eating_state);
			if (check_death_condition(all->philosophers[i]))
			{
				print_state(all->philosophers[i], "died");
				all->philosophers[i]->quit = 1;
				all->someone_dead = 1;
			}
			sem_post(all->philosophers[i]->eating_state);
			usleep(500);
			i++;
		}
		i = 0;
	}
	return (NULL);
}
