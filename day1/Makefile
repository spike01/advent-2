cat: cat.c
	gcc cat.c -o cat -pedantic -Wall -Werror -Wimplicit -Wunused -Wcomment -Wchar-subscripts -Wuninitialized \
                 -Wshadow  -Wcast-align -Wwrite-strings -fPIC -Wno-missing-braces\

run: ./cat
	./cat cat.c Makefile

clean:
	rm -f ./cat
