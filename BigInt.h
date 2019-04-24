#pragma once

#include <vector>

typedef unsigned long long ulong;

void InitializeBigInt();
void SetBigIntSize(int);

class BigInt {
public:
	bool positive = true;
	std::vector<ulong> numbers;

	BigInt();
	BigInt(ulong);
	BigInt(std::vector<ulong>&);

	void Print();

	void ShiftLeft(int);
	void ShiftRight(int);

	int GetAmountOfBits();
	bool GetBit(int);
	int GetFirstMeaningBit();
	int GetFirstMeaningNumber();

	int Compare(BigInt&);

	void AddNumber(BigInt&);
	void SubtractNumber(BigInt&);
	void SubtractNumberNegative(BigInt&);
	void MultiplyBy(BigInt&);
	void SquareMe();
	void Modulo(BigInt&);
	BigInt ModuloDiv(BigInt&);

	bool operator==(BigInt&);
	bool operator!=(BigInt&);

	BigInt operator+(BigInt&);
	BigInt operator-(BigInt&);
	BigInt operator*(BigInt&);
	BigInt operator/(BigInt&);
	BigInt operator%(BigInt&);
};

BigInt FastModuloPower(BigInt a, BigInt& b, BigInt& mod);
BigInt ReverseModulo(BigInt a, BigInt mod);

System::String^ BigIntToString(BigInt n);
BigInt StringToBigInt(System::String^ str);