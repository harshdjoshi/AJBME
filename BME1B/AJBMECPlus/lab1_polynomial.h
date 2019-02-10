//**********************************************************************
// Student Names: Akanksha Joshi, Sydney Pothier
//
// BME 122 Lab: 1 Assignment: Polynomial
// Filename: lab1_polynomial.hpp
//
// We hereby declare that this code, submitted for the course
// BME 122, is a product of our own efforts. This coded solution has
// not been plaigarized from other sources and has not been knowingly
// plaigarized by others.
//
// Project: Polynomial Representation as an ADT
// Purpose: Implement the mathematical concept of a polynomial
// as an ADT using sequential list ADT as a template
// Due Date: Monday, February 11, 2019
//***********************************************************************

#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include "stdafx.h"

using namespace std;

class Polynomial {

	int* data;
	int data_size;

public:

	Polynomial(int A[], int size) {
		if (sizeof(A) == size)
		{
			data_size = size;
			data = new int[data_size];

			for (int i = 0; i < data_size; i++)
			{
				data[i] = 0;
			}

			for (int i = 0; i < data_size; i++)
			{
				data[i] = A[i];
			}
		}
	}

	Polynomial() {
		srand(time(0));
		data_size = rand() % 1001;
		data = new int[data_size];
		data[0] = rand() % 1000 + (-1000) || rand() % 1001;

		for (int i = 1; i < data_size; i++)
		{
			int randValue = rand() % 2000 + (-1000);
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
		if (data_size != target.data_size)
		{
			return false;
		}

		for (int i = 0; i < data_size; i++)
		{
			if (data[i] != target.data[i])
			{
				isValid = false;
				break;
			}
		}

		return isValid;
	}

	Polynomial operator+(const Polynomial& target)
	{
		Polynomial result;

		for (int i = 0; i < target.data_size; i++)
		{
			result.data[i] = this->data[i] + target.data[i];
		}

		result.data_size = target.data_size;
		return result;
	}

	Polynomial operator-(const Polynomial& target)
	{
		Polynomial result;

		for (int i = 0; i < target.data_size; i++)
		{
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
		for (int i = 0; i < this->data_size; i++)
		{
			for (int j = 0; j < target.data_size; j++)
			{
				int resultValue = this->data[i] * target.data[j];
				int sumValue = result.data[i + j];
				result.data[i + j] = resultValue + sumValue;
			}
		}

		return result;
	}

	Polynomial derivative()
	{
		if (data_size == 0)
		{
			Polynomial emptyPoly(0, 0);
			return emptyPoly;
		}
		Polynomial result;
		result.data_size = data_size - 1;
		for (int i = 0; i < data_size; i++)
		{
			result.data[i] = ((i + 1) * data[i + 1]);
		}

		return result;
	}

	void print() {

		for (int i = 0; i < data_size; i++)
		{
			cout << data[i];
			if (i != 0)
			{
				cout << "x^" << i;
			}
			if (i != data_size - 1)
			{
				cout << " + ";
			}
		}
	}

	friend class PolynomialTest;
};

