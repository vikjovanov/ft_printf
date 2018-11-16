/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:11:46 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/16 20:21:16 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** NAME:
** 	ft_printf
**
** DESCRIPTION:
**	ft_print() affiche a l'ecran la chaine de caractere 'format' avec les 
**	differents parametres recus.
**
** SYNOPSIS:
**	int ft_printf(const char *format, ...)
**
** PARAMS:
** 	format - La chaine de caractere a formater
**	... - parametres permettant le formatage de la chaine de caractere
**
** RETURN VALUE:
**	(int) le nombre de caractere ecrits. Si une erreur est survenue, 
**	retourne une valeur negative.
*/
#include <stdio.h>
#include <stdarg.h>
int		ft_printf(const char *format, ...)
{
	va_list ap;
	void* a;

	va_start(ap, format);
	a = va_arg(ap, char*);
	va_end(ap);
	printf("%p\n", a);
	printf("%c\n", *((char*)a + 2));
	return 0;
}

int		main()
{
	ft_printf("Salut", "Salut");
	return 0;
}