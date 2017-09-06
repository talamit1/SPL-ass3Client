CFLAGS:=-c -Wall -Weffc++ -g
LDFLAGS:=-lboost_system -lboost_locale -lboost_thread -lboost_system

all: client
	g++ -o bin/client bin/connectionHandler.o bin/Client.o $(LDFLAGS) 

client: bin/connectionHandler.o bin/Client.o
	
bin/connectionHandler.o: src/connectionHandler.cpp
	g++ $(CFLAGS) -o bin/connectionHandler.o src/connectionHandler.cpp

bin/Client.o: src/Client.cpp
	g++ $(CFLAGS) -o bin/Client.o src/Client.cpp
	
	
.PHONY: clean
clean:
	rm -f bin/*
