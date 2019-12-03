all: main.exe


main.exe:
	 g++ *.cpp `wx-config --cxxflags --libs` -o MyApp

run:
	 ./MyApp

clean:
	 rm MyApp