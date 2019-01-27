#include "stdafx.h"
#include <iostream>
#include<string>
#include<ctime>
#include<fstream>
//#include <__ASSERT.h>

using namespace std;

class Polynomial { //declare Polynomial class
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
		srand(time(NULL));
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
		if (data) {
			delete[] data;
			data = NULL;
		}
	}
	bool operator==(const Polynomial& target) {
		*this == target;
	}
	void print() {
		// 1st term
		std::cout << data[data_size - 1] << "x^" << data_size - 1;
		// remaining terms
		for (int i = data_size - 2; i >= 0; i--)
			std::cout << " + " << data[i] << "x^" << i;
		return;
	}
};

int main(){
	//test default constructor
	Polynomial poly = Polynomial();
	cout << "Polynomial Default Constructor=";
	poly.print();

	//test constructor with array
	int testArray[5] = { 19,59,4,41,8 };
	Polynomial polyWithArray(testArray, 5);
	cout << "\n\nPolynomial Array Constructor =";
	polyWithArray.print();

	//test constructor with string parameter
	Polynomial polyWithString("Polynomial.txt");
	cout << "\n\nPolynomial String Constructor =";
	polyWithString.print();
	cout << "\n\n";
	return 0;
}