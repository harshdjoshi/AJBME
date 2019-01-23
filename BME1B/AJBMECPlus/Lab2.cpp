#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include <__ASSERT.h>

using namespace std;

class Polynomial { //declare Polynomial class
	int* data;
	int data_size;
public:
	Polynomial(int A[], int size) {
		data = new int[size];
	}
	~Polynomial() {
		delete [] data;
	}
};

int main()
{

}