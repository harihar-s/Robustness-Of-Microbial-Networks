make:
	g++ main.cpp -std=c++17 -o exec

.PHONY: clean

clean:
	rm exec