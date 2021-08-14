all:
	g++ main.cpp -o password
run:
	make all
	./password
clean:
	rm -rf password *.o
test:
	echo Do some tests
