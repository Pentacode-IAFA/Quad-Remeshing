# Quad-Remeshing
Implementing Reliable Feature-Line Driven Quad-Remeshing: https://dl.acm.org/doi/pdf/10.1145/3450626.3459941


# Build

## Prétraitement

### Instalation de gurobi

Suivre la procédure d'installation de Gurobi:
https://www.gurobi.com/documentation/quickstart.html

### Chemins absolus

Une fois le dossier gurobi951 récupéré, il y a des chemins absolus à remplacer:

* Dans le fichier `libs/quadwild/libs/libs.pri`: Il faut remplacer le chemin de gurobi (la ligne commançant par GUROBI_PATH). Le nouveau chemin est `/path/to/gurobi951/linux64`

* Dans le fichier `libs/quadwild/libs/quadretopology/quadretopology/include/qr_ilp.h`: Il faut remplacer le chemin de l'include de gurobi (ligne 32 normalement) par `#include "path/to/gurobi/linux64/include/gurobi_c++.h"`

```
mkdir build
cd build
cmake -DRadium_DIR=/path/to/dir ..
make install
```

# Usage

Une fois le plugin installé, il faut, dans l'application, charger le plugin et ajouter le widget du plugin à l'application. Il faut également préciser le chemin pour 2 variables dans le code source (`Library/QuadRemeshing.cpp - QuadRemesher::step1()`):
* `m_meshFilePath`: le chemin vers le fichier .obj qui doit être traiter.
* `m_setupPath`: `/path/to/Quad-Remeshing/libs/quadwild/quadwild/basic_setup.txt`.

Les boutons génèrerons les fichiers de configuration du mesh dans le même dossier indiqué par `m_meshFilePath` (il faut utiliser les boutons dans l'ordre).

Remarque: Les seuls boutons qui marchent pour l'instant sont:
* Remesh and field creation
* Tracing
* Display patches (il faut avoir charché et sélectionné le fichier nomFichier_P0.obj avec l'application et il faut que son mode de dessin soit per vertex)
