# Makefile for TestWind

CFLAGS = -g `pkg-config --cflags gtk+-3.0 gdk-3.0 cairo`
LIBS = `pkg-config --libs gtk+-3.0 gdk-3.0 cairo`

OBJECTS = PointClass.o EdgeClass.o DataSetClass.o AnimationClass.o
HEADERS = PointClass.h EdgeClass.h DataSetClass.h AnimationClass.h

# Derived pathnames
OBJS = $(addprefix ../build/, $(OBJECTS) )
HDRS = $(addprefix ../include/, $(HEADERS))
OUT = -o ../build/$@

all : tw1.cxx $(OBJS)
	g++ $(CFLAGS) tw1.cxx $(OBJS) $(LIBS) -o ../bin/tw1

../build/PointClass.o : PointClass.cxx $(HDRS)
	g++ -c $(cFLAGS) PointClass.cxx  $(LIBS) $(OUT)
	
../build/EdgeClass.o : EdgeClass.cxx $(HDRS)
	g++ -c $(CFLAGS) EdgeClass.cxx  $(LIBS) $(OUT)
	
../build/DataSetClass.o : DataSetClass.cxx $(HDRS)
	g++ -c $(CFLAGS) DataSetClass.cxx  $(LIBS) $(OUT)
	
../build/AnimationClass.o : AnimationClass.cxx $(HDRS)
	g++ -c $(CFLAGS) AnimationClass.cxx  $(LIBS) $(OUT)
