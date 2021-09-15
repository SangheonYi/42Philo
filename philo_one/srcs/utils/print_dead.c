/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:46:11 by hmin              #+#    #+#             */
/*   Updated: 2021/02/22 13:26:45 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	print_dead(t_philo *phi, char *str, int n)
{
	ft_putnbr_light(cur_time() - phi->t_start);
	write(1, " ", 1);
	ft_putnbr_light(phi->name);
	write(1, " ", 1);
	write(1, str, n);
}
