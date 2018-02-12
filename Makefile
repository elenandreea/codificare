build: encoder.c
	gcc encoder.c -o encoder -lm
run: encoder
	./encoder 

clean: 
	rm -rf encoder
