//============================================================================
// Name        : TensorTest.cpp
// Author      : Pierre-Olivier Marquis ID:40284322
// Description : Assignment 4 - Tensors and File Manipulation
//============================================================================

#include <iostream>
#include "BaseTensor.h"
#include "RankTwoTensor.h"
#include "RankOneTensor.h"
#include <fstream>
#include "IoTDataETL.h"
#include "RankOneTensorType.h"
using namespace std;

//Rank 2 Tensor Addition operator overload test case
void testRankOneTensorAddition() {
	RankOneTensor t1(3);
	t1.loadData();

	cout << "t1 " << t1 << endl;

	RankOneTensor t2(3);
	t2.loadData();

	cout << "t2 " << t2 << endl;

	cout << "t1+t2 " << t1 + t2;
}

//Rank 2 Tensor Addition operator overload test case
void testRankTwoTensorAddition() {
	RankTwoTensor t1(3, 3);
	t1.loadData();

	cout << "t1 " << t1 << endl;

	RankTwoTensor t2(3, 3);
	t2.loadData();

	cout << "t2 " << t2 << endl;

	cout << "t1+t2 " << t1 + t2 << endl;

}
//Rank 1 Tensor Assignment operator overload Test Case
void testRankOneTensorAssignment() {
	RankOneTensor t1(3);
	t1.loadData();
	RankOneTensor t2(3);
	t2.loadData();

	RankOneTensor t3 = t2;

	cout << "t1 " << t1 << endl;
	cout << "t2 " << t2 << endl;
	cout << "t3 " << t3 << endl;

}
//Rank 2 Tensor Assignment operator overload Test Case
void testRankTwoTensorAssignment() {
	RankTwoTensor t1(3, 3);
	t1.loadData();
	RankTwoTensor t2(3, 3);
	t2.loadData();

	RankTwoTensor t3 = t2;

	cout << "t1 " << t1 << endl;
	cout << "t2 " << t2 << endl;
	cout << "t3 " << t3 << endl;
}
//Rank 1 Tensor File Output test case
void testFileOutputStreamOperator() {
	ofstream outputFile("rank1tensor.txt");
	if (!outputFile.is_open()) {
		std::cerr << "Error opening the File!" << std::endl;
		exit(1);
	}
	RankOneTensor t(2);
	cin >> t;
	cout << t << endl;
	outputFile << t << std::endl;

	outputFile.close();
	cout << "Data written to rank1tensor.txt" << endl;
}
//Rank 1 Tensor File Input test case
void testFileInputStreamOperator() {
	RankOneTensor t(0);

	ifstream f;
	try {
		f.open("tensor.txt");
		if (!f) {
			throw ifstream::failure("File not Found.");
			exit(-1);
		} else {
			f >> t;
			cout << "tensor.txt " << t;
			f.close();
		}
	} catch (const ifstream::failure &e) {
		cerr << "File Exception: " << e.what() << endl;
	}
}
//Rank 1 Tensor Input test case
void testRankOneTensorInput() {
	RankOneTensor t(2);
	cin >> t;
	cout << "t " << t;
	RankOneTensor t2(2);
	t2.loadData();
	cout << "t2 " << t2;

	cout << "t + t2 " << t + t2;
}
//Rank 2 Tensor Input test case
void testRankTwoTensorInput() {
	RankTwoTensor t(2, 2);
	cin >> t;
	cout << "t " << t;
	RankTwoTensor t2(2, 2);
	t2.loadData();
	cout << "t2 " << t2;

	cout << "t + t2 " << t + t2;

}
//Rank 1 Increment/Decrement operator overloading testCase
void testRankOneIncrementDerementOperator() {
	RankOneTensor t(2);
	t.loadData();
	cout << "PREFIX INCREMENT: " << endl;
	cout << "Before " << t;
	cout << "Prexix increment " << ++t;
	cout << "After " << t;

	cout << endl << "POSTFIX INCREMENT: " << endl;
	cout << "Before " << t;
	cout << "PostFix increment " << t++;
	cout << "After " << t;

	cout << endl << "PREFIX DECREMENT: " << endl;
	cout << "Before " << t;
	cout << "PreFix decrement " << --t;
	cout << "After " << t;

	cout << endl << "POSTFIX DECREMENT: " << endl;
	cout << "Before " << t;
	cout << "PostFix decrement " << t--;
	cout << "After " << t;
}
//Rank 2 Increment/Decrement operator overloading testCase
void testRankTwoIncrementDecrementOperator() {
	RankTwoTensor t(2, 2);
	t.loadData();
	cout << "PREFIX INCREMENT: " << endl;
	cout << "Before " << t;
	cout << "PreFix increment " << ++t;
	cout << "After " << t;

	cout << endl << "POSTFIX INCREMENT: " << endl;
	cout << "Before " << t;
	cout << "PostFix increment " << t++;
	cout << "After " << t;

	cout << endl << "PREFIX DECREMENT: " << endl;
	cout << "Before " << t;
	cout << "PreFix decrement " << --t;
	cout << "After " << t;

	cout << endl << "POSTFIX DECREMENT: " << endl;
	cout << "Before " << t;
	cout << "PostFix decrement " << t--;
	cout << "After " << t;
}

//Funciton that tests the functionality of Dynamic Casting with Rank 1 and Rank 2 Tensors
void testDynamicCasting() {
	BaseTensor *basePtr = new RankOneTensor(2);

	RankOneTensor *rank1 = dynamic_cast<RankOneTensor*>(basePtr);
	rank1->loadData();
	RankOneTensor *testRankOne = new RankOneTensor(2);
	testRankOne->loadData();

	if (rank1) {
		cout << "RANK 1 DYNAMIC CASTING TEST:" << endl;
		cout << "rank1 " << *(rank1);
		cout << "testRankOne " << (*testRankOne);
		cout << "(rank1) + (test)" << (*rank1) + (*testRankOne);
	} else {
		cout << "Dynamic Cast failed!" << endl;
	}

	BaseTensor *basePtrTwo = new RankTwoTensor(2, 2);

	RankTwoTensor *rank2 = dynamic_cast<RankTwoTensor*>(basePtrTwo);
	rank2->loadData();
	RankTwoTensor *testRankTwo = new RankTwoTensor(2, 2);
	testRankTwo->loadData();

	if (rank2) {
		cout << endl << "RANK 2 DYNAMIC CASTING TEST:" << endl << endl;
		cout << "rank2 " << *(rank2);
		cout << "testRankTwo " << (*testRankTwo);

		cout << "(rank2) + (testRankTwo)" << (*rank2) + (*testRankTwo);
	} else {
		cout << "Dynamic Cast failed!" << endl;
	}
}
//testing exception handling
void testException() {
	RankOneTensor t1(3);
	RankOneTensor t2(4); //since dimensions aren't the same, the first catch is activated
	t1.loadData();
	t2.loadData();
	try {
		cout << (t1 == t2) << endl; //if the dimensions are the same but the elements aren't, then the second catch will activate
	} catch (const std::length_error &f) {
		cerr << "Caught exception: " << f.what() << endl;
	} catch (const std::invalid_argument &e) {
		cerr << "Caught exception: " << e.what() << endl;
	}
}

void testLoadFile() {
	IoTDataETL obj;
	try{
		obj.loadData("iot-data.txt");
	}catch(std::runtime_error& e){
		cerr<<e.what()<<endl;
	}

}

void testIoT(){
	IoTDataETL obj;

	try{
		obj.loadData("iot-data.txt");
		int row = 0;
		int col=11;
		int index = obj.getIndex(obj.getCategory(col));
		cout<<obj.getCategory(col)<< " : "<<obj.getValue(row, col)<<endl; //should return 9 -> value from row 0, column 11 (bwd_pkts_per_sec: 0.156193)
		cout<< obj.extractColValues(index); //prints out the values from column 11 into a RankOneTensorType object

		/*
		 * Note: Lines 55 and 68 of IoTDataETL (in getValue() function) print out the column names and data to tensors respectively.
		 * As to assure a faster run time, they can be uncommented to show the utility of getValue(row, col);
		 */

	}catch(std::runtime_error& e){
		cerr<<"Runtime Error: " << e.what()<< endl;
	}
}


int main() {
	testRankOneTensorAddition();
	testRankTwoTensorAddition();
	testRankOneTensorAssignment();
	testRankTwoTensorAssignment();
	testRankTwoIncrementDecrementOperator();
	testDynamicCasting();
	testException();
	testFileInputStreamOperator();
	testLoadFile();

	testIoT();

	return 0;
}
