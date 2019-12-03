/*
 * tw1.cxx
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
#include "../include/PointClass.h"
#include "../include/EdgeClass.h"
#include "../include/DataSetClass.h"

using namespace std;

int main(int argc, char **argv)
{
	Point from = Point(); 
	Point to   = Point(123,345);
	to.prt_point(); cout << endl;
	DataSet dataset = DataSet(512,512,5);
	return 0;
}

