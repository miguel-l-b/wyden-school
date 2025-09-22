CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = seletor
SOURCE = main.c

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe

build-all: $(TARGET)
	@echo "🔨 Compilando todos os projetos..."
	@if [ -d "detective-quest" ]; then cd detective-quest && make; fi
	@if [ -d "inventory" ]; then cd inventory && make; fi
	@if [ -d "war-game" ]; then cd war-game && make; fi
	@if [ -d "tetris-stack" ]; then cd tetris-stack && make; fi
	@echo "✅ Todos os projetos compilados!"

clean-all: clean
	@if [ -d "detective-quest" ]; then cd detective-quest && make clean; fi
	@if [ -d "inventory" ]; then cd inventory && make clean; fi
	@if [ -d "war-game" ]; then cd war-game && make clean; fi
	@if [ -d "tetris-stack" ]; then cd tetris-stack && make clean; fi

.PHONY: run clean build-all clean-all