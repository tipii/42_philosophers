/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_all.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:06:47 by tpalhol           #+#    #+#             */
/*   Updated: 2020/11/30 11:18:49 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_ALL_H
# define STRUCT_ALL_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <semaphore.h>

typedef struct s_philosopher	t_philosopher;
typedef struct timeval	t_timeval;
typedef struct s_fork	t_fork;
typedef struct s_args	t_args;

typedef struct			s_all
{
	t_timeval			start;
	t_args				*args;
	t_philosopher		**philosophers;
	sem_t				*mic;
	sem_t				*forks;
	sem_t				*someonedead;
}						t_all;

#endif
