all: gntest calc

gntest: gntest.o GeneralNumber.o gnparse.o
	g++ -g gntest.o GeneralNumber.o gnparse.o -lreadline -lncurses -o gntest

gntest.o: gntest.cpp GeneralNumber.h
	g++ -g -c gntest.cpp

calc: calc.o GeneralNumber.o gnparse.o
		g++ -g calc.o GeneralNumber.o gnparse.o -lreadline -lncurses -o calc

calc.o: calc.cpp GeneralNumber.h
		g++ -g -c calc.cpp

GeneralNumber.o: GeneralNumber.cpp GeneralNumber.h
	g++ -g -c GeneralNumber.cpp

gnparse.o: gnparse.cpp GeneralNumber.h
	g++ -g -c gnparse.cpp

clean:
	rm -f *.o gntest
	rm -f *.o calc

docs:
	doxygen
	chmod a+r,a-x html/*
	cp -p html/* ~/public_html/cs2303assig5
