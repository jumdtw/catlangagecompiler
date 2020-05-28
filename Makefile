CC = g++
SRCS_DIR = ./source
SRCS = comcat.cpp tokenize.cpp file_controller.cpp

BUILD_DIR = Build

TARGET = ./bin/comcat
OBJS = $(addprefix $(BUILD_DIR)/,$(patsubst %.cpp,%.o,$(SRCS)))
FLAG = -Wall


all: $(BUILD_DIR)  $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(FLAG) -o $@ $(OBJS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(CC) $(SRCS_DIR)/$*.cpp -c -o $(BUILD_DIR)/$*.o

clean:
	del $(OBJS)