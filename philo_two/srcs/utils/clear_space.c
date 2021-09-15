/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:33:14 by hmin              #+#    #+#             */
/*   Updated: 2021/02/27 09:40:40 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

/*
** The sem_close() function may fail if:
**
** [EINVAL]
** The sem argument is not a valid semaphore descriptor.
*/

void	semaphore_close(t_info *info)
{
	if (info->forks != SEM_FAILED)
		sem_close(info->forks);
	if (info->last_eat != SEM_FAILED)
		sem_close(info->last_eat);
	if (info->l_check != SEM_FAILED)
		sem_close(info->l_check);
	if (info->write != SEM_FAILED)
		sem_close(info->write);
	if (info->take != SEM_FAILED)
		sem_close(info->take);
	semaphore_unlink();
}

void	clear_space(t_info *info, t_philo **phi)
{
	semaphore_close(info);
	if (*phi)
		free(*phi);
}
