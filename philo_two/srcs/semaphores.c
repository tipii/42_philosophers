/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:56:15 by tpalhol           #+#    #+#             */
/*   Updated: 2020/11/30 13:28:13 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char		*generate_sem_name(t_philosopher *philo)
{
	char *name;

	name = malloc(sizeof(char) * 3);
	name[0] = '/';
	name[1] = philo->pos + 48;
	name[2] = 0;
	return (name);
}

sem_t		*create_semaphore(char *name, int i)
{
	sem_t	*result;

	sem_unlink(name);
	result = sem_open(name, O_CREAT | O_EXCL, 0600, i);
	return (result);
}
