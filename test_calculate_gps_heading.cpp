
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

#include "calculate_gps_heading.h"

struct test_point {
    double lat1;
    double lon1;
    double lat2;
    double lon2;
    double heading;
};

static bool almost_equal(double val, double target) {
    return fabs(target - val) < 0.01;
}

int main() {

    std::vector<test_point> test_points{

        { 52.981935612371615, -6.0326861216896495, 52.98331462882221, -6.034538892416848, 321.0316 },
        { 52.98331462882221, -6.034538892416848, 52.981935612371615, -6.0326861216896495, 141.0316 },
        { 52.98279445287178, -6.039364152945033, 52.983451492393165, -6.036505383661567, 69.11 },
        { 52.983451492393165, -6.036505383661567, 52.98279445287178, -6.039364152945033, 249.11 },
        { 52.98289,-6.03937, 52.982794, -6.039364, 177.85 },
        { -64.4177000, -56.9970700, -64.42482, -57.01286, 223.748 },
        {-64.4177000,-56.9970700, -64.41772, -56.9578, 90.083},
    };
    
    for (const auto& point: test_points) {
        double heading = calculate_gps_heading(point.lat1, point.lon1, point.lat2, point.lon2);
        
        std::cout << "heading is: (degrees)" << std::setprecision(5) << heading << std::endl;
        
        if (almost_equal(heading, point.heading)) {
            std::cout << "PASS" << std::endl;
        } else {
            std::cout << "FAIL" << std::endl;
        }
    }
    
    return 0;
}
