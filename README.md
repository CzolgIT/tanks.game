# tanks.game

## Prerequirements

### Linux
Those packages have to be installed
```
libsdl2-dev
libsdl2-net-dev
libsdl2-image-2.0-0
libsdl2-image-dev
```
### Windows
make sure that your mingw64 libraries are installed in
```
C:\tools\mingw64
```
### Mac OS
Make sure you have correctly installed all frameworks:
```
/Library/Frameworks/SDL2
/Library/Frameworks/SDL2_image
/Library/Frameworks/SDL2_net
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
You can use: **Clone or download -> Open in Xcode** and build with default settings
