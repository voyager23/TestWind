/*
 * EdgeClass.h
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

#ifndef EDGECLASS_H
#define EDGECLASS_H

#include <iostream>
#include <vector>
#include "PointClass.h"


using namespace std;

// Declaration file

class Edge {
	friend class DataSet;
	private:

	double m;
	double c;
	int used;

	vector<Edge>::iterator next;
	
	public:
	Edge(Point p, Point q);
	int is_co_linear(Edge e);
	void prt_edge();
	double phi;
	Point from;
	Point to;
	
};

bool edge_sort_funct(Edge i, Edge j);

#endif
