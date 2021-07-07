/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:53:50 by tpalhol           #+#    #+#             */
/*   Updated: 2020/11/30 13:06:58 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			philo_eating(t_philosopher *philo)
{
	sem_wait(philo->eating_state);
	print_state(philo, "is eating");
	sem_post(philo->eating_state);
	philo->count_eat++;
	msleep(philo->args->time_to_eat);
	gettimeofday(&philo->last_meal, NULL);
}

void			*philo_life(void *p)
{
	t_philosopher *philo;

	philo = p;
	while (!philo->all->someone_dead)
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
			if (philo->count_eat == philo->args->nbr_philo_must_eat ||
				philo->all->someone_dead)
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
	int i;

	i = 0;
	gettimeofday(&all->start, NULL);
	pthread_create(&all->controller, NULL, controller, all);
	pthread_detach(all->controller);
	while (i < all->args->nbr_of_philos)
	{
		if (!(i % 2))
			pthread_create(&all->philosophers[i]->thread, NULL,
				philo_life, all->philosophers[i]);
		i++;
	}
	usleep(200);
	i = 0;
	while (i < all->args->nbr_of_philos)
	{
		if ((i % 2))
			pthread_create(&all->philosophers[i]->thread,
				NULL, philo_life, all->philosophers[i]);
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
		{
			free(all->args);
			free(all);
			return (1);
		}
		if (init_semaphores(all))
		{
			free_all(all);
			return (1);
		}
		start_threads(all);
		join_threads(all);
		free_all(all);
	}
	return (0);
}
