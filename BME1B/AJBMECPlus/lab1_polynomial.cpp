#include "stdafx.h"
#include <iostream>
#include<string>
#include<ctime>
#include<fstream>
//#include <__ASSERT.h>

using namespace std;

class Polynomial { 
	int* data;
	int data_size;
public:	
	Polynomial(int A[], int size) {
		data_size = size;
		data = new int[data_size];
		for (int i = 0; i < data_size; i++) {
			data[i] = A[i];
		}
	}
	Polynomial() {
		srand(time(0));
		data_size = rand() % 1000 + 1;
		data = new int[data_size];
		
		for (int i = 0; i < data_size; i++) {
			int randValue = rand() % 1000 + 1;
			data[i] = randValue;
		}
	}
	Polynomial(string fileName) {
		ifstream instream(fileName);
		int in;
		int lineNumber = -1;
		while (!instream.eof()) {
			instream >> in;
			if (lineNumber == -1)
			{
				data_size = in;
				data = new int[data_size];
			}
			else
			{
				data[lineNumber] = in;
			}
			lineNumber++;
		}
		instream.close();
	}
	~Polynomial() {		
			delete[] data;
	}
	bool operator==(const Polynomial& target) {
		bool isValid = true;
		if (this->data_size != target.data_size)
			return false;
		for (int i = 0; i < target.data_size; i++) {
			if (this->data[i] != target.data[i]) {
				isValid = false;
				break;
			}
		}
		return isValid;
	}
	Polynomial operator+(const Polynomial& target)
	{
		Polynomial result;
		for (int i = 0; i < target.data_size; i++) {
			result.data[i] = this->data[i] + target.data[i];
		}
		result.data_size = target.data_size;
		return result;
	}
	Polynomial operator-(const Polynomial& target)
	{
		Polynomial result;
		for (int i = 0; i < target.data_size; i++) {
			result.data[i] = this->data[i] - target.data[i];
		}
		result.data_size = target.data_size;
		return result;
	}
	Polynomial operator*(const Polynomial& target)
	{
		Polynomial result;
		result.data_size = target.data_size + data_size - 1;
		for (int i = 0; i < result.data_size; i++)
		{
			result.data[i] = 0;
		}
		for (int i = 0; i < this->data_size; i++) {
			for (int j = 0; j < target.data_size; j++) {
				int resultValue = this->data[i] * target.data[j];
				int sumValue = result.data[i + j];
				result.data[i + j] = resultValue+sumValue;
			}
		}		
		return result;			
	}
	Polynomial derivative()
	{
		if (data_size == 0)
		{
			Polynomial emptyPoly(0,0);
			return emptyPoly;
		}
		Polynomial result;
		result.data_size = data_size - 1;
		for (int i = 0; i < data_size; i++) {
			result.data[i] = ((i+1) * data[i+1]);
		}		
		return result;
	}
	void print() {
		
		for (int i = 0; i < data_size; i++)
		{
			cout << data[i];
			if (i != 0)
				cout << "x^" << i;
			if (i != data_size - 1)
				cout << " + ";
		}
	}
	friend class PolynomialTest;
};

class PolynomialTest {
	
public:
	bool test_constructor_array() {
		bool isValid = true;
		int testArray[5] = { 19,59,4,41,8 };
		Polynomial polyWithArray(testArray, 5);
		//individually test coefficients
		for (int i = 0; i < 5; i++)
		{
			if (polyWithArray.data[i] != testArray[i])
			{
				isValid = false;
				break;
			}
		}
		return isValid;
	}
	bool test_constructor_string() {
		bool isValid = true;
		Polynomial polyWithString("Polynomial.txt");
		int testArray[8] = { 1,16,-5,6,1,9,8,22 };
		for (int i = 0; i < 5; i++)
		{
			if (polyWithString.data[i] != testArray[i])
			{
				isValid = false;
				break;
			}
		}
		return isValid;

	}
	
	bool test_equals_operator() {
		
		Polynomial polyWithString("Polynomial.txt");
		int testArray[8] = { 1,16,-5,6,1,9,8,22 };
		Polynomial polyWithArray(testArray, 8);
		return polyWithString == polyWithArray;
	}
	
	void run() {
		//test 1 - constructor with array
		if (test_constructor_array())
			cout << "test_constructor_array Passed" << endl;
		else
			cout << "test_constructor_array Failed" << endl;
		//test 2 - constructor with string
		if (test_constructor_string())
			cout << "test_constructor_string Passed" << endl;
		else
			cout << "test_constructor_string Failed" << endl;
		//test 3 - test equal operator
		if (test_equals_operator())
			cout << "test_equals_operator Passed" << endl;
		else
			cout << "test_equals_operator Failed" << endl;
		

	}

};
int main(){
	

	//test constructor with array
	PolynomialTest testClass = PolynomialTest();
	testClass.run();	
	cout << "\n\n";
	return 0;
}