all: file

file: main.o ForwardList.o Node.o String.o MyFunctions.o
	g++ main.o ForwardList.o Node.o String.o MyFunctions.o -o file

main.o: main.cpp String.h MyFunctions.h ForwardList.h 
	g++ -c main.cpp

ForwardList.o: ForwardList.cpp String.h
	g++ -c ForwardList.cpp

Node.o: Node.cpp
	g++ -c Node.cpp

String.o: String.cpp 
	g++ -c String.cpp 

MyFunctions.o: MyFunctions.cpp MyFunctions.h String.h ForwardList.h
	g++ -c MyFunctions.cpp