/*
 * DataSetClass.cxx
 * 
 * Copyright 2019 Michael Tate <mike@pop-os>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include "../include/DataSetClass.h"

// Implementation file

DataSet::DataSet(int x, int y, int n) {
	cout << "DataSet: parameters " << x << " " << y << " " << n << endl;

	// Construct a data set of N random points.
	// Constraints:
	// 		Bounded by X-Y limits
	//		No 3 points co-linear
	// Exposes a std::vector<Points>
	// Exposes a std::vector<Edge>
	
	// construct a trivial random generator engine from a time-based seed:
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator (seed);

	std::uniform_int_distribution<int> dist_x(1,x-1);
	std::uniform_int_distribution<int> dist_y(1,y-1);

	std::cout << "some random numbers between 1 and 511: ";
	for (int i=0; i<n; ++i) {
		std::cout << dist_x(generator) << ",";
		std::cout << dist_y(generator) << ": ";
	}
	std::cout << endl;
	
	points.clear();
	edges.clear();
	
	bool co_linear = false;
	do { // loop

		// generate a vector of N points
		// generate a vector of (N*N - N)/2 edges;
		// search edges for equal edges (same m and c)
		// 	if(found) 
		//		co_linear = true
		// end loop
		
		// create points
		for(auto x = 0; x < n; ++x) {
			Point p = Point(dist_x(generator), dist_y(generator));
			points.push_back(p);
		}
		
		// create edges
		for(vector<Point>::iterator from = points.begin(); from != points.end(); ++from) {
			for(vector<Point>::iterator to = points.begin(); to != points.end(); ++to) {
				if(to == from) continue;
				Edge e = Edge(*from, *to);	// Edge object will calculate m & c, setting used to false
				edges.push_back(e);
			}
		}
		
		// test edges and set co_linear
		for(vector<Edge>::iterator a = edges.begin(); a != edges.end() - 1; ++a) {
			for(vector<Edge>::iterator b = a + 1; b != edges.end(); ++b) {
				if( (*a).is_co_linear(*b) == 1 ) {
					co_linear = true;
					cout << "is_co_linear reports true\n";
					break;
				} else {
					co_linear = false;
				}
			}
		}
		 
		
	} while(co_linear == true);
	
	/* 
	 * Sort subsets of edges (equal from points) using rotation angle phi radians
	 */
	 
	prt_vector_points(points);	
	cout << "Dataset construction complete";
};

int DataSet::trajectory_search() {
	
	int size = 0;		// number of edges in trajectory
	double omega = 0.0; // current rotation angle (radians)
	Point start;
	vector<Edge>::iterator sentinel, working;
	

	
	for(auto start_iter = points.begin(); start_iter != points.end(); ++start_iter) {
		start = *start_iter;
		
		// clear all 'used' flags
		for(auto e = edges.begin(); e != edges.end(); ++e) e->used = 0;
		
		// clear trajectory vector
		trajectory.clear();
		
		// clear/set data values
		omega = 0.0;
		size = 0;
		
		// set the sentinel point
		// criteria: (start.cmp_point(from)==1) && phi > omega
		sentinel = edges.begin();
		do {
			
		} while(sentinel != edges.end());
		
		// loop start
		
		// loop end
		
		// print/output trajectory vector
	
	} // for start_iter...
	return 0;
}

void prt_vector_points(vector<Point> points) {
	for(auto p = points.begin(); p != points.end(); ++p) {
		(*p).prt_point();
	}
	cout << endl;	
}

void prt_vector_edges(vector<Edge> edges) {
	for(auto e = edges.begin(); e != edges.end(); ++e) {
		(*e).prt_edge();
		cout << endl;
	}
	cout << endl;
}

	
	



