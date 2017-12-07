all: work.c
	gcc -o work work.c

run: all 
	./work -c 8
	./work -v
	./work -c 4
	./work -v
	./work -r
	./work -v
	./work fdasfjald
clean:
	rm *~ work 
