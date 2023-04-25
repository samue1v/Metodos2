# Define the link target.
linkTarget = main

# Define any flags.
CFLAGS = -std=c++17 -Ofast

# Define the object files that we need to use.
objects = 	main.o \
			newton_cotes_open.o \
			newton_cotes_closed.o \
			gaussLegendre.o
					
# Define the rebuildables.
rebuildables = $(objects) $(linkTarget)

# Rule to actually perform the build.
$(linkTarget): $(objects)
	g++ -g -o $(linkTarget) $(objects) $(CFLAGS)
	
# Rule to create the .o (object) files.
%.o: %.cpp
	g++ -o $@ -c $< $(CFLAGS)
	
.PHONEY:
clean:
	rm $(rebuildables)