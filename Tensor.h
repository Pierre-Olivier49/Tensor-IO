/*
 * Tensor.h
 *
 *  Created on: Mar. 18, 2024
 *  Pierre-Olivier Marquis ID:40284322
 */

#ifndef TENSOR_H_
#define TENSOR_H_

#include <iostream>
#include <random>
#include "BaseTensor.h"

using namespace std;

double valueGen(){
	 std::random_device rd;
	 std::mt19937 mt(rd());

	    // Create a uniform distribution between 0 and 1
	  std::uniform_real_distribution<double> dist(0.0, 1.0);

	    // Generate and print a random double value
	  double randomValue = dist(mt);
	  return randomValue;
}

// Derived class that represents a specific tensor
class Tensor : public BaseTensor {
private:
    std::vector<double> data;

public:
    Tensor(int size) : data(size){}

    // Overload the + operator for tensor addition
    Tensor operator+(const Tensor& other) {
        Tensor result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    // Overload the - operator for tensor subtraction
    Tensor operator-(const Tensor& other) {
        Tensor result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }


    Tensor operator*(const Tensor& other) {
    	   //typical forward propergation;
            Tensor result(data.size());
            for (size_t i = 0; i < data.size(); ++i) {
                result.data[i] = (double) (data[i] * other.data[i]);

            }
            return result;
     }

    void loadData() override{
    	std::fill(data.begin(), data.end(),valueGen() );
    }

    // Friend function to overload the << operator for output
    friend std::ostream& operator<<(std::ostream& os, const Tensor& tensor) {
        os << "Data: [";
        for (size_t i = 0; i < tensor.data.size(); ++i) {
            os << tensor.data[i];
            if (i < tensor.data.size() - 1)
            	os << ", ";
        }
        os << ']' <<endl;

        return os;
    }
};




#endif /* TENSOR_H_ */
