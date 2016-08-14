SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all:$(BIN)/prueba


# ************ Compilación de módulos ************

	
$(BIN)/prueba: $(OBJ)/prueba.o $(OBJ)/banco.o
	$(CXX) -o $(BIN)/prueba  $(OBJ)/prueba.o $(OBJ)/banco.o

$(OBJ)/prueba.o: $(SRC)/prueba.cpp $(INC)/banco.h 
	$(CXX) $(CPPFLAGS) $(SRC)/prueba.cpp -o $(OBJ)/prueba.o


$(OBJ)/banco.o: $(SRC)/banco.cpp $(INC)/banco.h 
	$(CXX) $(CPPFLAGS) $(SRC)/banco.cpp -o $(OBJ)/banco.o	
	

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*