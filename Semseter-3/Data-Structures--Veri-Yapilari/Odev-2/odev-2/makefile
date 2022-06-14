all:compile link execute
compile:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Nokta.cpp -o ./lib/Nokta.o
	g++ -c -I "./include" ./src/NodeNokta.cpp -o ./lib/NodeNokta.o
	g++ -c -I "./include" ./src/NodeAVL.cpp -o ./lib/NodeAVL.o
	g++ -c -I "./include" ./src/DogruKuyrugu.cpp -o ./lib/DogruKuyrugu.o
	g++ -c -I "./include" ./src/AVL.cpp -o ./lib/AVL.o
link:
	g++ ./lib/Nokta.o ./lib/NodeAVL.o ./lib/AVL.o ./lib/DogruKuyrugu.o ./lib/NodeNokta.o ./lib/main.o -o ./bin/program
execute:
	./bin/program