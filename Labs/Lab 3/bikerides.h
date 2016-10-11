// ==========================================================================
// $Id: bikerides.h,v 1.2 2016/10/08 01:54:18 jlang Exp $
// CSI2372 Lab Assignment 3 2016
// ==========================================================================
// (C)opyright:
//
//   Jochen Lang
//   EECS, University of Ottawa
//   800 King Edward Ave.
//   Ottawa, On., K1N 6N5
//   Canada.
//   http://www.eecs.uottawa.ca
//
// Creator: jlang (Jochen Lang)
// Email:   jlang@eecs.uottawa.ca
// ==========================================================================
// $Log: bikerides.h,v $
// Revision 1.2  2016/10/08 01:54:18  jlang
// Fixed VS 2013 Incompatibilities.
//
// Revision 1.1  2016/09/30 15:44:51  jlang
// Created lab3.
//
// ==========================================================================
#ifndef _BikeRides_h_
#define _BikeRides_h_


#include <iostream>
#include <string>

#include <vector>
#include <array>

using std::cout;
using std::endl;
using std::string;


/**
* Route to a destination with one-way distance
*/
struct Route {
    string d_destination;
    float d_distance;
};

/**
* Ride by a rider on a route in a certian time (hours as float)
*/
struct Ride {
    string d_rider;
    Route d_route;
    float d_time;
};


class BikeRides {
protected:
    std::array<Route, 3> d_trainingRoutes{ { Route{ "Trim Road", 25.0f }, Route{ "Gatineau Park", 30.0f }, Route{ "Pinhey Point", 45.0f } } };
    std::vector<Ride> d_rides;
public:
    // returns the ride which took the longest time
    // if no Ride is stored, a nullpointer is returned
    Ride* getLongestRide();
    // returns true and the nth ride stored in d_rides
    // if no nth Ride exist false is returned and result is unchanged
    bool getNRide( int nth, Ride& result );
    // Add a new Ride to the vector of d_rides
    // but only if the ride is in the array of training routes
    void addRide( const Ride& r );
    // Print all the d_rides in order they have been stored
    void print();
    // Removes all rides of a given route and
// returns the number of removed rides
    int removeRides( const Route& r);
};
#endif