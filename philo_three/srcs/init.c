/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:41:29 by tpalhol           #+#    #+#             */
/*   Updated: 2020/11/30 10:43:27 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			init_first(t_all *all)
{
	if (!(all->philosophers = malloc(sizeof(t_philosopher *) *
		all->args->nbr_of_philos)))
		return (error_malloc());
	if (!(all->philosophers[0] = malloc(sizeof(t_philosopher))))
		return (error_malloc());
	all->philosophers[0]->pos = 0;
	return (0);
}

int			init_last(t_all *all, int i)
{
	if (!(all->philosophers[i] = malloc(sizeof(t_philosopher))))
		return (error_malloc());
	all->philosophers[i]->pos = all->args->nbr_of_philos - 1;
	return (0);
}

int			init_table(t_all *all)
{
	int i;

	i = 1;
	if (init_first(all))
		return (1);
	while (i < all->args->nbr_of_philos - 1)
	{
		if (!(all->philosophers[i] = malloc(sizeof(t_philosopher))))
			return (error_malloc());
		all->philosophers[i]->pos = i;
		i++;
	}
	if (init_last(all, i))
		return (1);
	return (0);
}

int			init_semaphores(t_all *all)
{
	int	i;

	i = 0;
	if (!(all->mic = create_semaphore("/mic", 1)))
		return (error_semaphore());
	if (!(all->someonedead = create_semaphore("/someonedead", 0)))
		return (error_semaphore());
	if (!(all->forks = create_semaphore("/forks", all->args->nbr_of_philos)))
		return (error_semaphore());
	while (i < all->args->nbr_of_philos)
	{
		all->philosophers[i]->name = generate_sem_name(all->philosophers[i]);
		if (!(all->philosophers[i]->eating_state =
			create_semaphore(all->philosophers[i]->name, 1)))
			return (error_semaphore());
		gettimeofday(&all->philosophers[i]->last_meal, NULL);
		all->philosophers[i]->all = all;
		all->philosophers[i]->quit = 0;
		all->philosophers[i]->count_eat = 0;
		all->philosophers[i]->args = all->args;
		i++;
	}
	return (0);
}
