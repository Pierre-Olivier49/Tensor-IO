/*
 * RankOneTensor.h
 *
 *  Created on: Mar. 18, 2024
 * Pierre-Olivier Marquis ID:40284322
 */

#ifndef RANKONETENSOR_H_
#define RANKONETENSOR_H_

#include "BaseTensor.h"
#include <vector>
#include <iostream>

class RankOneTensor: public BaseTensor {
private:
	std::vector<double> data;
public:
	//Parameterized Constructor for Rank 1 tensor
	RankOneTensor(int size): data(size){}

	double& operator[](int index){
		return data[index];
	}

	//Overloaded == operator
	bool operator==(const RankOneTensor& other) const{
		if(this->data.size() != other.data.size()){
			throw std::length_error("Tensors must have the same sized dimensions to be compared");
		}

		for(size_t i = 0; i<data.size(); i++){
			if(data[i] != other.data[i]){
				throw std::invalid_argument("The elements are not the same.");
				return false;
			}
		}
		return true;
	}

	//Addition Operator Overload
	RankOneTensor operator+(const RankOneTensor& other){

	if(this->data.size() == other.data.size()){
		RankOneTensor obj(data.size());
	for(size_t i = 0; i<data.size();i++){
			obj.data[i]= this->data[i] + other.data[i];
			}
		return obj;
	}else{
		std::cerr<<"Dimensions are not the same!"<<std::endl;
		return RankOneTensor(0);
	}

	}
	//Assignment Operator Overload
	void operator=(const RankOneTensor& other){
			data.resize(other.data.size());
			for(size_t i = 0; i<data.size();i++){
				data[i] = other.data[i];
			}
	}
	//Output Operator Overload
	friend std::ostream& operator<<(std::ostream& os, const RankOneTensor& tensor){
		os<<"Data: [";
		for(size_t i=0; i<tensor.data.size(); ++i){
			os<<tensor.data[i];
			if(i<tensor.data.size()-1)
				os<<" , ";

		}
		os <<']'<<std::endl;
		return os;
	}
	//Input Operator Overload
	friend std::istream& operator>>(std::istream& in, RankOneTensor& tensor){
		/*
		for(size_t i = 0; i<tensor.data.size(); i++){
			cout<<"Please type in your values to the tensor"<<std::endl;
			in>>tensor.data[i];
		}
		return in;
		*/
		double value;
		while(in>>value){
			tensor.data.push_back(value);
		}
		return in;

	}
	//Prefix Increment
	RankOneTensor operator++(){
		for(size_t i=0; i<this->data.size(); i++){
			++data[i];
		}
		return *this;
	}
	//PostFix Increment
	RankOneTensor operator++(int){
		RankOneTensor t = *this;
		for(size_t i=0; i<this->data.size(); i++){
			data[i]++;
		}
		return t;
	}
	//PreFix Decrement
	RankOneTensor operator--(){
		for(size_t i=0; i<this->data.size(); i++){
			--data[i];
		}
		return *this;
	}

	//PostFix Decrement
	RankOneTensor operator--(int){
		RankOneTensor t = *this;
		for(size_t i=0; i<this->data.size(); i++){
			data[i]--;
		}
		return t;
	}


	//LoadData overriden function for Rank 1 Tensors
	void loadData() override{

		for(size_t i = 0; i<data.size(); i++){
			this->data[i]= valueGen();
		}

		//std::fill(this->data.begin(), this->data.end(), valueGen());
	}
};

#endif /* RANKONETENSOR_H_ */
