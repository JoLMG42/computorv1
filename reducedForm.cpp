/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reducedForm.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:41:18 by jtaravel          #+#    #+#             */
/*   Updated: 2023/11/07 18:14:13 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Poly.hpp"
#include <algorithm>
#include <sstream>

void    calculMath(std::deque<std::string> deq);

std::deque<std::string>	eraseVal(std::deque<std::string> vec, std::string str)
{
	for (std::deque<std::string>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << "in erase, it = " << *it << "   str = " << str << "\n";
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
	std::cout << "\n\n\nIN REDUCED FUNCTION\n\n\n";

	std::cout << "Poly Left = " << polyLeft->getExpr() << "\n";
	std::cout << "Poly Right = " << polyRight->getExpr() << "\n";

	std::deque<std::string> vec = polyRight->getFactors();
	for (std::deque<std::string>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::deque<std::string>::iterator tmp(it);
		//tmp++;
		//if (tmp != vec.end())
		//	std::cout << "lol\n\n\n";
		//else if (tmp == vec.end())
		//{
		std::cout << "ITITITI = " << *it << "\n";
		if ((*tmp)[0] != '+' && (*tmp)[0] != '-')
		{
			std::deque<std::string> vecFac(polyLeft->getFactors());
			std::deque<int> vecPow(polyLeft->getPowers());
			int recupPow = atoi((char *)((*it).substr((*it).find("^") + 1, (*it).length())).c_str());
			(*it).insert(0, 1, '-');
			vecFac.push_back(*it);
			std::cout << "recup pow 1 = " << recupPow << "\n";
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
			std::cout << "recup pow 2 = " << recupPow << "\n";
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
			std::cout << "recup pow 3 = " << recupPow << "\n";
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
		//}

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
					std::cout << "powwwwww = " << *tmpIt << "    tmpPow = " << tmpPow << "\n";
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
			//if (*itPow == 

		}
	}
	
	double sum = 0;
	int	sign = 1;
	int	init = 0;
	int	test = 0;
	int	countPow = 0;
	std::deque<std::string>::iterator res;
	std::string toAdd;
	std::string recup;
	std::deque<std::string> reduced;
	std::deque<std::string> addReduced;
	std::deque<std::string> vec2 = polyLeft->getFactors();
	std::cout << "\n\n\n" << "AAAAAAAAAAAA\n\n\n";
	for (std::deque<std::string>::iterator it = forReduce.begin(); it != forReduce.end(); ++it)
		std::cout << "it = " << *it << "\n";
	std::cout << "\n\n\n" << "AAAAAAAAAAAA\n\n\n";
	//for (std::deque<std::string>::iterator all = vec2.begin(); all != vec2.end(); ++all)
	//{
		//recup = "";
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
				{
					continue;
				}
				size_t pos2 =  (*it2).find("^");
				int tmpPow = atoi((char *)(*it2).substr(pos2 + 1, (*it2).length()).c_str());
				if (pow == tmpPow)
				{
					size_t pos4 = (*it2).find("X");
					sum += atof(((*it2).substr(0, (*it2).find("X"))).c_str());
					std::stringstream rec;
					rec << sum;
					std::string str;
					rec >> str;
					//std::cout << "all before = " << *all << "\n";
					size_t pos3 = (*it2).find("X");
					vec2 = eraseVal(vec2, *it);
					vec2 = eraseVal(vec2, *it2);
					//vec2 = eraseVal(vec2, *it2);
					//reduced = eraseVal(vec2, *it2);
					(*it2).replace(0, pos3, str);
					std::cout << "all after = " << *it2 << "\n";
					if (countPow == 0)
						forReduce.pop_front();
					else
						forReduce.erase(forReduce.begin() + countPow);
					//forReduce.erase(it);
					//vec2.erase(all);
					break ;
				}
			}
			sum = 0;
	std::cout << "\n\n\n" << "AAAAAAAAAAAA\n\n\n";
	for (std::deque<std::string>::iterator it = forReduce.begin(); it != forReduce.end(); ++it)
		std::cout << "it = " << *it << "\n";
	std::cout << "\n\n\n" << "AAAAAAAAAAAA\n\n\n";
				/*if (it == forReduce.begin() && (*it == "+" || *it == "-"))
					forReduce.pop_front();
				std::cout << "HERE = " << *it << "\n";
				size_t pos =  (*it).find("^");
				int pow = atoi((char *)(*it).substr(pos + 1, (*it).length()).c_str());
				for (std::deque<std::string>::iterator it2 = forReduce.begin(); it2 != forReduce.end(); ++it2)
				{
					if (it == it2)
						continue;
					if ((*it == "+" || *it == "-") || (*it2 == "+" || *it2 == "-"))
						continue;
					sum += atof(((*it).substr(0, (*it).find("X"))).c_str());
					std::cout << "sum = " << sum << "\n";
					std::cout << "it = " << *it << "   it2 = " << *it2 << "\n";
					size_t pos2 =  (*it2).find("^");
					int tmpPow = atoi((char *)(*it2).substr(pos2 + 1, (*it2).length()).c_str());
					if (pow == tmpPow)
					{
						std::deque<std::string>::iterator recup(it2);
						recup--;
						//std::cout << "recup = " << *recup << "\n";
					//	std::cout << "sum 1 = " << sum << "\n";

							sign = -1;
							//vec2 = eraseVal(vec2, *recup);
							//reduced.push_back(*it);
						}
						else if ((*recup) == "+")
						{
							sign = 1;
							//vec2 = eraseVal(vec2, *recup);
							//reduced.push_back(*it);
						}
						if (sign == 1 && (*it2) != "+" && (*it2) != "-")
							sum += atof(((*it2).substr(0, (*it2).find("X"))).c_str());
						else if (sign == -1 && (*it2) != "+" && (*it2) != "-")
							sum -= atof(((*it2).substr(0, (*it2).find("X"))).c_str());

						std::stringstream rec;
						rec << sum;
						std::string str;
						rec >> str;
						//std::cout << "all before = " << *all << "\n";
						size_t pos3 = (*it2).find("X");
						vec2 = eraseVal(vec2, *it);
						vec2 = eraseVal(vec2, *it2);
						//reduced = eraseVal(vec2, *it2);
						forReduce.pop_front();
						(*it2).replace(0, pos3, str);
						std::cout << "all after = " << *it2 << "\n";
						//forReduce.pop_front();
						//forReduce.erase(it);
						//vec2.erase(all);
						break ;
					}
				}
				sum = 0;
				if (it == forReduce.end())
					break;*/
		}
		
			/*if (it == forReduce.begin() && ((*it) == "+" || (*it) == "-"))
				continue ;

			std::cout << "all = " << *all << "   it = " << *it << "\n";
			if (*it != *all)
			{
				test = 1;
				if (toAdd != "ALREADYIN")
					toAdd = *all;
				continue;
			}
			std::cout << "it = " << *all << "\n";
			if (init == 0)
			{
				std::deque<std::string>::iterator tmp(all);
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
			std::deque<std::string>::iterator tmp(it);
			tmp++;
			std::cout << "recude = " << sum << "\n";
			if (*all != "+" && *all != "-")
				toAdd = "ALREADYIN";
			if (*it != "+" && *it != "-" && *tmp != "+" && *tmp != "-")
			{
				size_t pos = (*res).find("X");
				std::stringstream rec;
				rec << sum;
				std::string str;
				rec >> str;
				//std::deque<std::string>::iterator tmp(res);
				std::string tmp(*res);
				(tmp).replace(0, pos, str);
				std::cout << "RES = " << tmp << "\n";
				//reduced.push_back(tmp);
				recup = tmp;
				//vec2.insert(res, *res);
				//all = res;
				init = 0;
				sum = 0;
				sign = 1;
				//test = 0;
				break ;
			}
			else
				break ;
		}
		if (test == 1)
		{
			if (recup.length() > 0 && recup != "ALREADYIN")
				addReduced.push_back(toAdd);
			if (toAdd != "ALREADYIN")
			{
				std::cout << "to add  = " << toAdd << "\n";
				addReduced.push_back(toAdd);
			}

			test = 0;
		}
		toAdd = "";*/
	//}

	for (std::deque<std::string>::iterator it = forReduce.begin(); it != forReduce.end(); ++it)
	{
		if ((*it)[0] == '-' || (*it)[0] == '+')
			vec2.push_back(*it);
		else
			vec2.push_front(*it);
	}
	/*
	int flag = 0;
	std::deque<std::string>::iterator it;
	for (std::deque<std::string>::iterator all = vec2.begin(); all != vec2.end(); ++all)
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
	}*/

//	if (*(reduced.end() - 1) == "+" || (*(reduced.end() - 1) == "-"))
//		reduced.pop_back();
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
			std::cout << "ppppp = " << ((*it)[(*it).find("^") + 1]) << "\n";
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

	for (std::deque<std::string>::iterator it = ordered.begin(); it != ordered.end();++ it)
	{
		std::cout << "ORDERED = " << *it << "\n";
	}

	for (std::deque<std::string>::iterator it = recupFactor.begin(); it != recupFactor.end();++ it)
	{
		
		(*it).insert((*it).find("X"), 1, ' ');
		(*it).insert((*it).find("X") - 1, 1, '*');
		(*it).insert((*it).find("X") - 2 , 1, ' ');
		if ((*it)[0] == '+' || (*it)[0] == '-')
			(*it).insert(1, 1, ' ');

		std::cout << "factors = " << *it << "\n";
		expr += *it;
		std::deque<std::string>::iterator tmp(it);
		tmp++;
		if (tmp != recupFactor.end())
			expr += " ";
	}
	expr += " = 0";
	polyLeft->setExpr((char *)expr.c_str());
	for (std::deque<int>::iterator it = recupPowers.begin(); it != recupPowers.end();++ it)
		std::cout << "powers = " << *it << "\n";

	std::cout << "Poly Left = " << polyLeft->getExpr() << "\n";
	std::cout << "Poly Right = " << polyRight->getExpr() << "\n";
	
	std::cout << "Reduced Form: " << polyLeft->getExpr() << "\n";
	std::cout << "Polynomial degree: " << maxPow << "\n";
	if (maxPow <= 2)
		calculMath(ordered);
}
