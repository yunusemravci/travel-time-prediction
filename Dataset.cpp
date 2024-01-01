//
//  Dataset.cpp
//  TravelTime-Prediction
//
//  Created by yunus emre avcı on 2.12.2023.
//

#include "Dataset.hpp"

Dataset::Dataset(string path){
    data_path = path;
}
vector<Vehicle> Dataset::getVehicles(){
    return vehicles;
}
string Dataset::getData_path(){
    return data_path;
}
void Dataset::setData_path(string path){
    data_path = path;
}
vector<string> Dataset::split(const string &str, const string &delimiter){
    vector<string> tokens;
    size_t prev=0, pos=0;
    
    do {
        pos = str.find(delimiter, prev);
        if (pos == string::npos) pos = str.length();
            string token = str.substr(prev, pos-prev);
            if (!token.empty()) tokens.push_back(token);
            prev = pos + delimiter.length();
    } while (pos < str.length() && prev < str.length());
    
    return tokens;
}

void Dataset::load_dataset(){
    ifstream inputfile;
    string row;
    
    inputfile.open(getData_path());
    
    // Skip the header line
    getline(inputfile, row);
    
    
    while(getline(inputfile,row)){
        Vehicle tempVehicle;
        vector<string> tokens = split(row, "; ");
        if (tokens.size() < 10) return;
        vector<double> lat, lon, lat_acc, lon_acc, speed, time;
        // Parse first four columns
        tempVehicle.setTrack_ID(stoi(tokens[0]));
        tempVehicle.setType(tokens[1]);
        tempVehicle.setTraveled_d(stod(tokens[2]));
        tempVehicle.setAvg_speed(stod(tokens[3]));
        
        
        for (size_t i=4; i+5 < tokens.size(); i+=6) {
            try {
                lat.push_back(stod(tokens[i]));
                lon.push_back(stod(tokens[i+1]));
                speed.push_back(stod(tokens[i+2]));
                lat_acc.push_back(stod(tokens[i+3]));
                lon_acc.push_back(stod(tokens[i+4]));
                time.push_back(stod(tokens[i+5]));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid argument for std::stod conversion: " << e.what() << std::endl;
            }
            
        }
        
        tempVehicle.setLat(lat);
        tempVehicle.setLon(lon);
        tempVehicle.setLat_acc(lat_acc);
        tempVehicle.setLon_acc(lon_acc);
        tempVehicle.setSpeed(speed);
        tempVehicle.setTime(time);
        
        vehicles.push_back(tempVehicle);
        
    }
    
    inputfile.close();
}
