# Progetto di Laboratorio di Algoritmi

Progetto in C++ realizzato per il corso di Laboratorio di Algoritmi, tenuto nell'anno accademico _2023/2024_ dalla Prof.ssa [Manuela Flores](https://www.unipa.it/persone/docenti/f/manuela.flores/?pagina=curriculum) presso l'**UniversitÃ degli Studi di Palermo**.

_**A cura di [@zAlweNy26](https://github.com/zAlweNy26) e [@FedeDC512](https://github.com/FedeDC512).**_

> Visiona la Traccia della prova pratica [qui](Traccia.pdf).
>
> Visiona la Relazione Tecnica [qui](Relazione.md).

## Requisiti di progetto

- Windows: [Installa MinGW](https://code.visualstudio.com/docs/cpp/config-mingw)
- Linux: [Installa GCC](https://code.visualstudio.com/docs/cpp/config-linux)
- MacOS [Installa Clang](https://code.visualstudio.com/docs/cpp/config-clang-mac)

## Procedura di Avvio

Per Windows:

```bash
cd src
g++ -o main.exe main.cpp utils/utils.h utils/utils.cpp graph/graph.h graph/graph.cpp dfs/dfs.h dfs/dfs.cpp
.\main # o main.exe
```

Per Linux / MacOS:

```bash
cd src
g++ -o main main.cpp ./**/*.cpp ./**/*.h
./main
```
