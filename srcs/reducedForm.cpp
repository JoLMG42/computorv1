/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reducedForm.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:41:18 by jtaravel          #+#    #+#             */
/*   Updated: 2023/11/09 19:20:05 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Poly.hpp"
#include <algorithm>
#include <sstream>

std::deque<std::string>	eraseVal(std::deque<std::string> vec, std::string str)
{
	for (std::deque<std::string>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		if (*it == str)
		{
			vec.erase(it);
			break ;
		}
	}
	return vec;

}

void	reducedForm(Poly *polyLeft, Poly *polyRight)
{
	std::deque<std::string> vec = polyRight->getFactors();
	for (std::deque<std::string>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::deque<std::string>::iterator tmp(it);
		if ((*tmp)[0] != '+' && (*tmp)[0] != '-')
		{
			std::deque<std::string> vecFac(polyLeft->getFactors());
			std::deque<int> vecPow(polyLeft->getPowers());
			int recupPow = atoi((char *)((*it).substr((*it).find("^") + 1, (*it).length())).c_str());
			(*it).insert(0, 1, '-');
			vecFac.push_back(*it);
			vecPow.push_back(recupPow);
			std::string recup = " - ";
			recup += *it;
			polyLeft->setExpr((char*)(polyLeft->getExpr() + recup).c_str());
			polyLeft->setFactors(vecFac);
			polyLeft->setPowers(vecPow);
			polyRight->setExpr((char*)"0");
		}
		else
		{
			if ((*tmp)[0] == '-')
			{
				std::deque<std::string> vecFac(polyLeft->getFactors());
				std::deque<int> vecPow(polyLeft->getPowers());
				int recupPow = atoi((char *)((*it).substr((*it).find("^") + 1, (*it).length())).c_str());
				(*it).erase(0, 1);
				(*it).insert(0, 1, '+');
				vecFac.push_back(*it);
				vecPow.push_back(recupPow);
				std::string recup = " + ";
				recup += *it;
				polyLeft->setExpr((char*)(polyLeft->getExpr() + recup).c_str());
				polyLeft->setFactors(vecFac);
				polyLeft->setPowers(vecPow);
				polyRight->setExpr((char*)"0");
			}
			else if ((*tmp)[0] == '+')
			{
				std::deque<std::string> vecFac(polyLeft->getFactors());
				std::deque<int> vecPow(polyLeft->getPowers());
				int recupPow = atoi((char *)((*it).substr((*it).find("^") + 1, (*it).length())).c_str());
				(*it).erase(0, 1);
				(*it).insert(0, 1, '-');
				vecFac.push_back(*it);
				vecPow.push_back(recupPow);
				std::string recup = " - ";
				recup += *it;
				polyLeft->setExpr((char*)(polyLeft->getExpr() + recup).c_str());
				polyLeft->setFactors(vecFac);
				polyLeft->setPowers(vecPow);
				polyRight->setExpr((char*)"0");
			}
		}

	}


	
	std::deque<int> powers = polyLeft->getPowers();
	std::deque<int> recupPow;
	std::deque<std::string> forReduce;
	int tmpPow = -4242;
	for (std::deque<int>::iterator it = powers.begin(); it != powers.end(); ++it)
	{
		tmpPow = *it;
		for (std::deque<int>::iterator tmpIt = powers.begin(); tmpIt != powers.end(); ++tmpIt)
		{
			if (tmpPow == *tmpIt && it != tmpIt)
			{
				std::deque<int>::iterator recup = std::find(recupPow.begin(), recupPow.end(), tmpPow);
				if (recup == recupPow.end())
					recupPow.push_back(*tmpIt);
			}
		}
	}
	for (std::deque<int>::iterator itPow = recupPow.begin(); itPow != recupPow.end(); ++itPow)
	{
		std::deque<std::string> vec = polyLeft->getFactors();
		for (std::deque<std::string>::iterator it = vec.begin(); it != vec.end(); ++it)
		{
			std::string cut = "";
			size_t pos =  (*it).find("^");
			if (pos != std::string::npos)
			{
				cut = (*it).substr(pos + 1, (*it).length());
				if (atoi(cut.c_str()) == *itPow)
				{
						std::deque<std::string>::iterator tmp(it);
						forReduce.push_back(*it);
				}
			}
		}
	}

	
	double	sum = 0;
	int	countPow = 0;
	std::deque<std::string>::iterator res;
	std::string toAdd;
	std::string recup;
	std::deque<std::string> reduced;
	std::deque<std::string> addReduced;
	std::deque<std::string> vec2 = polyLeft->getFactors();
	int firstPow = atoi((char *)(*(forReduce.begin())).substr((*(forReduce.begin())).find("^") + 1, (*(forReduce.begin())).length()).c_str());
	for (std::deque<std::string>::iterator it = forReduce.begin(); it != forReduce.end(); ++it)
	{
		size_t pos =  (*it).find("^");
		int pow = atoi((char *)(*it).substr(pos + 1, (*it).length()).c_str());
		if (pow != firstPow && pos != std::string::npos)
			countPow++;
		sum += atof(((*it).substr(0, (*it).find("X"))).c_str());
		for (std::deque<std::string>::iterator it2 = forReduce.begin(); it2 != forReduce.end(); ++it2)
		{
			if (it == it2)
				continue;
			size_t pos2 =  (*it2).find("^");
			int tmpPow = atoi((char *)(*it2).substr(pos2 + 1, (*it2).length()).c_str());
			if (pow == tmpPow)
			{
				sum += atof(((*it2).substr(0, (*it2).find("X"))).c_str());
				std::stringstream rec;
				rec << sum;
				std::string str;
				rec >> str;
				size_t pos3 = (*it2).find("X");
				vec2 = eraseVal(vec2, *it);
				vec2 = eraseVal(vec2, *it2);
				(*it2).replace(0, pos3, str);
				if (countPow == 0)
					forReduce.pop_front();
				else
				{
					std::deque<std::string>::iterator temp(it);
					temp--;
					forReduce.erase(forReduce.begin() + countPow);
					countPow--;
					it = temp;
				}
				break ;
			}
		}
		sum = 0;
	}
	for (std::deque<std::string>::iterator it = forReduce.begin(); it != forReduce.end(); ++it)
	{
		if ((*it)[0] == '-' || (*it)[0] == '+')
			vec2.push_back(*it);
		else
			vec2.push_front(*it);
	}
	polyLeft->setFactors(vec2);

	std::deque<std::string> recupFactor = polyLeft->getFactors();
	std::string expr;
	std::deque<std::string> ordered;
	std::deque<int> recupPowers = polyLeft->getPowers();
	int maxPow = 0;
	sort(recupPowers.begin(), recupPowers.end(), std::greater<int>());
	maxPow = *(recupPowers.begin());
	if (maxPow <= 2)
	{	
		std::string p0;
		std::string p1;
		std::string p2;
		for (std::deque<std::string>::iterator it = recupFactor.begin(); it != recupFactor.end();++ it)
		{
			if ((*it)[(*it).find("^") + 1] == '2')
			{
				p2 = *it;
				p2 = p2.erase(p2.find("X"), 3);
			}
			else if ((*it)[(*it).find("^") + 1] == '1')
			{
				p1 = *it;
				p1 = p1.erase(p1.find("X"), 3);
			}
			else if ((*it)[(*it).find("^") + 1] == '0')
			{
				p0 = *it;
				p0 = p0.erase(p0.find("X"), 3);
			}
		}
		ordered.push_back(p2);
		ordered.push_back(p1);
		ordered.push_back(p0);
	}


	for (std::deque<std::string>::iterator it = recupFactor.begin(); it != recupFactor.end();++ it)
	{
		size_t pos = (*it).find("X");
		if (pos != std::string::npos)
		{
			std::string recup = (*it).substr(0, pos);
			if (recup == "0")
				recupFactor.erase(it);
			if (recupFactor.size() <= 1)
				break ;
		}
	}

	for (std::deque<std::string>::iterator it = recupFactor.begin(); it != recupFactor.end();++ it)
	{
		
		(*it).insert((*it).find("X"), 1, ' ');
		(*it).insert((*it).find("X") - 1, 1, '*');
		(*it).insert((*it).find("X") - 2 , 1, ' ');
		if ((*it)[0] == '+' || (*it)[0] == '-')
			(*it).insert(1, 1, ' ');
		expr += *it;
		std::deque<std::string>::iterator tmp(it);
		tmp++;
		if (tmp != recupFactor.end())
			expr += " ";
	}
	expr += " = 0";
	polyLeft->setExpr((char *)expr.c_str());

	std::cout << "Reduced Form: " << polyLeft->getExpr() << "\n";
	std::cout << "Polynomial degree: " << maxPow << "\n";
	if (maxPow <= 2)
		calculMath(ordered);
	else
		std::cout << "The polynomial degree is strictly greater than 2, I can't solve.\n";
}
