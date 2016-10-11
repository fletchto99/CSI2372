#include "bikerides.h"

using namespace std;

int main() {
    std::array<Route, 3> routes = { { Route{ "Trim Road", 25.0f }, Route{ "Gatineau Park", 30.0f }, Route{ "Pinhey Point", 45.0f } } };
    BikeRides* br = new BikeRides();
    br->addRide(Ride{"Sophia", routes[1], 4.5});
    br->addRide(Ride{"Sophia", routes[2], 4.1});
    br->addRide(Ride{"Emma", routes[0], 2.5});
    br->addRide(Ride{"Liam", routes[1], 3.5});
    br->addRide(Ride{"Oliver", routes[1], 5.1});
    br->addRide(Ride{"Maya", routes[2], 3.2});
    br->print();
    Ride longest = *(br->getLongestRide());
    cout << "-------------------------" << endl;
    cout << longest.d_rider << " : Ride to " << longest.d_route.d_destination << " of " << longest.d_route.d_distance << "km in " << longest.d_time << "hrs." << endl;
    cout << "-------------------------" << endl;
    Ride nth;
    if (br->getNRide(3, nth)) {
        cout << nth.d_rider << " : Ride to " << nth.d_route.d_destination << " of " << nth.d_route.d_distance << "km in " << nth.d_time << "hrs." << endl;
        cout << "-------------------------" << endl;
    }
    br->removeRides(routes[1]);
    br->print();
    return 0;
}
