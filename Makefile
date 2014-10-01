#FILES

EXEC := mpi_pi.exe
SRC := $(wildcard *.c)
OBJ :=$(patsubst %.c, %.o, $(SRC))

#OPTIONS

CC := mpicc
#CFLAGS := 
#LDFLAGS := -L/lib
#LDLIBS := -lm

#RULES

$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^
#%.o:%.c
#	$(CC) $(CFLAGS) -c $<
#hw_2prog.o hw2_routines.o: hw2_routines.h


#integrate: hw2_prog.o hw2_routines.o
#	icc -o integrate hw2_prog.o hw2_routines.o
#hw2_prog.o: hw2_prog.c hw2_routines.h
#	icc -c hw2_prog.c
#hw2_routines.o: hw2_routines.c hw2_routines.h
#	icc -c hw2_routines.c

#USEFUL PHONY TARGETS

.PHONY: clobber clean neat echo

clobber: clean
	$(RM) $(EXEC)
clean: neat
	$(RM) $(OBJ)
neat:
	$(RM) *~ .*~
echo:
	@echo $(OBJ)

run:
	./$(EXEC)
