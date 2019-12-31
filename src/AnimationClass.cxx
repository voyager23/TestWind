/*
 * AnimationClass.cxx
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

#include "../include/AnimationClass.h"

// Implementation file

#if(1)
Animation::Animation() {
	
	animation = gdk_pixbuf_simple_anim_new(xDim,yDim,1.0);
	cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_RGB24, xDim, yDim);
	cairo_t *cr = cairo_create(surface);
	
	// cleanup code
	//free(surface);
	//free(cr);
};
#endif

GdkPixbufSimpleAnim * Animation::create_simple_animation(Trajectory *t) {
	
	animation = gdk_pixbuf_simple_anim_new(xDim,yDim,1.0);
	cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_RGB24, xDim, yDim);
	cairo_t *cr = cairo_create(surface);
	
	// clear surface to black
	cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);	// black
	cairo_rectangle(cr, 0.0, 0.0, xDim, yDim);
	cairo_fill(cr);
	
	// drawing parameters
	cairo_set_source_rgb(cr, 0.0, 0.72, 0.92);	// cyan
	cairo_set_line_width(cr, 2.5);

	// Draw edges on surface
	// Trajectory is a vector of iterators to type Edge
	for(auto e = (*t).begin(); e != (*t).end(); e++) { 
		Edge edge = **e;
		edge.prt_edge();
		cout << endl;
		cairo_move_to(cr, edge.from.getx(), edge.from.gety());
		cairo_line_to(cr, edge.to.getx(), edge.to.gety());
		//		create pixbuf from surface
		GdkPixbuf *buf = gdk_pixbuf_get_from_surface(surface, 0.0, 0.0, xDim, yDim);
		//		add pixbuf to animation
		gdk_pixbuf_simple_anim_add_frame (animation,buf);
		//	next edge
	};
	
	// set animation to loop indefinitely	
	gdk_pixbuf_simple_anim_set_loop (animation, true);
		
	return animation;
	
};

