CXX = g++
CXXFLAGS = -Wall -std=c++0x -O3
#tu mozna i nalezy dopisac wersje z optymalizacjami
LIBFLAGS = -lSDL -lGL -lGLU -lSDL_ttf
CFLAGS =
CFLAGS = -I$(IDIR) $(LIBFLAGS) -static
OBJDIR = Obj/
OBJDIR-OPT = Obj-opt/
LIB = libTirian2.a
IDIR = Include/
COMMON_DEPS = $(IDIR)types.hpp
OBJ = $(patsubst %.cpp, $(OBJDIR)%.o, $(wildcard *.cpp))

.PHONY: all clean

all: $(LIB)

clean:
	rm -f $(OBJDIR)*.o

Docs: *.cpp Include/*.hpp Dox/*.dox Doxyfile
	doxygen

$(LIB): $(OBJ)
	rm $(LIB)
	ar rc $(LIB) $(OBJ)
	ranlib $(LIB)
	
$(OBJDIR)%.o: %.cpp $(IDIR)%.hpp $(COMMON_DEPS)
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(C-STANDARD-FLAGS) $(CFLAGS)
