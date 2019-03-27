# dune-debug-test
Minimal project to test dune debug + c code linking

Please run:
```
make
```

To see the different scenarios. Expected output is:
```
$ make
dune build main.exe
dune build main.bc

Running main.exe
./_build/default/main.exe
abcdef+

Running main.bc + update LD_LIBARY_PATH
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:_build/default ./_build/default/main.bc
abcdef+

Running main.bc
./_build/default/main.bc
Fatal error: cannot load shared library dllutils_core_stubs
Reason: dlopen(dllutils_core_stubs.so, 10): image not found
make: *** [all] Error 2
```

# Solution
Adding `ocamlc_flags (:standard -custom)` solves the issue !
