#include <vector>
#include <cstdlib>
#include <ctime>
#include "BigInt.h"
#include "prime.h"

using namespace std;

ulong ulongRand()
{
	ulong rand1 = rand();
	ulong rand2 = rand();
	rand1 = rand1 << 32;
	return (rand1 | rand2);
}

bool RabinMillerPrimeTest(BigInt& prime, int k)
{
	BigInt n1 = BigInt(prime.numbers);
	BigInt one = BigInt(1);
	BigInt two = BigInt(2);
	n1.SubtractNumber(one);

	if (FastModuloPower(two, n1, prime).Compare(one) != 0)
		return false;

	int s = 1;
	/*
	for (int i = 0; i < n1.GetAmountOfBits(); i++)
	{
		if (n1.GetBit(i))
		{
			s = i;
			break;
		}
	}
	*/

	BigInt d = n1;
	d.ShiftRight(1);

	//vector<ulong> aNumbers;
	BigInt a = BigInt(prime.numbers);
	BigInt tmp;
	bool flag;
	for (int i = 0; i < k; i++)
	{
		//aNumbers.clear();
		for (vector<ulong>::iterator it = a.numbers.begin(); it != a.numbers.end(); it++)
		{
			if (it == a.numbers.end() - 1)
				*it = (ulongRand() / 2);
			else
				*it = ulongRand();
		}
		//a = BigInt(aNumbers);

		tmp = FastModuloPower(a, d, prime);
		if (tmp.Compare(one) != 0)
		{
			if (tmp.Compare(n1) != 0)
			{
				return false;
			}
		}
	}
	return true;
}

BigInt generateRabinPrimeNumber(int bits)
{
	int numbersAmount = bits / 64;
	vector<ulong> numbers;
	for (int i = 0; i < numbersAmount; i++)
	{
		if (i == numbersAmount - 1)
			if (i == 0)
				numbers.push_back(((ulongRand() >> 3) << 2) + (ULLONG_MAX >> 1));
			else
				numbers.push_back((ulongRand() >> 1) + (ULLONG_MAX >> 1));
		else if (i == 0)
			numbers.push_back((ulongRand() / 4) * 4 + 3);
		else
			numbers.push_back(ulongRand());
	}
	BigInt prime = BigInt(numbers);
	BigInt four = BigInt(4);


	while (!RabinMillerPrimeTest(prime, 16))
		prime.AddNumber(four);
	return prime;


	/*
	if (RabinMillerPrimeTest(prime, 8))
		return prime;
	else
		return generateRabinPrimeNumber(bits);
	*/
}

BigInt RandomNumber()
{
	vector<ulong> numbers;
	numbers.push_back(ulongRand());
	return BigInt(numbers);
}
