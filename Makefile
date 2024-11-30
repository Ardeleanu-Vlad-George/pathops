TARGET := pathops
OBJECT := obj/main.o obj/path.o

$(TARGET): $(OBJECT)
	gcc -o $@ $^

$(OBJECT): obj/%.o : src/%.c
	gcc -std=c99 -I inc/ -c -o $@ $^

clean:
	rm $(TARGET) $(OBJECT)
