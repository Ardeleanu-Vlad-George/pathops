# Purpose
Develope a program that accepts as CLA a directory path (real or not) and then prints out:
- 'path': the whole given path;
- 'file': the full name of the file to which the path points to;
- 'base': the path up to the 'file' part;
- 'name': the name of the file without the extension;
- 'extn': the extension of the file;
# Bonus
Storing some functions that process file paths that could be used in other programs.
# MadeWith
- GNU Make; version 4.2.1
- GCC; version 9.4.0
- C; standard ISO C99
# ExampleOfUsage
Running './pathops src/main.c' produces:
```
path: src/main.c
file: main.c
base: src
name: main
extn: c
```
Running './pathops Makefile' produces:
```
path: Makefile
file: Makefile
base: (null)
name: Makefile
extn: (null)
```
Running './pathops ../bitrev/README.md' produces:
```
path: ../bitrev/README.md
file: README.md
base: ../bitrev
name: README
extn: md
```
Running './pathops ...yes' produces:
```
path: ...yes
file: ...yes
base: (null)
name: ...yes
extn: (null)
```
Running './pathops ....' produces:
```
path: ...yes
file: ...yes
base: (null)
name: ...yes
extn: (null)
```
Running './pathops ..hide.txt' produces:
```
path: ..hide.txt
file: ..hide.txt
base: (null)
name: ..hide
extn: txt
```
Running './pathops ../ceva' produces:
```
path: ../ceva
file: ceva
base: ..
name: ceva
extn: (null)
```
Running './pathops ../.undeva/cumva' produces:
```
path: ../.undeva/cumva
file: cumva
base: ../.undeva
name: cumva
extn: (null)
```
Running './pathops ./.fix-aici..si_asa' produces:
```
path: ./.fix-aici..si_asa
file: .fix-aici..si_asa
base: .
name: .fix-aici
extn: .si_asa
```
# Stones
## HindStones
- Replace the biology based naming convention with the next one: the whole path is just called 'path' (same notation), the file full name is 
 called 'file' (same notation), the name wihout the the extension is 'name' (same), the file extension is 'extension' (noted 'extn'), the part
 up to 'file' is called 'base' (same notation);(did this only in the beginning section of this README)
## MileStones
- Clean the 'examples' section, make sure they are no duplicates, and all the exceptional cases are covered;
## Sky_Stones
- Code a similar program in Python using regex (this program would recatogarize the project from an 'example' to a 'subject')
