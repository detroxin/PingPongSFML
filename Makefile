all:
	g++ -Isrc/include -Lsrc/lib -o main main.cpp -lsfml-graphics -lsfml-window -lsfml-system