/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:35:39 by jtaravel          #+#    #+#             */
/*   Updated: 2023/11/08 17:58:42 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Poly.hpp"

int	checkFormat(char *str, Poly *poly)
{
	std::string cpy(str);
	cpy = addSpace(cpy);
	cpy = refactoStr(cpy, "+", "+");
	std::deque<std::string>	factors;
	std::deque<char>		sign;
	std::deque<int>		powers;
	poly->setExpr((char*)cpy.c_str());
	std::deque<std::string> vec = ft_splitdeque(cpy, " ");
	for (std::deque<std::string>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		if (((*it).find("*") <= (*it).length() || (*it)[0] == '*') && (*it).length() != 1)
			return (0);
		else if (((*it).find("*") <= (*it).length() || (*it)[0] == '*') && (*it).length() == 1)
		{
			if (it == vec.begin())
				return (0);
			std::deque<std::string>::iterator tmp(it);
			std::string recup;
			tmp--;
			if (!isNumber(*tmp))
				return (0);
			recup = *tmp;
			tmp = it;
			tmp++;
			if ((*tmp)[0] != 'X' || (*tmp)[1] != '^')
				return (0);
			else if ((*tmp)[0] == 'X' && (*tmp)[1] == '^')
			{
				std::string pow = (*tmp).substr(2, (*tmp).length());
				if (!isNumber(pow) || pow.length() < 1)
					return (0);
				else
					powers.push_back(atoi(pow.c_str()));
			}
			recup += *tmp;
			std::deque<std::string>::iterator tmp2(it);
			tmp2--;
			if (tmp2 != vec.begin())
			{
				tmp2--;
				if ((*tmp2).length() > 0)
					recup.insert(0, 1, (*tmp2)[0]);
			}
			if (tmp != vec.end() && (*tmp).length() > 0 && ((*tmp)[0] == '+' || (*tmp)[0] == '-' ))
				sign.push_back((*(tmp))[0]);
			factors.push_back(recup);
		}
	}
	poly->setFactors(factors);
	poly->setSign(sign);
	poly->setPowers(powers);
	std::deque<std::string> recupFactor = poly->getFactors();
	/*for (std::deque<std::string>::iterator it = recupFactor.begin(); it != recupFactor.end();++ it)
		std::cout << "factors = " << *it << "\n";
	std::deque<char> recupSign = poly->getSign();
	for (std::deque<char>::iterator it = recupSign.begin(); it != recupSign.end();++ it)
		std::cout << "sign = " << *it << "\n";
	std::deque<int> recupPowers = poly->getPowers();
	for (std::deque<int>::iterator it = recupPowers.begin(); it != recupPowers.end();++ it)
		std::cout << "powers = " << *it << "\n";
	std::cout << poly->getExpr();*/
	return (1);

}

std::string	refactoStr(std::string str, const char *ope, const char *toSplit)
{
	std::string cpy(str);
	std::string forSplit(ope);
	std::string tilps(toSplit);
	std::deque<std::string> split = ft_splitdeque(cpy, tilps);
	for (std::deque<std::string>::iterator it = split.begin(); it != split.end(); ++it)
	{
		if ((*it).find("-") != std::string::npos && it != split.begin())
		{
			std::deque<std::string>::iterator beg = it;
			std::string minus("-");
			std::deque<std::string> split2 = ft_splitdeque(*it, minus);
			for (std::deque<std::string>::iterator it = split2.begin(); it != split2.end(); ++it)
			{
				if ((*it)[0] == ' ')
					(*it).erase(0, 1);
				if ((*it)[(*it).length() - 1] == ' ')
					(*it).erase((*it).length() - 1, 1);
				size_t pos = (*it).find("X");
				if (pos == std::string::npos)
					(*it) += " * X^0";
				else
				{
					size_t pos2 = (*it).find("^");
					if (pos2 == std::string::npos)
						(*it) += "^1";
					size_t pos3 = (*it).find("*");
					if (pos3 == std::string::npos)
						(*it).insert(0, "1 * ");
				}
			}
			std::string ret;
			for (std::deque<std::string>::iterator it2 = split2.begin(); it2 != split2.end(); ++it2)
			{
				if (it2 == split2.begin())
				{
					ret += *it2;
					continue;
				}
				else
				{
					std::string w = " ";
					w += "-";
					w += " ";
					(*it2).insert(0, w);
				}
				ret += *it2;
			}
			*it = ret;
		}
		if ((*it)[0] == ' ')
			(*it).erase(0, 1);
		if ((*it)[(*it).length() - 1] == ' ')
			(*it).erase((*it).length() - 1, 1);
		size_t pos = (*it).find("X");
		if (pos == std::string::npos)
			(*it) += " * X^0";
		else
		{
			size_t pos2 = (*it).find("^");
			if (pos2 == std::string::npos)
			{
				(*it) += "^1";
			}
			size_t pos3 = (*it).find("*");
			if (pos3 == std::string::npos)
				(*it).insert(0, "1 * ");
		}
	}
	if (split.size() < 2)
		return ((*(split.begin())));
	std::string ret;
	for (std::deque<std::string>::iterator it = split.begin(); it != split.end(); ++it)
	{
		if (it == split.begin())
		{
			ret += *it;
			continue;
		}
		else
		{
			std::string w = " ";
			w += ope;
			w += " ";
			(*it).insert(0, w);
		}
		ret += *it;
	}
	return (ret);
}
