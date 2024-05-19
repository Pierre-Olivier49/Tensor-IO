/*
 * RankTwoTensor.h
 *
 *  Created on: Mar. 18, 2024
 *  Pierre-Olivier Marquis ID:40284322
 */

#ifndef RANKTWOTENSOR_H_
#define RANKTWOTENSOR_H_

#include "BaseTensor.h"
#include "RankOneTensor.h"
#include<iostream>
#include <vector>
#include <iomanip>

class RankTwoTensor: public BaseTensor {
private:
std::vector<std::vector<double>> data;
//use RankOneTensor inside the vector instead of an array of doubles -> polymorphism

public:
	//Parameterized Constructor for Rank 2 tensor
	RankTwoTensor(int rows, int cols): data(rows, std::vector<double>(cols)){}

	//Rank 2 Tensor '==' operator overload
	bool operator==(const RankTwoTensor& other) const{
			if(this->data.size() != other.data.size()){
				throw std::length_error("Tensors must have the same sized dimensions to be compared");
			}

			for(size_t i = 0; i<data.size(); i++){
				for(size_t j=0; j<data[0].size();j++){
					if(data[i][j] != other.data[i][j]){
						throw std::invalid_argument("The elements are not the same.");
						return false;
					}
				}


			}
			return true;
		}


	//Addition Operator Overload
	RankTwoTensor operator+(const RankTwoTensor& other){

	if((this->data.size() == other.data.size()) && (this->data[0].size()==other.data[0].size())){
		RankTwoTensor obj(data.size(), data[0].size());
	for(size_t i = 0; i<data.size();i++){
		for(size_t j=0; j<data[0].size(); j++){
			obj.data[i][j]= this->data[i][j] + other.data[i][j];
			}
		}
		return obj;
	}else{
		std::cerr<<"Dimensions are not the same!"<<std::endl;
		return RankTwoTensor(0,0);
	}

	}
	//Assignment Operator Overload
	void operator=(const RankTwoTensor& other){
		data.resize(other.data.size());
		for(size_t i = 0; i<data.size(); i++){

			data[i].resize(other.data[i].size());

			for(size_t j=0; j<data[i].size(); j++){
				data[i][j]=other.data[i][j];
			}
		}
		}
	//PreFix Increment
	RankTwoTensor operator++(){
			for(size_t i=0; i<data.size(); i++){
				for(size_t j=0; j<data[0].size(); j++){
					++(data[i][j]);
				}
			}
			return *this;
		}
	//PostFix Increment
	RankTwoTensor operator++(int){
		RankTwoTensor t=*this;
			for(size_t i=0; i<this->data.size(); i++){
				for(size_t j=0; j<this->data[0].size(); j++){
					this->data[i][j]++;
				}
			}
			return t;
		}

	//PreFix Decrement
	RankTwoTensor operator--(){
		for(size_t i=0; i<this->data.size(); i++){
			for(size_t j=0; j<this->data[0].size(); j++){
				--data[i][j];
			}
		}
		return *this;
	}
	//PostFix Decrement
	RankTwoTensor operator--(int){
		for(size_t i=0; i<this->data.size(); i++){
			for(size_t j=0; j<this->data[0].size(); j++){
				data[i][j]--;
			}
		}
		return *this;
	}
	//Output Operator Overload
	friend std::ostream& operator<<(std::ostream& os, const RankTwoTensor& tensor){
		 os << "Data:" << std::endl;
		    for(size_t i = 0; i < tensor.data.size(); ++i){
		        os << "[ ";
		        for(size_t j = 0; j < tensor.data[i].size(); ++j){
		            os << std::setw(4) << tensor.data[i][j] << " ";
		        }
		        os << " ]" << std::endl;
		    }
		    return os;
		}
	//Input Operator Overload
	friend std::istream& operator>>(std::istream& in, RankTwoTensor& tensor){
		for(size_t i = 0; i<tensor.data.size(); i++){
			for(size_t j=0; j<tensor.data[0].size(); j++){
				cout<<"Please type in your values to the tensor"<<std::endl;
				in>>tensor.data[i][j];
			}

		}
		return in;
		}


	//LoadData overriden function for Rank 2 Tensors
	void loadData() override{
		for(size_t i=0; i<data.size(); i++){
			for(size_t j=0; j<data[0].size(); j++){
				data[i][j]=valueGen();
			}
		}
	}
};

#endif /* RANKTWOTENSOR_H_ */
