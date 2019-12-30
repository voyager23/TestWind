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
#include <algorithm>
#define N 6
#include "../include/PointClass.h"
#include "../include/EdgeClass.h"
#include "../include/DataSetClass.h"
#include "../include/AnimationClass.h"

using namespace std;

int main(int argc, char **argv)
{
	vector<Edge>::iterator first,last;
	DataSet dataset = DataSet(512,512,N);	
		
	cout << endl << "========== Not Sorted ==========" << endl;
	prt_vector_edges(dataset.edges);
	
#if(1)

	sort( dataset.edges.begin(), dataset.edges.end(), edge_sort_funct);
	
#else
	
	// Sort the edges vector by sub-section based on equal 'from' points
	first = dataset.edges.begin();
	last = first;
	while(1) {
		// advance the last pointer
		while ((last != dataset.edges.end())&&((*first).from.cmp_point((*last).from) == 1)) 
			last += 1;
		sort(first, last, edge_sort_funct);
		if(last == dataset.edges.end()) break;
		first = last;
	} // while(1)
	
#endif

	cout << endl << "========== Sorted ==========" << endl;
	prt_vector_edges(dataset.edges);
	
	cout << "Starting trajectory search." << endl;
	vector<Trajectory*> bar;
	dataset.trajectory_search(bar);
	cout << "Search complete." << endl;
	
	// Graphics function: 
	// Takes a Trajectory pointer as parameter and returns a gtk-animation
	
	Animation *simple_animation = new Animation();
	GdkPixbufSimpleAnim *anim = (*simple_animation).create_simple_animation(bar[0]);
	
	// gtk-window to display the animation. Close window to move to next trajectory
	
	return 0;
}
