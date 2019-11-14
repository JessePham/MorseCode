all: main.exe


main.exe:
	 g++ MyApp.cpp Frame.cpp TextPanel.cpp `wx-config --cxxflags --libs` -o MyApp

run:
	 ./MyApp

clean:
	 rm MyApp