base:
	@g++ main.cpp *.o -Wall
clean:
	@rm -rf ./a.out
	@./setup.py questions.txt questions.cpp
	@echo Files cleaned the questions.cpp has been wiped and updated from questions.txt
run:
	@echo Runing your code
	@g++ main.cpp questions.cpp *.o
	@./a.out
