
#define _USE_MATH_DEFINES
#include <math.h>
#include "calculate_gps_heading.h"

//   Copyright 2022 Kevin Godden
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

static inline double to_rad(double theta) {
    return (theta * M_PI) / 180.0;
}

static inline double to_degrees(double theta) {
    return (theta * 180.0) / M_PI;
}

//
// Calculate the heading in decimal degrees between 2 (preferably quite close) locations 
// (lat1, lon1) --> First location
// (lat2, lon2) --> Second location
//
double calculate_gps_heading(double lat1, double lon1, double lat2, double lon2) {
    // Convert degrees to radians
    lat1 = to_rad(lat1);
    lon1 = to_rad(lon1);
    lat2 = to_rad(lat2);
    lon2 = to_rad(lon2);    
        
    double dlon = lon2 - lon1;
    double X = cos(lat2) * sin(dlon);
    double Y = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(dlon);
    
    double heading = atan2(X,Y);
    
    // We want heading in degrees, not radians.
    heading = to_degrees(heading);
  
    // We want a uniform heading of >=0 and <360
    if (heading < 0)
        heading = 360.0 + heading;
    
    return heading;
}