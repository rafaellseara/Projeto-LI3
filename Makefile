CC = gcc
CFLAGS = -O2 -Wall `pkg-config --cflags --libs glib-2.0`
LDFLAGS = -lcurses
#===================================================#
BIN_DIR = bin
BLD_DIR = build
INC_DIR = include
SRC_DIR = src
#===================================================#
SRC = $(wildcard $(SRC_DIR)/**/*c) main.c
SRC_TEST = $(wildcard $(SRC_DIR)/**/*c) main_test.c
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BLD_DIR)/%.o,$(SRC))
OBJS_TEST = $(patsubst $(SRC_DIR)/%.c,$(BLD_DIR)/%.o,$(SRC_TEST))

#===================================================#
PROGRAM = programa-principal
TEST_PROGRAM = programa-testes
#===================================================#

.DEFAULT_GOAL = build

build: setup $(PROGRAM) $(TEST_PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) -I $(INC_DIR) -o $@ $^ $(CFLAGS) $(LDFLAGS)

$(BLD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c -I $(INC_DIR) -o $@ $^ $(CFLAGS)

.PHONY: setup
setup:
	@mkdir -p $(BLD_DIR)

.PHONY: clean
clean:
	@-rm -r $(BLD_DIR)
	@-rm $(PROGRAM) $(TEST_PROGRAM)

.PHONY: test
test: $(TEST_PROGRAM)
	
$(TEST_PROGRAM): $(OBJS_TEST)
	$(CC) -I $(INC_DIR) -o $@ $^ $(CFLAGS) $(LDFLAGS)

