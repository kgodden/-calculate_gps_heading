# calculate_gps_heading

Some example code to estimate 'heading' or 'course' given two locations retrieved from a moving GPS device.  The two points used should be realtivly close to one another but large enough to be meaningful with respect to the accuracy of your GPS device, so perhaps 100m --> 200m apart.

The code to calculate heading can be found in **calculate_gps_heading.cpp**:

```cpp
double calculate_gps_heading(double lat1, double lon1, double lat2, double lon2)
```

It takes 4 arguments, latitude and longitude for the 2 locations in decimal degrees.

It calculates heading and returns it as an angular offset from 'North' in degrees.

The calculate heading vaue will be between 0 and 360 degrees: **0 >= heading < 360**

There are some tests in a file called **test_calculate_gps_heading.cpp**

To build and run them first execute make and then run test_calculate_gps_heading, ypu shpuld see some output like this:

```
$ make ; ./test_calculate_gps_heading.exe
g++ -o test_calculate_gps_heading  calculate_gps_heading.cpp test_calculate_gps_heading.cpp -std=c++11
PASS: heading: 321.03, target: 321.03
PASS: heading: 141.03, target: 141.03
PASS: heading: 69.104, target: 69.11
PASS: heading: 249.11, target: 249.11
PASS: heading: 177.85, target: 177.85
PASS: heading: 223.75, target: 223.75
PASS: heading: 90.085, target: 90.083
```
