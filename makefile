all: main.exe


main.exe:
	 g++ *.cpp `wx-config --cxxflags --libs` -o MyApp

start:	main.exe run

run:
	 ./MyApp

clean:
	 rm MyApp