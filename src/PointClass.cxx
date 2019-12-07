/*
 * PointClass.cxx
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

// Implementation file

#include <iostream>
#include "../include/PointClass.h"

using namespace std;

Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(int a, int b) {
	x = a;
	y = b;
}

int Point::getx() { return x; }
int Point::gety() { return y; }

void Point::sety(int b) { y = b; }
void Point::setx(int a) { x = a; }

int Point::cmp_point(Point p) {
	if((this->x == p.x)&&(this->y == p.y)) return 1;
	return 0;
}

