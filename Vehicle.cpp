//
//  Vehicle.cpp
//  TravelTime-Prediction
//
//  Created by yunus emre avcı on 2.12.2023.
//

#include "Vehicle.hpp"


Vehicle::Vehicle(){}

int Vehicle::getTrack_ID(){
    return track_ID;
}

string Vehicle::getType() const{
    return vtype;
}

void Vehicle::setTrack_ID(int track_ID){
    track_ID = track_ID;
}

void Vehicle::setType(string vtype){
    vtype = vtype;
}

void Vehicle::setAvg_speed(double avg_speed){
    avg_speed = avg_speed;
}
void Vehicle::setTraveled_d(double traveled_d){
    traveled_d = traveled_d;
}

void Vehicle::setLat(vector<double> lat){
    lat = lat;
}

void Vehicle::setLon(vector<double> lon){
    lon = lon;
}

void Vehicle::setLat_acc(vector<double> lat_acc){
    lat_acc = lat_acc;
}

void Vehicle::setLon_acc(vector<double> lon_acc){
    lon_acc = lon_acc;
}
void Vehicle::setSpeed(vector<double> speed){
    speed = speed;
}
void Vehicle::setTime(vector<double> time){
    time = time;
}
vector<double> Vehicle::getLat() const{
    return lat;
}

vector<double> Vehicle::getLon() const{
    return lon;
}

vector<double> Vehicle::getLat_acc() const{
    return lat_acc;
}

vector<double> Vehicle::getLon_acc() const{
    return lon_acc;
}

vector<double> Vehicle::getSpeed() const{
    return speed;
}

vector<double> Vehicle::getTime() const{
    return time;
}

string Vehicle::toString(){
    stringstream vehicle_info;
    
    vehicle_info << getTrack_ID() << " " << getType() << " " << getTraveled_d();
    return vehicle_info.str();
}
