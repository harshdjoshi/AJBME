//**********************************************************************
// Student Names: Akanksha Joshi, Sydney Pothier
//
// BME 122 Lab: 1 Assignment: Polynomial
// Filename: lab1_polynomial.cpp
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
#include "stdafx.h"
#include<iostream>
#include "lab1_polynomial.h"



using namespace std;

class PolynomialTest {
public:

	void test_constructor_default() {
		Polynomial poly1;
		Polynomial poly2;
		Polynomial poly3;
		poly1.print();
		cout << poly1.data_size << endl;
		poly2.print();
		cout << poly2.data_size << endl;
		poly3.print();
		cout << poly3.data_size << endl;
		cout << "test_constructor_default Passed" << endl;
	}

	void test_constructor_array() {
		bool passed1 = true;
		bool passed2 = true;
		bool passed3 = true;
		int testArray1[5] = { 19, 59, 4, 41, 8 };
		int* testArrayOne = testArray1;
		Polynomial polyWithArray1(testArrayOne, 5);
		int testArray2[5] = { 19, 59, 4, 41, 0 };
		int* testArrayTwo = testArray2;
		Polynomial polyWithArray2(testArrayTwo, 5);
		int testArray3[5] = { 0, 1, 2, 3, 4 };
		int* testArrayThree = testArray3;
		Polynomial polyWithArray3(testArrayThree, 5);
		//individually test coefficients
		for (int i = 0; i < 5; i++)
		{
			if (polyWithArray1.data[i] != testArray1[i])
			{
				int test = polyWithArray1.data[i];
				passed1 = false;
				break;
			}
		}

		for (int i = 0; i < 5; i++)
		{
			if (polyWithArray2.data[i] != testArray2[i])
			{
				passed2 = false;
				break;
			}
		}

		for (int i = 0; i < 5; i++)
		{
			if (polyWithArray3.data[i] != testArray3[i])
			{
				passed3 = false;
				break;
			}
		}

		if (passed1 && passed2 && passed3)
		{
			cout << "test_constructor_array Passed" << endl;
		}

		else
		{
			cout << "test_constructor_array Failed" << endl;
		}
	}
	
	void test_constructor_string() {
		bool passed = true;
		Polynomial polyWithString("Polynomial.txt");
		int testArray[8] = { 1,16,-5,6,1,9,8,22 };
		for (int i = 0; i < 8; i++)
		{
			if (polyWithString.data[i] != testArray[i])
			{
				passed = false;
				break;
			}
		}

		if (passed)
		{
			cout << "test_constructor_string Passed" << endl;
		}

		else
		{
			cout << "test_constructor_string Failed" << endl;
		}
	}

	void test_equals_operator() {
		bool passed1 = true;
		bool passed2 = true;
		bool passed3 = true;
		int testArray1[5] = { 19, 59, 4, 41, 8 };
		Polynomial poly1(testArray1, 5);
		Polynomial duplicatePoly1(testArray1, 5);
		int testArray2[5] = { 19, 59, 4, 41, 0 };
		Polynomial poly2(testArray2, 5);
		Polynomial duplicatePoly2(testArray2, 5);
		int testArray3[5] = { 0, 1, 2, 3, 4 };
		Polynomial poly3(testArray3, 5);
		Polynomial duplicatePoly3(testArray3, 5);
		passed1 = poly1 == duplicatePoly1;
		passed2 = poly2 == duplicatePoly2;
		passed3 = poly3 == duplicatePoly3;

		if (passed1 && passed2 && passed3)
		{
			cout << "test_equals_operator Passed" << endl;
		}

		else
		{
			cout << "tes_equals_operator Failed" << endl;
		}
	}

	void test_multiply_operator() {
		bool passed1, passed2, passed3 = true;
		//TEST CASE 1
		int testArray1[4] = { 5, 0, 10, 6 };
		int testArray2[3] = { 1, 2, 4 };
		Polynomial poly1(testArray1, 4);
		Polynomial poly2(testArray2, 3);
		int resultArray1[6] = { 5, 10, 30, 26, 52, 24 };
		Polynomial resultPoly1(resultArray1, 6);
		Polynomial returnPoly1 = poly1 * poly2;
		passed1 = returnPoly1 == resultPoly1;
		//TEST CASE 2
		int testArray3[2] = { 2, 3 };
		int testArray4[4] = { 0, 1, 2, 3 };
		Polynomial poly3(testArray3, 2);
		Polynomial poly4(testArray4, 4);
		int resultArray2[5] = { 0, 2, 7, 12, 9 };
		Polynomial resultPoly2(resultArray2, 5);
		Polynomial returnPoly2 = poly3 * poly4;
		passed2 = returnPoly2 == resultPoly2;
		//TEST CASE 3
		int testArray5[4] = { 5, 4, 3, 0 };
		int testArray6[3] = { 1, 0, 1 };
		Polynomial poly5(testArray5, 4);
		Polynomial poly6(testArray6, 3);
		int resultArray3[6] = { 5, 4, 8, 4, 3, 0 };
		Polynomial resultPoly3(resultArray3, 6);
		Polynomial returnPoly3 = poly5 * poly6;
		passed3 = returnPoly3 == resultPoly3;

		if (passed1 && passed2 && passed3)
		{
			cout << "test_multiply_operator Passed" << endl;
		}

		else
		{
			cout << "test_multiply_operator Failed" << endl;
		}
	}

	void test_add_operator() {
		bool passed1, passed2, passed3 = true;
		//TEST CASE 1
		int testArray1[4] = { 5, 0, 10, 6 };
		int testArray2[3] = { 1, 2, 4 };
		Polynomial poly1(testArray1, 4);
		Polynomial poly2(testArray2, 3);
		int resultArray1[4] = { 6, 2, 14, 6 };
		Polynomial resultPoly1(resultArray1, 4);
		Polynomial returnPoly1 = poly1 + poly2;
		passed1 = returnPoly1 == resultPoly1;
		//TEST CASE 2
		int testArray3[2] = { 2, 3 };
		int testArray4[4] = { 0, 1, 2, 3 };
		Polynomial poly3(testArray3, 2);
		Polynomial poly4(testArray4, 4);
		int resultArray2[4] = { 2, 4, 2, 3 };
		Polynomial resultPoly2(resultArray2, 4);
		Polynomial returnPoly2 = poly3 + poly4;
		passed2 = returnPoly2 == resultPoly2;
		//TEST CASE 3
		int testArray5[4] = { 5, 4, 3, 0 };
		int testArray6[3] = { 1, 0, 1 };
		Polynomial poly5(testArray5, 4);
		Polynomial poly6(testArray6, 3);
		int resultArray3[4] = { 6, 4, 4,0 };
		Polynomial resultPoly3(resultArray3, 4);
		Polynomial returnPoly3 = poly5 + poly6;
		passed3 = returnPoly3 == resultPoly3;

		if (passed1 && passed2 && passed3)
		{
			cout << "test_add_operator Passed" << endl;
		}

		else
		{
			cout << "test_add_operator Failed" << endl;
		}
	}

	void test_subtract_operator() {
		bool passed1, passed2, passed3 = true;
		//TEST CASE 1
		int testArray1[4] = { 5, 0, 10, 6 };
		int testArray2[3] = { 1, 2, 4 };
		Polynomial poly1(testArray1, 4);
		Polynomial poly2(testArray2, 3);
		int resultArray1[4] = { 4, -2, 6, 6 };
		Polynomial resultPoly1(resultArray1, 4);
		Polynomial returnPoly1 = poly1 - poly2;
		passed1 = returnPoly1 == resultPoly1;
		//TEST CASE 2
		int testArray3[2] = { 2, 3 }; //3x+2
		int testArray4[4] = { 0, 1, 2, 3 }; //3x^3 + 2x^2 + 1x
		Polynomial poly3(testArray3, 2);
		Polynomial poly4(testArray4, 4);
		int resultArray2[4] = { 2, 2, -2, -3 };
		Polynomial resultPoly2(resultArray2, 4);
		Polynomial returnPoly2 = poly3 - poly4;
		passed2 = returnPoly2 == resultPoly2;
		//TEST CASE 3
		int testArray5[4] = { 5, 4, 3, 0 };
		int testArray6[4] = { 5, 4, 3, 0 };
		Polynomial poly5(testArray5, 4);
		Polynomial poly6(testArray6, 3);
		int resultArray3[4] = {4};
		Polynomial resultPoly3(resultArray3, 4);
		Polynomial returnPoly3 = poly5 - poly6;
		passed3 = returnPoly3 == resultPoly3;

		if (passed1 && passed2 && passed3)
		{
			cout << "test_subtract_operator Passed" << endl;
		}

		else
		{
			cout << "test_subtract_operator Failed" << endl;
		}
	}

	void test_derivative_operator() {
		bool passed1, passed2, passed3 = true;
		//TEST CASE 1
		int testArray1[4] = { 1, 2, 3, 4 };
		Polynomial poly1(testArray1, 4);
		int result1[3] = { 2, 6, 12 };
		Polynomial resultPoly1(result1, 3);
		Polynomial returnPoly1 = poly1.derivative();
		passed1 = returnPoly1 == resultPoly1;
		//TEST CASE 2
		int testArray2[5] = { 1, 2, 3, 4, 0 };
		Polynomial poly2(testArray2, 5);
		int result2[3] = { 2, 6, 12 };
		Polynomial resultPoly2(result2, 3);
		Polynomial returnPoly2 = poly2.derivative();
		passed2 = returnPoly2 == resultPoly2;
		//TEST CASE 3
		int testArray3[6] = { 0, 1, 2, 3, 4, 5 };
		Polynomial poly3(testArray3, 6);
		int result3[5] = { 1, 4, 9, 16, 25 };
		Polynomial resultPoly3(result3, 5);
		Polynomial returnPoly3 = poly3.derivative();
		passed3 = returnPoly3 == resultPoly3;

		if (passed1 && passed2 && passed3)
		{
			cout << "test_derivative_operator Passed" << endl;
		}

		else
		{
			cout << "test_derivative_operator Failed" << endl;
		}
	}

	void run() {
		//test 1 - default constructor
		test_constructor_default();

		//test 2 - constructor with array
		test_constructor_array();

		//test 3 - constructor with string
		test_constructor_string();

		//test 4 - test equal operator
		test_equals_operator();

		//test 5 - test multiply operator
		test_multiply_operator();

		//test 6 - test add operator
		test_add_operator();

		//test 7 - test subtract operator
		test_subtract_operator();

		//test 8 - test derivative operator
		test_derivative_operator();
	}
};

int main() {

	PolynomialTest testClass = PolynomialTest();
	testClass.run();
	cout << "\n";
	_getch();
	return 0;
}