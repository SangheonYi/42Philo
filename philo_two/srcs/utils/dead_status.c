/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:44:53 by hmin              #+#    #+#             */
/*   Updated: 2021/02/23 09:17:50 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	dead_status(t_philo *phi)
{
	phi->info->dead_phi = phi->name;
	sem_wrap_writing(phi, DEAD, 8, print_dead);
}
