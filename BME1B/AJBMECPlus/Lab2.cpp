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
		data = new int[size];
		while (A[size - 1] == 0) {
			size--;
		}
		for (int i = size-1; i >= 0; i--) {
			if (A[i] == 0) {
				size--;
			}
			data[i] = A[i];
		}
	}
	Polynomial() {
		srand(time(0));
		data = new int[rand() % 1001];
		for (int i = 0; i < sizeof(data)-1; i++) {
			data[i] = rand() % 1001;
		}
	}
	Polynomial(string fileName) {
		ifstream instream("polynomial.txt");
		int in;
		while (!instream.eof()) {
			instream >> in;
			data_size = in;
		}
		data = new int[data_size];
		for (int i = 0; i < data_size - 1; i++) {
			
		}

		instream.close();
	}
	~Polynomial() {
		delete [] data;
	}
	bool operator==(const Polynomial& target) {

	}
};

int main()
{

}