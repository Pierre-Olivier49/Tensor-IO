/*
 * RankOneTensorType.h
 *
 *  Created on: Mar. 27, 2024
 *  Pierre-Olivier Marquis ID:40284322
 */

#ifndef RANKONETENSORTYPE_H_
#define RANKONETENSORTYPE_H_
#include <vector>
#include <string>
#include <iostream>


template<typename T>
class RankOneTensorType: public BaseTensor {
public:
	RankOneTensorType(): data(0){} //Default Constructor
	RankOneTensorType(int size): data(size){} //Parameter constructor

	//[] operator overload
	T& operator[](int index){
		return data[index];
	}

	const T& operator[](int index) const{
		return data[index];
	}

	//Double equal operator overload
	bool operator==(const RankOneTensorType& other) const{
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
	//!= operator overload
	bool operator!=(const RankOneTensorType& other) const{
		if(this->data.size() != other.data.size()){
			throw std::length_error("Tensors must have the same sized dimensions to be compared");
		}
		for(size_t i = 0; i<data.size(); i++){
			if(data[i] == other.data[i]){
				throw std::invalid_argument("The elements are not the same.");
				return true;
			}
		}
		return false;
	}



		//Addition Operator Overload
		RankOneTensorType operator+(const RankOneTensor& other){

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
		void operator=(const RankOneTensorType& other){
				data.resize(other.data.size());
				for(size_t i = 0; i<data.size();i++){
					data[i] = other.data[i];
				}
		}
		//Output Operator Overload
		friend std::ostream& operator<<(std::ostream& os, const RankOneTensorType& tensor){
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
		friend std::istream& operator>>(std::istream& in, RankOneTensorType& tensor){
			T value;
			while(getline(in, value, ',')){
				tensor.data.push_back(value);
			}
			return in;

		}
		//Prefix Increment
		RankOneTensorType operator++(){
			for(size_t i=0; i<this->data.size(); i++){
				++data[i];
			}
			return *this;
		}
		//PostFix Increment
		RankOneTensorType operator++(int){
			RankOneTensorType t = *this;
			for(size_t i=0; i<this->data.size(); i++){
				data[i]++;
			}
			return t;
		}
		//PreFix Decrement
		RankOneTensorType operator--(){
			for(size_t i=0; i<this->data.size(); i++){
				--data[i];
			}
			return *this;
		}

		//PostFix Decrement
		RankOneTensorType operator--(int){
			RankOneTensorType t = *this;
			for(size_t i=0; i<this->data.size(); i++){
				data[i]--;
			}
			return t;
		}

		void loadData() override{

			for(size_t i = 0; i<data.size(); i++){
				this->data[i]= valueGen();
			}

		}

		void insertData(T item){
			data.push_back(item);
		}

private:
	std::vector<T> data;
};

#endif /* RANKONETENSORTYPE_H_ */
