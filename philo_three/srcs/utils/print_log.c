/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:54:56 by sayi              #+#    #+#             */
/*   Updated: 2021/02/27 12:54:58 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	print_log(t_philo *phi, char *str, int n)
{
	if (phi->info->dead_phi || !phi->must_eat)
		return ;
	ft_putnbr_light(cur_time() - phi->t_start);
	write(1, " ", 1);
	ft_putnbr_light(phi->name);
	write(1, " ", 1);
	write(1, str, n);
}
