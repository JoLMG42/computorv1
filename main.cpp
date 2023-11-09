/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:33:29 by jtaravel          #+#    #+#             */
/*   Updated: 2023/11/09 19:21:02 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>
#include "Poly.hpp"
#include <stdlib.h>
#include <string>
#include <fstream>

int	forTester(std::string arg)
{

	std::cout << "\n\nTesting for arg: " << arg << "\n\n";
	Poly polyLeft;
	Poly polyRight;

	std::string oh(arg);
	std::deque<std::string> recupPoly = splitStart(oh, "=");

	if (!checkFormat((char *)(recupPoly.begin())->c_str(), &polyLeft))
	{
		std::cout << "Wrong format\n";
		return (0);
	}
	if (recupPoly.size() > 1)
	{
		std::deque<std::string>::iterator itEnd = recupPoly.end();
		itEnd--;
		if (!checkFormat((char *)((*itEnd).c_str()), &polyRight))
		{
			std::cout << "Wrong format\n";
			return (0);
		}
	}
	reducedForm(&polyLeft, &polyRight);
	return (1);
}

int	main(int ac, char **av)
{
	if (TESTER == 1)
	{
		std::ifstream file("tester.txt", std::ios::in);
		if (!file)
		{
			std::cout << "File error\n";
			return (0);
		}
		else
		{
			std::string recup;
			while (getline(file, recup))
			{
				if (!forTester(recup))
					return (0);
			}
			file.close();
		}
		return (0);
	}
	Poly polyLeft;
	Poly polyRight;
	if (ac != 2)
	{
		std::cout << "Wrong number of arguments\n";
		return (0);
	}
	std::string oh(av[1]);
	std::deque<std::string> recupPoly = splitStart(oh, "=");
	if (recupPoly.size() != 1 && recupPoly.size() != 2)
	{
		std::cout << "Wrong format\n";
		return (0);
	}

	if (BONUS == 1)
		std::cout << "Left Part = " << *(recupPoly.begin()) << "\n";
	if (!checkFormat((char *)(recupPoly.begin())->c_str(), &polyLeft))
	{
		std::cout << "Wrong format\n";
		return (0);
	}
	if (recupPoly.size() > 1)
	{
		std::deque<std::string>::iterator itEnd = recupPoly.end();
		itEnd--;
		if (BONUS == 1)
			std::cout << "Right Part = " << (*itEnd) << "\n";
		if (!checkFormat((char *)((*itEnd).c_str()), &polyRight))
		{
			std::cout << "Wrong format\n";
			return (0);
		}
	}
	reducedForm(&polyLeft, &polyRight);
}
