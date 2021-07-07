/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_forks.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:17:37 by tpalhol           #+#    #+#             */
/*   Updated: 2020/11/25 16:20:50 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_FORKS_H
# define STRUCT_FORKS_H
# include <pthread.h>

typedef struct			s_fork
{
	pthread_mutex_t		mutex;
}						t_fork;

#endif
