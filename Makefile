all:
	dune build main.exe
	dune build main.bc
	@echo "\nRunning main.exe"
	./_build/default/main.exe
	@echo "\nRunning main.bc + update LD_LIBARY_PATH"
	LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:_build/default ./_build/default/main.bc
	@echo "\nRunning main.bc"
	./_build/default/main.bc

.PHONY: all
