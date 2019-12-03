# Makefile for TestWind


OBJECTS = PointClass.o EdgeClass.o DataSetClass.o
HEADERS = PointClass.h EdgeClass.h DataSetClass.h

# Derived pathnames
OBJS = $(addprefix ../build/, $(OBJECTS) )
HDRS = $(addprefix ../include/, $(HEADERS))
OUT = -o ../build/$@

all : tw1.cxx $(OBJS)
	g++ tw1.cxx $(OBJS) -o ../bin/tw1

../build/PointClass.o : PointClass.cxx $(HDRS)
	g++ -c PointClass.cxx $(OUT)
	
../build/EdgeClass.o : EdgeClass.cxx $(HDRS)
	g++ -c EdgeClass.cxx $(OUT)
	
../build/DataSetClass.o : DataSetClass.cxx $(HDRS)
	g++ -c DataSetClass.cxx $(OUT)
