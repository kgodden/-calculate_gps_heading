all: 
	g++ -o test_calculate_gps_heading  calculate_gps_heading.cpp test_calculate_gps_heading.cpp -std=c++11
	
.PHONY: clean
clean:
	-rm -f test_calculate_gps_heading *.gch 2> /dev/null