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

build-all:
	@echo "🔨 Compilando seletores de nível..."
	@$(MAKE) -C novato build-all || true
	@$(MAKE) -C aventureiro build-all || true
	@$(MAKE) -C mestre build-all || true
	@echo "✅ Tudo compilado!"

clean-all: clean
	@$(MAKE) -C novato clean-all || true
	@$(MAKE) -C aventureiro clean-all || true
	@$(MAKE) -C mestre clean-all || true

.PHONY: run clean build-all clean-all
