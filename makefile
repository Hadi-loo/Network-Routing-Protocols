# Compiler
CXX = g++
CXXFLAGS = --std=c++17

# Directories
SRC_DIR = src
BIN_DIR = bin

# Executables
MAIN_EXE = main.out

# Objects


# Sensitivity lists

MainExecutableSensitivityList = \
	$(BIN_DIR)/main.o \
	$(BIN_DIR)/commandHandler.o \
	$(BIN_DIR)/network.o \
	$(BIN_DIR)/graph.o \

MainSensitivityList = \
	$(SRC_DIR)/main.cpp \
	$(SRC_DIR)/commandHandler.hpp \

CommandHandlerSensitivityList = \
	$(SRC_DIR)/commandHandler.cpp \
	$(SRC_DIR)/commandHandler.hpp \
	$(SRC_DIR)/network.hpp \
	$(SRC_DIR)/consts.hpp \

NetworkSensitivityList = \
	$(SRC_DIR)/network.cpp \
	$(SRC_DIR)/network.hpp \
	$(SRC_DIR)/graph.hpp \

GraphSensitivityList = \
	$(SRC_DIR)/graph.cpp \
	$(SRC_DIR)/graph.hpp \
	$(SRC_DIR)/consts.hpp \


# Compile
all: $(MAIN_EXE)

$(MAIN_EXE): $(MainExecutableSensitivityList)
	$(CXX) $(CXXFLAGS) $(MainExecutableSensitivityList) -o $(MAIN_EXE)


$(BIN_DIR)/main.o: $(MainSensitivityList)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cpp -o $(BIN_DIR)/main.o

$(BIN_DIR)/commandHandler.o: $(CommandHandlerSensitivityList)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/commandHandler.cpp -o $(BIN_DIR)/commandHandler.o

$(BIN_DIR)/network.o: $(NetworkSensitivityList)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/network.cpp -o $(BIN_DIR)/network.o

$(BIN_DIR)/graph.o: $(GraphSensitivityList)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/graph.cpp -o $(BIN_DIR)/graph.o

.PHONY: clean
clean:
	rm -f $(BIN_DIR)/*.o $(BIN_DIR)/*.out