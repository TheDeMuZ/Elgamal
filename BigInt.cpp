#include <iostream>
#include <iomanip>
#include "BigInt.h"

using namespace std;

int SIZE = 4;
void SetBigIntSize(int bits)
{
	SIZE = bits / 64;
}
vector<bool> CurrentBits;

ulong ULONG_BITS[64];
void InitializeBigInt()
{
	ULONG_BITS[0] = 1;
	for (int i = 1; i < 64; i++)
	{
		ULONG_BITS[i] = ULONG_BITS[i - 1] << 1;
	}
}

int min(ulong a, ulong b)
{
	if (a > b)
		return b;
	else
		return a;
}
void shiftVectorForward(vector<ulong>& v)
{
	for (int i = v.size() - 1; i > 0; i--)
		v[i] = v[i - 1];
	v[0] = 0;
}
void shiftVectorBackward(vector<ulong>& v)
{
	for (int i = 0; i < v.size() - 1; i++)
		v[i] = v[i + 1];
	v[v.size() - 1] = 0;
}

BigInt::BigInt()
{
	numbers = vector<ulong>(SIZE, 0);
}
BigInt::BigInt(ulong number)
{
	numbers = vector<ulong>(SIZE, 0);
	numbers[0] = number;
}
BigInt::BigInt(vector<ulong>& original)
{
	if (original.size() > SIZE)
		numbers = vector<ulong>(original);
	else
	{
		numbers = vector<ulong>(SIZE, 0);
		for (int i = 0; i < original.size(); i++)
			numbers[i] = (original[i]);
	}
}


void BigInt::Print()
{
	if (!positive)
		cout << "  -";
	for (int i = 0; i < numbers.size(); i++)
		cout << "  " << numbers[i];
	cout << endl;
}


void BigInt::ShiftLeft(int k)
{
	for (int i = 0; i < k; i++)
	{
		bool flagPrevious = false, flagThis = false;
		for (vector<ulong>::iterator it = numbers.begin(); it != numbers.end(); it++)
		{
			flagThis = *it & ULONG_BITS[63];
			*it <<= 1;
			if (flagPrevious) *it |= ULONG_BITS[0];
			flagPrevious = flagThis;
		}
		if (flagPrevious)
			numbers.push_back(ULONG_BITS[0]);
	}
}
void BigInt::ShiftRight(int k)
{
	for (int i = 0; i < k; i++)
	{
		bool flagPrevious = false, flagThis = false;

		vector<ulong>::iterator it = numbers.end();
		do
		{
			it--;
			flagThis = *it & ULONG_BITS[0];
			*it >>= 1;
			if (flagPrevious) *it |= ULONG_BITS[63];
			flagPrevious = flagThis;
		} while (it != numbers.begin());
	}
}
int BigInt::GetAmountOfBits()
{
	return numbers.size() * 64;
}
bool BigInt::GetBit(int index)
{
	int bitIndex = index % 64;
	index -= bitIndex;
	index /= 64;
	return numbers[index] & ULONG_BITS[bitIndex];
}
int BigInt::GetFirstMeaningBit()
{
	int index = numbers.size(), i;
	vector<ulong>::iterator it = numbers.end();
	do
	{
		it--;
		index--;
		if (*it > 0)
			for (i = 63; i >= 0; i--)
				if ((*it & ULONG_BITS[i]) != 0)
					return (index * 64) + i;
	} while (it != numbers.begin());
	return 0;
}
int BigInt::GetFirstMeaningNumber()
{
	for (int i = numbers.size() - 1; i >= 0; i--)
		if (numbers[i] > 0)
			return i;
	return 0;
}


int BigInt::Compare(BigInt& cmp)
{
	int nMy = GetFirstMeaningNumber();
	int nCmp = cmp.GetFirstMeaningNumber();
	if (nMy > nCmp)
		return 1;
	else if (nMy < nCmp)
		return -1;
	while (nMy >= 0)
	{
		if (numbers[nMy] > cmp.numbers[nMy])
			return 1;
		else if (numbers[nMy] < cmp.numbers[nMy])
			return -1;
		nMy--;
	}
	return 0;
}


void BigInt::AddNumber(BigInt& add)
{
	vector<ulong>::iterator it1 = numbers.begin();
	vector<ulong>::iterator it2 = add.numbers.begin();

	ulong buff;
	bool flag = false;
	while (it2 != add.numbers.end())
	{
		if (it1 == numbers.end())
		{
			numbers.push_back(0);
			it1 = numbers.end() - 1;
		}

		buff = *it1 + *it2;
		if (buff < *it1) // bylo przeniesienie
		{
			if (flag)
				buff++;
			else
				flag = true;
		}
		else
		{
			if (flag)
			{
				buff++;
				if (buff != 0) // nie nastapilo przeniesienie
					flag = false;
			}
		}
		*it1 = buff;

		it1++, it2++;
		if (flag)
			if (it2 == add.numbers.end())
			{
				add.numbers.push_back(0);
				it2 = add.numbers.end() - 1;
			}
	}
}
void BigInt::SubtractNumber(BigInt& add)
{
	vector<ulong>::iterator it1 = numbers.begin();
	vector<ulong>::iterator it2 = add.numbers.begin();

	ulong buff;
	bool flag = false;
	while (it2 != add.numbers.end())
	{
		if (it1 == numbers.end())
		{
			numbers.push_back(0);
			it1 = numbers.end() - 1;
		}

		buff = *it1 - *it2;
		if (buff > *it1) // bylo pozyczenie
		{
			if (flag)
				buff--;
			else
				flag = true;
		}
		else
		{
			if (flag)
			{
				buff--;
				if (buff != ULONG_MAX) // nie nastapilo pozyczenie
					flag = false;
			}
		}
		*it1 = buff;

		it1++, it2++;
		if (flag)
			if (it2 == add.numbers.end())
			{
				add.numbers.push_back(0);
				it2 = add.numbers.end() - 1;
			}
	}
}
void BigInt::SubtractNumberNegative(BigInt& add)
{
	if (positive)
	{
		if (!add.positive)
		{
			AddNumber(add);
			return;
		}
		else if (Compare(add) >= 0)
		{
			SubtractNumber(add);
			return;
		}
		BigInt result = BigInt(add.numbers);
		result.SubtractNumber(*this);
		numbers.assign(result.numbers.begin(), result.numbers.end());
		positive = false;
	}
	else
	{
		if (add.positive)
		{
			AddNumber(add);
			return;
		}
		else if (Compare(add) >= 0)
		{
			SubtractNumber(add);
			return;
		}
		BigInt result = BigInt(add.numbers);
		result.SubtractNumber(*this);
		numbers.assign(result.numbers.begin(), result.numbers.end());
		positive = true;
	}
}


void BigInt::MultiplyBy(BigInt& by)
{
	BigInt result = BigInt(0);
	int bits = by.GetAmountOfBits(), bitCounter = 0;
	for (int i = 0; i < bits; i++)
	{
		if (by.GetBit(i))
		{
			ShiftLeft(bitCounter);
			result.AddNumber(*this);
			bitCounter = 1;
		}
		else
			bitCounter++;
	}
	if (positive != by.positive)
		positive = !positive;
	numbers.assign(result.numbers.begin(), result.numbers.end());
}
void BigInt::SquareMe()
{
	BigInt me = *this;
	MultiplyBy(me);
}

void BigInt::Modulo(BigInt& mod)
{
	int bitMy = GetFirstMeaningBit();
	int bitMod = mod.GetFirstMeaningBit();
	if (bitMod > bitMy)
		return;
	int bitDiff = bitMy - bitMod;
	mod.ShiftLeft(bitDiff);
	while (Compare(mod) >= 0)
		SubtractNumber(mod);

	while (bitDiff > 0)
	{
		mod.ShiftRight(1);
		bitDiff--;
		while (Compare(mod) >= 0)
			SubtractNumber(mod);
	}
	if (bitMod < SIZE * 64 && mod.numbers.size() > SIZE)
	{
		mod.numbers.erase(mod.numbers.begin() + SIZE, mod.numbers.end());
		if (numbers.size() > SIZE)
			numbers.erase(numbers.begin() + SIZE, numbers.end());
	}
}
BigInt BigInt::ModuloDiv(BigInt& mod)
{
	BigInt result = BigInt(0);
	int bitMy = GetFirstMeaningBit();
	int bitMod = mod.GetFirstMeaningBit();
	if (bitMod > bitMy)
		return result;
	BigInt one = BigInt(1);
	int bitDiff = bitMy - bitMod;
	mod.ShiftLeft(bitDiff);
	one.ShiftLeft(bitDiff);
	while (Compare(mod) >= 0)
	{
		SubtractNumber(mod);
		result.AddNumber(one);
	}

	while (bitDiff > 0)
	{
		mod.ShiftRight(1);
		one.ShiftRight(1);
		bitDiff--;
		while (Compare(mod) >= 0)
		{
			SubtractNumber(mod);
			result.AddNumber(one);
		}
	}
	if (bitMod < SIZE * 64 && mod.numbers.size() > SIZE)
	{
		mod.numbers.erase(mod.numbers.begin() + SIZE, mod.numbers.end());
		if (numbers.size() > SIZE)
			numbers.erase(numbers.begin() + SIZE, numbers.end());
	}
	return result;
}

bool BigInt::operator==(BigInt& b)
{
	return Compare(b) == 0;
}
bool BigInt::operator!=(BigInt& b)
{
	return Compare(b) != 0;
}



BigInt BigInt::operator+(BigInt& a)
{
	BigInt result = BigInt(numbers);
	result.AddNumber(a);
	return result;
}
BigInt BigInt::operator-(BigInt& a)
{
	BigInt result = BigInt(numbers);
	result.SubtractNumber(a);
	return result;
}
BigInt BigInt::operator*(BigInt& a)
{
	BigInt result = BigInt(numbers);
	result.MultiplyBy(a);
	return result;
}
BigInt BigInt::operator/(BigInt& a)
{
	BigInt lhs = BigInt(numbers);
	return lhs.ModuloDiv(a);
}
BigInt BigInt::operator%(BigInt& a)
{
	BigInt lhs = BigInt(numbers);
	lhs.Modulo(a);
	return lhs;
}


















BigInt FastModuloPower(BigInt a, BigInt& b, BigInt& mod)
{
	int bitCounter = 0;
	bool flag = false;
	int bits = b.GetAmountOfBits();
	//BigInt *powers = new BigInt[bits];
	BigInt aCopy = a;
	for (int i = 0; i < bits; i++)
	{
		if (b.GetBit(i))
		{
			if (flag)
			{
				for (int j = 0; j < bitCounter; j++)
				{
					aCopy.SquareMe();
					aCopy.Modulo(mod);
				}
				a.MultiplyBy(aCopy);
				a.Modulo(mod);
			}
			else
			{
				//lastPower = &a;
				if (bitCounter > 0)
				{
					for (int j = 0; j < bitCounter; j++)
					{
						aCopy.SquareMe();
						aCopy.Modulo(mod);
					}
					a = aCopy;
				}
				flag = true;
			}
			bitCounter = 1;
		}
		else
		{
			bitCounter++;
		}
	}
	//delete[] powers;
	return a;
}


void ReverseModulo_Euklides(BigInt a, BigInt b, BigInt& x, BigInt& y)
{
	BigInt zero = BigInt(0);
	if (a.Compare(zero) != 0)
	{
		ReverseModulo_Euklides(b%a, a, x, y);
		BigInt tmp = x;
		x = y;
		BigInt buff = (b / a) * tmp;
		x.SubtractNumberNegative(buff);
		y = tmp;
	}
}
BigInt ReverseModulo(BigInt a, BigInt mod)
{
	BigInt x = BigInt(0), y = BigInt(1);
	ReverseModulo_Euklides(a, mod, x, y);
	if (!x.positive);
	{
		mod.positive = false;
		x.SubtractNumberNegative(mod);
	}
	return x;
}

System::String^ BigIntToString(BigInt n)
{
	System::String^ result = "";
	BigInt zero = BigInt(0);
	BigInt ten = BigInt(10);
	BigInt div;
	while (n.Compare(zero) == 1)
	{
		div = n.ModuloDiv(ten);
		result = n.numbers[0].ToString() + result;
		n = div;
	}
	return result;
}
BigInt StringToBigInt(System::String^ str)
{
	BigInt n = BigInt(0);
	BigInt ten = BigInt(10);
	BigInt add = BigInt(0);
	ulong digit;
	for (int i = 0; i < str->Length; i++)
	{
		digit = ((ulong)str[i]) - 48;
		add.numbers[0] = digit;
		n.MultiplyBy(ten);
		n.AddNumber(add);
	}
	return n;
}