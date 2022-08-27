OBJECTS = SQ_EQ.o Solve.o printf.o unittest.o

.cpp.o:
	@ g++ -c -o $@ $<
out: $(OBJECTS)
	@ g++ -o out $(OBJECTS)
	@ rm -f *.o
	@ echo "Success"
.SUFFIXES: .cpp.o
