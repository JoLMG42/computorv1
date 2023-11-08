#include <iostream>
#include <deque>
#include "Poly.hpp"
#include <stdlib.h>


std::deque<std::string> ft_splitdeque(std::string str, std::string deli)
{
	std::deque<std::string> res;

		int start = 0;
		int end = str.find(deli);
		int     i = 0;
		while (end != -1)
		{
				res.push_back(str.substr(start, end - start));
				start = end + deli.size();
				end = str.find(deli, start);
				i++;
		}
		res.push_back(str.substr(start, end - start));
		return (res);
}

bool isNumber(const std::string& str)
{
	for (char const& c : str)
	{
		if (std::isdigit(c) == 0 && c != '.')
			return false;
	}
	return true;
}

std::string	refactoStr(std::string str, const char *ope, const char *toSplit)
{
	std::cout << "START REFACTO = \n\n\n" << str << "\n\n\n";

	std::string cpy(str);
	std::string forSplit(ope);
	std::string tilps(toSplit);
	std::deque<std::string> split = ft_splitdeque(cpy, tilps);
	for (std::deque<std::string>::iterator it = split.begin(); it != split.end(); ++it)
	{
		std::cout << "it before = |" << *it << "|\n";

		if ((*it).find("-") != std::string::npos)
		{
			std::deque<std::string>::iterator beg = it;
			std::string minus("-");
			std::deque<std::string> split2 = ft_splitdeque(*it, minus);
			for (std::deque<std::string>::iterator it = split2.begin(); it != split2.end(); ++it)
			{
				std::cout << "it before 222222 = |" << *it << "|\n";
				if ((*it)[0] == ' ')
					(*it).erase(0, 1);
				if ((*it)[(*it).length() - 1] == ' ')
					(*it).erase((*it).length() - 1, 1);
				size_t pos = (*it).find("X");
				if (pos == std::string::npos)
				{
					(*it) += " * X^0";
				}
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
				std::cout << "it before 3333333  = |" << *it << "|\n";
			}
			//if (split.size() < 2)
			//	return ((*(split.begin())));
			std::string ret;
			for (std::deque<std::string>::iterator it2 = split2.begin(); it2 != split2.end(); ++it2)
			{
				//if (it2 == split.begin())
				if (it2 == split2.begin())
				{
					ret += *it2;
					continue;
				}
				else
				{
					std::cout << "looooooo = " << *it2 << "\n";
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
		{
			(*it) += " * X^0";
		}
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
		std::cout << "it after = |" << *it << "|\n";
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
	std::cout << "\nFin refacto = " << ret << "\n";
	return (ret);


}

int	checkFormat(char *str, Poly *poly)
{
	std::string cpy(str);
	cpy = refactoStr(cpy, "+", "+");
	//cpy = refactoStr(cpy, "-", "-+");
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
			std::deque<std::string>::iterator tmp(it);
			std::string recup;
			tmp--;
			if (!isNumber(*tmp))
				return (0);
			//factors.push_back(*tmp);
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
			//tmp--;
			std::deque<std::string>::iterator tmp2(it);
			tmp2--;
			if (tmp2 != vec.begin())
			{
				tmp2--;
				if ((*tmp2).length() > 0)
					recup.insert(0, 1, (*tmp2)[0]);
			}
			if (tmp != vec.end() && (*tmp).length() > 0 && ((*tmp)[0] == '+' || (*tmp)[0] == '-' ))
			{
				sign.push_back((*(tmp))[0]);
				//factors.push_back(*(tmp));
			}
			factors.push_back(recup);
			//std::cout << "ici = " << (*tmp) << "\n";
		}
	}
	poly->setFactors(factors);
	poly->setSign(sign);
	poly->setPowers(powers);
	std::deque<std::string> recupFactor = poly->getFactors();
	for (std::deque<std::string>::iterator it = recupFactor.begin(); it != recupFactor.end();++ it)
		std::cout << "factors = " << *it << "\n";
	std::deque<char> recupSign = poly->getSign();
	for (std::deque<char>::iterator it = recupSign.begin(); it != recupSign.end();++ it)
		std::cout << "sign = " << *it << "\n";
	std::deque<int> recupPowers = poly->getPowers();
	for (std::deque<int>::iterator it = recupPowers.begin(); it != recupPowers.end();++ it)
		std::cout << "powers = " << *it << "\n";
	std::cout << poly->getExpr();
	return (1);

}

std::deque<std::string> splitStart(std::string str, std::string delim)
{
	size_t start = 0;
	size_t pos_delim = str.find(delim);
	std::deque<std::string> ret;
	while (pos_delim != str.npos)
	{
		ret.push_back(str.substr(start, pos_delim - start));
		start = pos_delim + delim.length();
		pos_delim = str.find(delim, start);
	}
	ret.push_back(str.substr(start, str.length() - start));
	return (ret);
}

void    reducedForm(Poly *polyLeft, Poly *polyRight);

int	main(int ac, char **av)
{

	if (BONUS == 0)
		std::cout << "NONONONOONNO\n";
	else if (BONUS == 1)
		std::cout << "OIUOIUOIUOIUO\n";

	Poly polyLeft;
	Poly polyRight;
	if (ac != 2)
	{
		std::cout << "Wrong number of arguments\n";
		return (0);
	}
	std::string oh(av[1]);
	std::deque<std::string> recupPoly = splitStart(oh, "=");
	for (std::deque<std::string>::iterator it = recupPoly.begin(); it != recupPoly.end();++ it)
		std::cout << "split ret = " << *it << "\n";

	std::cout << "POlY left = " << *(recupPoly.begin()) << "\n";
	if (!checkFormat((char *)(recupPoly.begin())->c_str(), &polyLeft))
	{
		std::cout << "Wrong format\n";
		return (0);
	}
	std::deque<std::string>::iterator itEnd = recupPoly.end();
	itEnd--;
	std::cout << "\nPOlY RIGHT = " << (*itEnd) << "\n";
	if (!checkFormat((char *)((*itEnd).c_str()), &polyRight))
	{
		std::cout << "Wrong format\n";
		return (0);
	}
	reducedForm(&polyLeft, &polyRight);
}
