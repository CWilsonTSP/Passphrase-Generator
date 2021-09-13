all:
	g++ -Wall -O3 main.cpp -o password
run:
	make all
	./password
clean:
	rm -rf password *.o
test:
	./password -m 10 -M 20
