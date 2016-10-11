#include "bikerides.h"

using namespace std;

Ride* BikeRides::getLongestRide() {
    return &max_element(d_rides.begin(), d_rides.end(),[](const Ride& r1, const Ride& r2){
        return r1.d_time < r2.d_time;
    })[0];
}

bool BikeRides::getNRide(int nth, Ride &result) {
    if(nth < d_rides.size()) {
        result = d_rides[nth];
        return true;
    }
    return false;
}

void BikeRides::addRide(const Ride &r) {
    if (find_if(d_trainingRoutes.begin(), d_trainingRoutes.end(),  [&r](const Route &route) {
        return r.d_route.d_distance == route.d_distance && r.d_route.d_destination == route.d_destination;
    }) != d_trainingRoutes.end()) {
        d_rides.push_back(r);
    }
}

void BikeRides::print() {
    for_each(d_rides.begin(), d_rides.end(), [](const Ride &ride) {
        cout << ride.d_rider << " : Ride to " << ride.d_route.d_destination << " of " << ride.d_route.d_distance << "km in " << ride.d_time << "hrs." << endl;
    });
}

int BikeRides::removeRides(const Route &r) {
    unsigned long size_start = d_rides.size();
    d_rides.erase(remove_if(d_rides.begin(), d_rides.end(), [&r](Ride& ride) {
        return r.d_distance == ride.d_route.d_distance && r.d_destination == ride.d_route.d_destination;
    }), d_rides.end());
    return static_cast<int>(size_start - d_rides.size());
}