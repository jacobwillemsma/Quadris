CXX = g++ -g
CXXFLAGS = -Wall -MMD -L/usr/X11R6/lib -lX11
EXEC = quadris
OBJECTS = quadris.o  score.o cell.o board.o textdisplay.o block.o coordinate.o interpreter.o iblock.o jblock.o tblock.o lblock.o zblock.o oblock.o sblock.o nextblock.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS} 

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
  
.PHONY: clean