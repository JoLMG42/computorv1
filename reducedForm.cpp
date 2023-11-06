/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reducedForm.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:41:18 by jtaravel          #+#    #+#             */
/*   Updated: 2023/11/06 18:14:38 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Poly.hpp"
#include <algorithm>
#include <sstream>

void	reducedForm(Poly *polyLeft, Poly *polyRight)
{
	std::cout << "\n\n\nIN REDUCED FUNCTION\n\n\n";

	std::cout << "Poly Left = " << polyLeft->getExpr() << "\n";
	std::cout << "Poly Right = " << polyRight->getExpr() << "\n";

	std::vector<std::string> vec = polyRight->getFactors();
	for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::vector<std::string>::iterator tmp(it);
		tmp++;
		if (tmp != vec.end())
			std::cout << "lol\n\n\n";
		else if (tmp == vec.end())
		{
			std::vector<std::string> vecFac(polyLeft->getFactors());
			std::vector<int> vecPow(polyLeft->getPowers());
			std::cout << "lalalala = " << *it << "\n";
			vecFac.push_back("-");
			vecFac.push_back(*it);
			vecPow.push_back(*(polyRight->getPowers()).begin());
			std::string recup = " - ";
			recup += *it;
			polyLeft->setExpr((char*)(polyLeft->getExpr() + recup).c_str());
			polyLeft->setFactors(vecFac);
			polyLeft->setPowers(vecPow);
			polyRight->setExpr((char*)"0");
		}

	}

	
	std::vector<int> powers = polyLeft->getPowers();
	std::vector<int> recupPow;
	std::vector<std::string> forReduce;
	int tmpPow = -4242;
	for (std::vector<int>::iterator it = powers.begin(); it != powers.end(); ++it)
	{
		for (std::vector<int>::iterator tmpIt(it); tmpIt != powers.end(); ++tmpIt)
		{
			if (tmpPow == *tmpIt)
			{
				std::vector<int>::iterator recup = std::find(recupPow.begin(), recupPow.end(), tmpPow);
				if (recup == recupPow.end())
					recupPow.push_back(tmpPow);
			}
			tmpPow = *tmpIt;
		}
	}
	for (std::vector<int>::iterator itPow = recupPow.begin(); itPow != recupPow.end(); ++itPow)
	{
		std::vector<std::string> vec = polyLeft->getFactors();
		for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); ++it)
		{
			std::string cut = "";
			size_t pos =  (*it).find("^");
			if (pos != std::string::npos)
			{
				cut = (*it).substr(pos + 1, (*it).length());
				if (atoi(cut.c_str()) == *itPow)
				{
					std::vector<std::string>::iterator tmp(it);
					tmp--;
					if (tmp != vec.end() && (*tmp).length() > 0)
						forReduce.push_back(*tmp);
					forReduce.push_back(*it);

				}
			}
			//if (*itPow == 

		}
		//std::cout << "powwwwww = " << *it << "\n";
	}
	
	double sum = 0;
	int	sign = 1;
	int	init = 0;
	std::vector<std::string>::iterator res;
	std::vector<std::string> reduced;
	std::vector<std::string> vec2 = polyLeft->getFactors();
	for (std::vector<std::string>::iterator it = forReduce.begin(); it != forReduce.end(); ++it)
	{
		for (std::vector<std::string>::iterator all = vec2.begin(); all != vec2.end(); ++all)
		{
			if (it == forReduce.begin() && ((*it) == "+" || (*it) == "-"))
				continue ;
			if (*it != *all)
			{
				continue;
			}
			std::cout << "it = " << *all << "\n";
			if (init == 0)
			{
				std::vector<std::string>::iterator tmp(all);
				res = tmp;
			}
			if ((*it) == "-")
			{
				sign = -1;
			//	reduced.push_back(*it);
			}
			else if ((*it) == "+")
			{
				sign = 1;
				//reduced.push_back(*it);
			}
			if (sign == 1 && (*it) != "+" && (*it) != "-")
				sum += atof(((*it).substr(0, (*it).find("X"))).c_str());
			else if (sign == -1 && (*it) != "+" && (*it) != "-")
				sum -= atof(((*it).substr(0, (*it).find("X"))).c_str());
			std::vector<std::string>::iterator tmp(it);
			tmp++;
			std::cout << "recude = " << sum << "\n";
			if ((*it) != "+" && (*it) != "-" && (*tmp) != "+" && (*tmp) != "-")
			{
				size_t pos = (*res).find("X");
				std::stringstream rec;
				rec << sum;
				std::string str;
				rec >> str;
				//std::vector<std::string>::iterator tmp(res);
				std::string tmp(*res);
				(tmp).replace(0, pos, str);
				std::cout << "RES = " << *res << "\n";
				reduced.push_back(tmp);
				//vec2.insert(res, *res);
				//all = res;
				init = 0;
				sum = 0;
				sign = 1;
			}
		}
	}

	int flag = 0;
	std::vector<std::string>::iterator it;
	for (std::vector<std::string>::iterator all = vec2.begin(); all != vec2.end(); ++all)
	{
		for (it = forReduce.begin(); it != forReduce.end(); ++it)
		{
			std::cout << "all = " << *all << "   it = " << *it << "\n";
			if (*it != *all)
				flag = 1;
			else if (*it == *all && *it != "+" && *it != "-")
			{
				flag = 0;
				break ;
			}
		}
		if (flag == 1)
		{
			std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA = " << *all << "\n";
			reduced.push_back(*all);
			flag = 0;
		}
	}

	if (*(reduced.end() - 1) == "+" || (*(reduced.end() - 1) == "-"))
		reduced.pop_back();
	polyLeft->setFactors(reduced);






	std::vector<std::string> recupFactor = polyLeft->getFactors();
	std::string expr;
	for (std::vector<std::string>::iterator it = recupFactor.begin(); it != recupFactor.end();++ it)
	{
		std::cout << "factors = " << *it << "\n";
		expr += *it;
		expr += " ";
	}
	polyLeft->setExpr((char *)expr.c_str());
/*	std::vector<char> recupSign = poly->getSign();
	for (std::vector<char>::iterator it = recupSign.begin(); it != recupSign.end();++ it)
		std::cout << "sign = " << *it << "\n";*/
	std::vector<int> recupPowers = polyLeft->getPowers();
	for (std::vector<int>::iterator it = recupPowers.begin(); it != recupPowers.end();++ it)
		std::cout << "powers = " << *it << "\n";

	std::cout << "Poly Left = " << polyLeft->getExpr() << "\n";
	std::cout << "Poly Right = " << polyRight->getExpr() << "\n";

}
