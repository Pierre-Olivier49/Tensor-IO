
 * IoTDataETL.h
 *
 *  Created on: Mar. 27, 2024
 *  Pierre-Olivier Marquis ID:40284322
 */

#ifndef IOTDATAETL_H_
#define IOTDATAETL_H_
#include <vector>
#include <fstream>
#include "RankOneTensorType.h"
#include <iostream>
#include <string>
#include <limits.h>
#include <algorithm>
#include <iterator>
using namespace std;


class IoTDataETL {
public:
	IoTDataETL(){
		iot_category.resize(0);
		iot_data.resize(0);
	}

	double getValue(int row, int col){
		double value{INT_MAX};
		try{
			RankOneTensorType<string> tensor = iot_data[row];
			value = std::stod(tensor[col]);

		}catch(std::invalid_argument& ia){
			std::cerr<<"Invalid argument: "<<ia.what()<<'\n';
		}catch(std::out_of_range& oor){
			std::cerr<<"Out Of Range: "<<oor.what()<<'\n';
		}
		return value;
	}

	void loadData(std::string fileLocation){
		ifstream file(fileLocation);
		if(!file){
			string error_msg=fileLocation + " was not opened properly!";
			throw std::runtime_error(error_msg);
		}
		string line;
		getline(file, line);
		stringstream lineString(line);

		int size(0);
		string token;
		while(getline(lineString, token, ',')){
			cout<<token<<endl; //UNCOMMENT HERE TO PRINT OUT CATEGORIES TO CONSOLE
			iot_category.push_back(token);
			++size;
		}

		while(getline(file, line)){
			lineString.clear();
			lineString.str("");
			lineString.str(line);
			string token;

			RankOneTensorType<string> tensor(0);
			lineString>>tensor;
			cout<<tensor<<endl; //UNCOMMENT HERE TO PRINT OUT ALL ROWS (0-12) TO A RANK-ONE-TENSOR-TYPE OBJECT
			iot_data.push_back(tensor);

		}
		file.close();
	}

	string getCategory(int index){
		return iot_category[index];
	}

	RankOneTensorType<string> extractColValues(int index){
		RankOneTensorType<string> tensor(0);

		for(RankOneTensorType<string> t: iot_data){
			tensor.insertData(t[index]);
		}
		return tensor;

	}

	RankOneTensorType<string> extractColValues(string colName){
		int found_index{-1};

		std::vector<string>::iterator first = iot_category.begin();
		std::vector<string>::iterator end = iot_category.end();

		std::vector<string>::iterator it = std::find(first, end, colName);

		if( it != iot_category.end()){
			found_index = std::distance(iot_category.begin(), it);
		}
		RankOneTensorType<string> tensor(0);

		for(std::vector<RankOneTensorType<string>>::iterator it = iot_data.begin(); it != iot_data.end(); ++it){
			//[] is the operator overloaded for class RankOneTensorType<T>
			tensor.insertData((*it)[found_index]);
		}

		return tensor;

	}

	int getIndex(string category){
		for(size_t i=0; i<iot_category.size(); i++){

			if(iot_category[i] == category){
				return i;
			}
		}
		return -1;
	}



private:
	std::vector<string> iot_category;
	std::vector<RankOneTensorType<string>> iot_data;

};

#endif /* IOTDATAETL_H_ */
