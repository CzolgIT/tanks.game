# tanks.game

## Prerequirements

Those packages have to be installed (Linux)
```
libsdl2-dev
libsdl2-net-dev
```

On windows make sure that your mingw64 libraries are installed in
```
C:\tools\mingw64
```

## Building

### Linux
Simply enter the project folder and type
```
make SYSTEM=linux
```

### Windows
CLI
```
make
```

### Mac OS
Simply clone this project to xcode.
Make sure you have correctly  installed frameworks:

 - SDL2
 - SDL2_image
 - SDL2_net
