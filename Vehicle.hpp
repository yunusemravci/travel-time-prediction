//
//  Vehicle.hpp
//  TravelTime-Prediction
//
//  Created by yunus emre avcı on 2.12.2023.
//

#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Vehicle{

private:
    int track_ID;
    string vtype;
    double traveled_d, avg_speed;
    vector<double> lat, lon, speed, lon_acc, lat_acc, time;

    
public:
    Vehicle();
    int getTrack_ID();
    string getType() const;
    double getTraveled_d() const;
    double getAvg_speed() const;
    vector<double> getLat()const;
    vector<double> getLon()const;
    vector<double> getLon_acc()const;
    vector<double> getLat_acc()const;
    vector<double> getSpeed()const;
    vector<double> getTime() const;
    
    void setTrack_ID(int track_id);
    void setType(string vtype);
    void setTraveled_d(double traveled_d);
    void setAvg_speed(double avg_speed);
    void setLat(vector<double> lat);
    void setLon(vector<double> lon);
    void setLat_acc(vector<double> lat_acc);
    void setLon_acc(vector<double> lon_acc);
    void setSpeed(vector<double> speed);
    void setTime(vector<double> time);
    string toString();
};
#endif /* Vehicle_hpp */
