
all: hello libHello.so

hello: main.cpp hello.h libHello.so
	gcc main.cpp -fPIC -L. -lHello -o hello

libHello.so: hello.h hello.cpp
	gcc -shared hello.cpp -fPIC -o libHello.so

clean:
	-rm hello libHello.so 2>/dev/null
