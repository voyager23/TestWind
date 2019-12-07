/*
 * EdgeClass.cxx
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


#include <iostream>
#include <cmath>
#include "../include/EdgeClass.h"

// Implementation file

Edge::Edge(Point p, Point q) {
	from = p;
	to   = q;
	double dy = from.gety() - to.gety();
	double dx = from.getx() - to.getx();
	m = dy / dx;
	c = from.gety() - (m * from.getx());
	phi = atan(m);
	used = false;	
}

int Edge::is_co_linear(Edge e) {
	if ((m == e.m)&&(c == e.c)) return 1;
	return 0;
}

void Edge::prt_edge() {
	from.prt_point(); to.prt_point();
	cout << m << "  " << c << "  " << phi << "  " << used << endl;
}

//----------------------------------------------------------------

bool edge_sort_funct(Edge i, Edge j) {
	// return true if i is considered to come before j.
	// 	else return false	
	return (i.phi < j.phi);
}



