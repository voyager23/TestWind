/*
 * AnimationClass.h
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
 
 // Declaration File

#ifndef ANIMATIONCLASS_H
#define ANIMATIONCLASS_H

#include <iostream>
#include <vector>

#include <cairo.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>

#include "EdgeClass.h"
#include "DataSetClass.h"

class Animation {
	
	private:
		cairo_surface_t *surface;
		cairo_t *cr;
		Trajectory *t;
		GdkPixbuf *b;
		GdkPixbufSimpleAnim *animation;
		const double xDim = 512.0;
		const double yDim = 512.0;
	
	public:
		Animation();
		GdkPixbufSimpleAnim *create_simple_animation(Trajectory*);
	
};

#endif
