#pragma once
#include "BigInt.h"


class ElgamalAlg
{
private:
	BigInt p, g, h, a;//p, g, h s¹ kluczem publicznym a prywatnym

public:
	int keyLength;
	ElgamalAlg();
	void keyLenghtSet(int keyLenght);
	void generateKey(int keyLenght);
	void readKeyEncrypt();
	void readKeyDecrypt();
	void EncryptFile(System::String^, System::String^);
	void DecryptFile(System::String^, System::String^);
	System::String^ encrptText(System::String^ plainText);
	System::String^ decryptText(System::String^ clipherText);
};

BigInt textToBigInt(System::String^ str);
System::String^ BigIntToText(BigInt& num);
System::String^ BigIntToHex(BigInt& num);
BigInt HexToBigInt(System::String^ hex);