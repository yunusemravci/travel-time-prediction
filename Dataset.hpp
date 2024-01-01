//
//  Dataset.hpp
//  TravelTime-Prediction
//
//  Created by yunus emre avcı on 2.12.2023.
//

#ifndef Dataset_hpp
#define Dataset_hpp

#include <stdio.h>
#include <iostream>
#include "Vehicle.hpp"
#include <fstream>
#include <sstream>

using namespace std;

class Dataset {
    
private:
    string data_path;
    vector<Vehicle> vehicles;
    
public:
    Dataset(string path);
    void load_dataset();
    vector<Vehicle> getVehicles();
    string getData_path();
    void setData_path(string path);
    void show_head_dataset();
    vector<string> split(const string& str, const string& delimiter);

};
#endif /* Dataset_hpp */
