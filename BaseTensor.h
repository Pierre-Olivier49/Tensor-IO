/*
 * BaseTensor.h
 *
 * Mar. 18, 2024
 * Pierre-Olivier Marquis ID:40284322
 */

#ifndef BASETENSOR_H_
#define BASETENSOR_H_
#include <random>
using namespace std;

class BaseTensor {
public:
	virtual void loadData() = 0;
	double valueGen(){ //Value Generation function
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<double> dist(0.0, 1.0);
		double randomValue = dist(mt);
		return randomValue;
	}

};

#endif /* BASETENSOR_H_ */
