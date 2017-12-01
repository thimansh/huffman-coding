CXX = g++
CXXFLAGS = -g -std=c++11
RM = rm

all: decoder encoder

clean: 
	$(RM) *.o encoder decoder

encoder: encoder.o pairing.o binary.o fourway.o
	$(CXX) $(CXXFLAGS) -o encoder encoder.o pairing.o binary.o fourway.o


encoder.o: encoder.cpp pairing.h binary.h fourway.h
	$(CXX) $(CXXFLAGS) -c encoder.cpp


pairing.o: pairing.h	

binary.o: binary.h

fourway.o: fourway.h

decoder: decoderhuff.o decoder.o encoder.o
	$(CXX) $(CXXFLAGS) -o decoder decoderhuff.o decoder.o 

decoderhuff.o: decoderhuff.cpp decoder.h 
	$(CXX) $(CXXFLAGS) -c decoderhuff.cpp

decoder.o: decoder.h
