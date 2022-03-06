# Hangman by NCN
=========================

_The project is a part of the 'LTNC' series_
**_Student: DO TUAN NGHIA_**

## How to run

- Run directly Hangman.exe in build/Hangman

```bash
    $ cd build
    $ ./Hangman
```

- Recompile by running CMake

```bash
    $ cmake .
    $ make
```

- You also can run by CMake Tool for a better experience
- Compiling by **g++**

```bash
    $ g++ -std=c++11 main.cpp modules/play.cpp modules/high_score.cpp modules/new_word.cpp modules/manage_user.cpp lib/console.cpp lib/verify.cpp lib/data.cpp lib/user.cpp lib/utils.cpp lib/config.cpp -o main
    $ ./main
```

## Feature
- Multi-player
- Manage player
- Have hint to guess and example after each play-turn.
- Beautiful graphic interface

