/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:53:50 by tpalhol           #+#    #+#             */
/*   Updated: 2020/11/30 13:18:17 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

void			philo_eating(t_philosopher *philo)
{
	sem_wait(philo->eating_state);
	print_state(philo, "is eating");
	sem_post(philo->eating_state);
	philo->count_eat++;
	msleep(philo->args->time_to_eat);
	gettimeofday(&philo->last_meal, NULL);
}

int				philo_ate_enough(t_philosopher *philo)
{
	if (philo->count_eat == philo->args->nbr_philo_must_eat)
	{
		sem_post(philo->all->someonedead);
		if (philo->all->args->nbr_philo_must_eat == -1)
			sem_wait(philo->all->mic);
		return (1);
	}
	return (0);
}

void			*philo_life(void *p)
{
	t_philosopher *philo;

	philo = p;
	pthread_create(&philo->controller, NULL, controller, philo);
	pthread_detach(philo->controller);
	while (1)
	{
		sem_wait(philo->all->forks);
		print_state(philo, "has taken a fork");
		sem_wait(philo->all->forks);
		print_state(philo, "has taken a fork");
		if (!philo->quit)
		{
			philo_eating(philo);
			sem_post(philo->all->forks);
			sem_post(philo->all->forks);
			if (philo_ate_enough(philo))
				break ;
			print_state(philo, "is sleeping");
			msleep(philo->args->time_to_sleep);
			print_state(philo, "is thinking");
		}
	}
	return (NULL);
}

void			start_threads(t_all *all)
{
	int				i;
	t_philosopher	*philo;

	i = 0;
	while (i < all->args->nbr_of_philos)
	{
		philo = all->philosophers[i];
		philo->pid = fork();
		if (philo->pid < 0)
		{
			ft_putstr_fd("A fork have failed", 2);
			free_all(all);
			exit(1);
		}
		else if (philo->pid == 0)
		{
			philo_life(philo);
			exit(0);
		}
		i++;
	}
}

int				main(int argc, char **argv)
{
	t_all	*all;

	all = NULL;
	if (!(all = init_all(all)))
		return (1);
	if (basic_args_check(argc, argv))
	{
		fill_with_args(all->args, argc, argv);
		if (init_table(all))
			return (free_before_philos(all));
		if (init_semaphores(all))
		{
			free_all(all);
			return (1);
		}
		gettimeofday(&all->start, NULL);
		start_threads(all);
		wait_end(all);
		free_all(all);
	}
	return (0);
}
