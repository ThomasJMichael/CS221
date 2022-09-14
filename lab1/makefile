OBJS	= main.o company.o employee.o
SOURCE	= main.cpp company.cpp employee.cpp
HEADER	= company.h employee.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

company.o: company.cpp
	$(CC) $(FLAGS) company.cpp 

employee.o: employee.cpp
	$(CC) $(FLAGS) employee.cpp 


clean:
	rm -f $(OBJS) $(OUT)