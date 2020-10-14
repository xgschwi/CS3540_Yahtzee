help : ## help: Displays a menu of commands accesed by make <command>
	@echo "	make: Calls help menu since help is the first command defined"
	@echo "	help: Displays a menu of commands accesed by make <command>"
	@echo "	init: Creates bin directory"
	@echo "	all: Compiles all cpp files into main.exe in bin directory"
	@echo "	run: Runs compiled program main.exe in bin directory"
	@echo "	clear: Removes bin directory and main.exe"
	@echo "	do_all: Initializes directory, compiles code, and cleans up after running the code"

init: ## init: Creates bin directory
	mkdir bin

all: ## all: Compiles all cpp files into main.exe in bin directory
	make init
	g++ -o bin/main.exe yahtzee.cpp HighScores.cpp yahtzeeDriver.cpp

run: ## run: Runs compiled program main.exe in bin directory
	./bin/main.exe

clear: ## clear: Removes bin directory and main.exe
	rm -r bin

do_all: ## do_all: Initializes directory, compiles code, and cleans up after running the code
	make all
	make run
	make clear
