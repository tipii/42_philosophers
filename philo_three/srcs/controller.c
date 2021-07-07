/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:54:28 by tpalhol           #+#    #+#             */
/*   Updated: 2020/11/30 11:34:24 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

void	print_final_state(t_philosopher *philo, char *str)
{
	sem_wait(philo->all->mic);
	ft_putnbr_fd(get_time_since_start(philo->all->start), 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->pos + 1, 1);
	write(1, " ", 1);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
}

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
	t_philosopher	*philo;

	philo = a;
	while (1)
	{
		sem_wait(philo->eating_state);
		if (check_death_condition(philo))
		{
			print_final_state(philo, "died");
			sem_post(philo->all->someonedead);
			exit(0);
			break ;
		}
		sem_post(philo->eating_state);
		usleep(200);
	}
	return (NULL);
}
