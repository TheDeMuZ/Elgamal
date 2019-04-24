#include <vector>
#include "BigInt.h"
#include "Algo.h"
#include "prime.h"
#include <iostream>
using namespace System;
using namespace System::Text;
using namespace System::IO;

BigInt bytesToBigInt(array<unsigned char>^ bytes)
{
	std::vector<ulong> data;
	ulong current = 0;
	ulong tmp;
	int byteIndex;
	for (int i = 0; i < bytes->Length; i++)
	{
		tmp = (ulong)(bytes[i]);
		byteIndex = i % 8;
		switch (byteIndex)
		{
		case 0:
			current += tmp;
			break;
		case 1:
			current += tmp * 256;
			break;
		case 2:
			current += tmp * 65536;
			break;
		case 3:
			current += tmp * 16777216;
			break;
		case 4:
			current += tmp * 4294967296;
			break;
		case 5:
			current += tmp * 1099511627776;
			break;
		case 6:
			current += tmp * 281474976710656;
			break;
		case 7:
			current += tmp * 72057594037927936;
			break;
		default:
			break;
		}
		if (byteIndex == 7)
		{
			data.push_back(current);
			current = 0;
		}
	}
	if (current > 0)
		data.push_back(current);
	return BigInt(data);
}
array<unsigned char>^ BigIntToBytes(BigInt& num)
{
	int numbers = num.numbers.size();
	array<unsigned char>^ bytes = gcnew array<unsigned char>(numbers * 8);
	for (int n = 0; n < numbers; n++)
	{
		ulong u = num.numbers[n];
		for (int i = 0; i < 8; i++)
		{
			bytes[n * 8 + i] = (unsigned char)(u & 255);
			u >>= 8;
		}
	}
	return bytes;
}

BigInt textToBigInt(String^ str)
{
	array<unsigned char>^ bytes = Encoding::ASCII->GetBytes(str);
	return bytesToBigInt(bytes);
}
String^ BigIntToText(BigInt& num)
{
	return Encoding::ASCII->GetString(BigIntToBytes(num));
}


String^ BigIntToHex(BigInt& num)
{
	return BitConverter::ToString(BigIntToBytes(num));
}

BigInt HexToBigInt(String^ hex)
{
	array<String^>^ hexBytes = hex->Split('-');
	std::vector<ulong> data;
	ulong current = 0;
	ulong tmp;
	int byteIndex;
	unsigned char byte;
	for (int i = 0; i < hexBytes->Length; i++)
	{
		byte = Byte::Parse(hexBytes[i], Globalization::NumberStyles::HexNumber);
		tmp = (ulong)(byte);
		byteIndex = i % 8;
		switch (byteIndex)
		{
		case 0:
			current += tmp;
			break;
		case 1:
			current += tmp * 256;
			break;
		case 2:
			current += tmp * 65536;
			break;
		case 3:
			current += tmp * 16777216;
			break;
		case 4:
			current += tmp * 4294967296;
			break;
		case 5:
			current += tmp * 1099511627776;
			break;
		case 6:
			current += tmp * 281474976710656;
			break;
		case 7:
			current += tmp * 72057594037927936;
			break;
		default:
			break;
		}
		if (byteIndex == 7)
		{
			data.push_back(current);
			current = 0;
		}
	}
	if (current > 0)
		data.push_back(current);
	return BigInt(data);
}

ElgamalAlg::ElgamalAlg(){}

void ElgamalAlg::keyLenghtSet(int keyLenght)
{
	this->keyLength = keyLenght;
}

void ElgamalAlg::generateKey(int keyLenght)
{
	this->keyLength = keyLenght;
	this->p = generateRabinPrimeNumber(keyLenght);
	this->g = RandomNumber();
	this->a = RandomNumber();
	this->h = FastModuloPower(g, a, p);
	File::WriteAllText("p.txt", BigIntToString(p));
	File::WriteAllText("g.txt", BigIntToString(g));
	File::WriteAllText("a.txt", BigIntToString(a));
	File::WriteAllText("h.txt", BigIntToString(h));
}

void ElgamalAlg::readKeyEncrypt()
{
	p = StringToBigInt(File::ReadAllText("p.txt"));
	g = StringToBigInt(File::ReadAllText("g.txt"));
	h = StringToBigInt(File::ReadAllText("h.txt"));
}

void ElgamalAlg::readKeyDecrypt()
{
	p = StringToBigInt(File::ReadAllText("p.txt"));
	a = StringToBigInt(File::ReadAllText("a.txt"));
}



void ElgamalAlg::EncryptFile(String ^ sourcePath, String ^ destinationPath)
{
	FileStream^ streamFrom = File::Open(sourcePath, System::IO::FileMode::Open);
	BinaryReader^ reader = gcnew BinaryReader(streamFrom);

	FileStream^ streamTo = File::Create(destinationPath);
	BinaryWriter^ writer = gcnew BinaryWriter(streamTo);
	int blockLength = (keyLength - 8) / 8;
	array<unsigned char>^ bytes;
	array<unsigned char>^ c1b;
	array<unsigned char>^ c2b;
	BigInt c1, c2, r, M;
	while (streamFrom->Length > streamFrom->Position) 
	{
		bytes = reader->ReadBytes(System::Math::Min(blockLength, (int)(streamFrom->Length - streamFrom->Position)));

		M = bytesToBigInt(bytes);

		r = RandomNumber();
		c1 = FastModuloPower(g, r, p);
		c2 = (M * FastModuloPower(h, r, p)) % p;

		c1b = BigIntToBytes(c1);
		c2b = BigIntToBytes(c2);

		writer->Write(c1b->Length);
		writer->Write(c2b->Length);
		writer->Write(c1b, 0, c1b->Length);
		writer->Write(c2b, 0, c2b->Length);
	}
	reader->Close();
	writer->Close();
}
void ElgamalAlg::DecryptFile(String^ sourcePath, String^ destinationPath)
{
	
	FileStream^ streamFrom = File::Open(sourcePath, System::IO::FileMode::Open);
	BinaryReader^ reader = gcnew BinaryReader(streamFrom);
	FileStream^ streamTo = File::Create(destinationPath);
	BinaryWriter^ writer = gcnew BinaryWriter(streamTo);
	int blockLength = (keyLength - 8) / 8;
	int c1L, c2L;
	array<unsigned char>^ bytes;
	BigInt C1, C2, tmp, M;
	array<unsigned char>^ c1b;
	array<unsigned char>^ c2b;
	while (streamFrom->Length > streamFrom->Position) 
	{
		c1L = reader->ReadInt32();
		c2L = reader->ReadInt32();
		c1b = reader->ReadBytes(c1L);
		c2b = reader->ReadBytes(c2L);
		C1 = bytesToBigInt(c1b);
		C2 = bytesToBigInt(c2b);
		tmp = ReverseModulo(FastModuloPower(C1, a, p), p);
		M = (tmp * C2) % p;
		bytes = BigIntToBytes(M);
		if (bytes->Length < blockLength)
		{
			for (int i = 0; i < (blockLength - bytes->Length); i++)
				writer->Write((unsigned char)0);
		}
		writer->Write(bytes, 0, bytes->Length - 1);
	}
	

	reader->Close();
	writer->Close();
}

System::String ^ ElgamalAlg::encrptText(System::String ^ plainText)
{
	/*String^ result = "";
	int blockLength = (keyLength - 8) / 8;
	System::Collections::Generic::List<String^>^ blocks = gcnew System::Collections::Generic::List<String^>();
	for (int i = 0; i < plainText->Length;  i += blockLength)
	{
		blocks->Add(plainText->Substring(i, System::Math::Min(blockLength, plainText->Length - i)));
	}
	BigInt c1, c2, M, r;
	for each (String^ v in blocks)
	{
		if (!String::IsNullOrEmpty(result))
			result += '\r\n';
		r = RandomNumber();
		M = textToBigInt(v);
		c1 = FastModuloPower(g, r, p);
		c2 = (M * FastModuloPower(h, r, p)) % p;
		result += BigIntToString(c1) + " " + BigIntToString(c2) + " ";
	}
	return result;*/

	String^ result = "";
	int blockLength = (keyLength - 8) / 8;
	System::Collections::Generic::List<String^>^ blocks = gcnew System::Collections::Generic::List<String^>();
	int count = 0;
	for (int i = 0; i < plainText->Length; i += blockLength)
	{
		blocks->Add(plainText->Substring(i, System::Math::Min(blockLength, plainText->Length - i)));
		count++;
	}
	BigInt c1, c2, M, r;
	int i = 0;
	for each (String^ v in blocks)
	{
		r = RandomNumber();
		M = textToBigInt(v);
		c1 = FastModuloPower(g, r, p);
		c2 = (M * FastModuloPower(h, r, p)) % p;
		result += BigIntToString(c1) + " " + BigIntToString(c2) + " ";
	}

	result->Remove(count);

	return result;
}

System::String ^ ElgamalAlg::decryptText(System::String ^ clipherText)
{
	/*String^ result = "";
	int blockLenght = (keyLength - 8) / 8;
	array <String^> ^blocks = clipherText->Split('\r\n');
	String^ c1;
	String^ c2;
	BigInt C1, C2, tmp, M;
	for each (String^ block in blocks)
	{
		array <String^> ^ciphers = block->Split(' ');
		c1 = ciphers[0];
		c2 = ciphers[1];
		C1 = StringToBigInt(c1);
		C2 = StringToBigInt(c2);
		tmp = ReverseModulo(FastModuloPower(C1, a, p), p);
		M = (tmp * C2) % p;
		result += BigIntToText(M);
	}
	return result;*/

	String^ result = "";
	int blockLenght = (keyLength - 8) / 8;
	array <String^> ^blocks = clipherText->Split(' ');

	if (blocks->Length % 2 != 0)
	{
		array <String^> ^tmp = gcnew array <String ^>(blocks->Length + 1);

		for (int i = 0; i < blocks->Length; i++)
			tmp[i] = blocks[i];
			
		tmp[tmp->Length - 1] = "\0";
		blocks = tmp;
	}

	String^ c1;
	String^ c2;
	BigInt C1, C2, tmp, M;
	for(int i=0;i < blocks->Length;)
	{
		c1 = blocks[i++];
		c2 = blocks[i++];
		C1 = StringToBigInt(c1);
		C2 = StringToBigInt(c2);
		tmp = ReverseModulo(FastModuloPower(C1, a, p), p);
		M = (tmp * C2) % p;
		result += BigIntToText(M);
	}
	return result;
}




