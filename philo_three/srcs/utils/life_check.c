/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 02:31:02 by hmin              #+#    #+#             */
/*   Updated: 2021/02/26 13:38:42 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <stdio.h>

void	life_check(t_philo *phi)
{
	ssize_t		starved_time;

	while (1)
	{
		sem_wait(phi->info->last_eat);
		starved_time = cur_time() - phi->last_eat;
		sem_post(phi->info->last_eat);
		if (starved_time >= phi->info->rules[T_DIE])
			dead_status(phi);
		if (phi->info->dead_phi || phi->must_eat == 0)
			return ;
		usleep(1);
	}
}
