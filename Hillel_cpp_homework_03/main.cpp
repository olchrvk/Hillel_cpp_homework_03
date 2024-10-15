#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void func1(float*& var1, int& var2);
void func2(float* var3, int var4);

int main()
{
	float* arrayAddress = new float(30);
	int arrayLength = 0;

	cout << "----Before----" << "\n";
	cout << "Array address: " << arrayAddress << "\n";
	cout << "Array length: " << arrayLength << "\n";

	func1(arrayAddress, arrayLength);

	cout << "----After----" << "\n";
	cout << "Array address: " << arrayAddress << "\n";
	cout << "Array length: " << arrayLength << "\n";

	func2(arrayAddress, arrayLength);

	return 0;
}

void func1(float*& var1, int& var2) 
{
	if (var1 != nullptr)
		delete var1;

	const int arrayLength = 20;

	float* array = new float[20];

	var1 = array;

	var2 = arrayLength;

	srand(time(0));

	for (int i = 0; i < arrayLength; i++)
	{
		array[i] = rand();
	}
}


void func2(float* var3, int var4)
{
	if (var3 == nullptr)
		return;

	cout << "###START PRINT###" << "\n";
	for (int i = 0; i < var4; i++)
	{
		cout << "Element [" << i + 1 << "]: " << *(var3 + i) << "\n";
	}
	cout << "###END PRINT###" << "\n";
}
