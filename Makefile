compilerFlags := -Wall -Werror
includeFlags := -Iheaders -I/usr/local/include -I/usr/include
linkerFlags := -L/usr/local/lib -lraylib -lm -lpthread -ldl -lrt -lX11

objFilenames := $(wildcard obj/*.o)

.PHONY: obj

main: obj
	g++ -o main main.cpp $(objFilenames) $(compilerFlags) $(includeFlags) $(linkerFlags) -ggdb

obj:
	for source_file in gameObjects/*.cpp; do \
		a=$$(basename "$$source_file" .cpp); \
		g++ -c -o obj/$$a.o "$$source_file" $(includeFlags) $(compilerFlags) -ggdb; \
	done