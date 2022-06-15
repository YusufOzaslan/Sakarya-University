all:compile link execute
compile:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Iterator.cpp -o ./lib/Iterator.o
	g++ -c -I "./include" ./src/Node.cpp -o ./lib/Node.o
	g++ -c -I "./include" ./src/DoublylinkedList.cpp -o ./lib/DoublylinkedList.o
link:
	g++ ./lib/DoublylinkedList.o ./lib/Node.o ./lib/Iterator.o ./lib/main.o -o ./bin/program
execute:
	./bin/program