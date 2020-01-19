CC=gcc
CFLAGS=-std=gnu99 -g -O2 -Wall -Wextra -pedantic $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)

EX_22_SRC = ex22_alvi.c
EX_22_OBJS = $(EX_22_SRC:.c=.o)

.DEFAULT_GOAL := all

.PHONY: all
all: clean ex22_main_alvi ## Clean and compile
	@echo "+ $@"

ex22_main_alvi: $(EX_22_OBJS) ex22_main_alvi.c
	$(CC) $(CFLAGS) $^ -o $@

$(EX_22_OBJS): $(EX_22_SRC)
	$(CC) -c $(CFLAGS) $^

.PHONY: release
release: clean  ## Generate release version
	@echo "+ $@"
	@tar -cvzf ala273_project.tar.gz .

.PHONY: clean
clean: clean-build clean-debug ## Remove all file artifacts

.PHONY: clean-build
clean-build: ## Remove all build artifacts
	@echo "+ $@"
	@rm -rf *.o *.a *.exe
	@rm -rf *.tar.gz
	@rm -rf ex22_main_alvi

.PHONY: clean-debug
clean-debug: ## Remove all debug artifacts
	@echo "+ $@"
	@rm -f output.txt
	@rm -f .gdb_history
	@rm -rf vgcore*
	
.PHONY: help
help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-22s\033[0m %s\n", $$1, $$2}'
	@echo "Contact author for more help: ala273@mail.usask.ca"