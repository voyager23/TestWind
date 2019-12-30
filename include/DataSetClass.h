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

#ifndef _DATASETCLASS_H
#define _DATASETCLASS_H

#include <iostream>
#include <vector>
#include <chrono>
#include <random>

#include "PointClass.h"
#include "EdgeClass.h"

// Declaration file

using namespace std;

typedef vector<vector<Edge>::iterator> Trajectory;

class DataSet {
	public:
	vector<Point> points;
	vector<Edge> edges;
	vector< vector<Edge>::iterator > trajectory;
	DataSet(int x, int y, int n);
	void trajectory_search(vector<Trajectory*>&);
	
	
	private:
	int n; // number of points
	
};

void prt_vector_points(vector<Point>);
void prt_vector_edges(vector<Edge>);
	

	
#endif
