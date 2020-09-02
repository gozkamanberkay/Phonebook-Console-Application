# ----------------------------------------------------------------------------
# @command build Compiles the given files and creates the executable file,
#	   run Runs the executable file,
#	   iterate Clears the console screen and iterates build and run commands.
#
# ----------------------------------------------------------------------------
build: 
	gcc main.c contact.c node.c menu.c file.c controller.c -o main

# ----------------------------------------------------------------------------
run: 
	./main

# ----------------------------------------------------------------------------
iterate:
	clear && make build && make run

# ----------------------------------------------------------------------------
