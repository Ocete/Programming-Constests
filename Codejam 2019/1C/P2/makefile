
# Macros
all: execute

execute:
	g++ a.cpp -o a
	./a < entrada.txt

test:
	g++ a.cpp -o a
	./a < entrada.txt  > test.txt
	g++ test.cpp -o test
	./test < test.txt

clean:
	rm a
