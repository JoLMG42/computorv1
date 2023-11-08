/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:33:29 by jtaravel          #+#    #+#             */
/*   Updated: 2023/11/08 15:37:04 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>
#include "Poly.hpp"
#include <stdlib.h>

int	main(int ac, char **av)
{
	Poly polyLeft;
	Poly polyRight;
	if (ac != 2)
	{
		std::cout << "Wrong number of arguments\n";
		return (0);
	}
	std::string oh(av[1]);
	std::deque<std::string> recupPoly = splitStart(oh, "=");

	if (BONUS == 1)
		std::cout << "left Part = " << *(recupPoly.begin()) << "\n";
	if (!checkFormat((char *)(recupPoly.begin())->c_str(), &polyLeft))
	{
		std::cout << "Wrong format\n";
		return (0);
	}
	std::deque<std::string>::iterator itEnd = recupPoly.end();
	itEnd--;
	if (BONUS == 1)
		std::cout << "Right Part = " << (*itEnd) << "\n";
	if (!checkFormat((char *)((*itEnd).c_str()), &polyRight))
	{
		std::cout << "Wrong format\n";
		return (0);
	}
	reducedForm(&polyLeft, &polyRight);
}
