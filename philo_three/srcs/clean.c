/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:42:35 by tpalhol           #+#    #+#             */
/*   Updated: 2020/11/30 13:19:35 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		free_all(t_all *all)
{
	int i;

	i = 0;
	while (i < all->args->nbr_of_philos)
	{
		sem_unlink(all->philosophers[i]->name);
		sem_close(all->philosophers[i]->eating_state);
		free(all->philosophers[i]->name);
		free(all->philosophers[i]);
		i++;
	}
	free(all->philosophers);
	sem_unlink("/mic");
	sem_close(all->mic);
	sem_unlink("/forks");
	sem_close(all->forks);
	sem_unlink("/someonedead");
	sem_close(all->someonedead);
	free(all->args);
	free(all);
}

int			free_before_philos(t_all *all)
{
	free(all->args);
	free(all);
	return (1);
}

void		kill_process(t_all *all)
{
	int i;

	i = 0;
	while (i < all->args->nbr_of_philos)
	{
		kill(all->philosophers[i]->pid, SIGTERM);
		i++;
	}
}

void		wait_end(t_all *all)
{
	int status;
	int i;

	i = 0;
	sem_wait(all->someonedead);
	if (all->args->nbr_philo_must_eat != -1)
		msleep(all->args->time_to_die);
	kill_process(all);
	while (i < all->args->nbr_of_philos)
	{
		waitpid(all->philosophers[i]->pid, &status, 0);
		i++;
	}
}
