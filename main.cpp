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

int	checkFormat(char *str, Poly *poly)
{
	std::deque<std::string>	factors;
	std::deque<char>		sign;
	std::deque<int>		powers;
	poly->setExpr(str);
	std::deque<std::string> vec = ft_splitdeque(str, " ");
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
