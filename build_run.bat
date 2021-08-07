cls
g++ ^
-std=c++17 ^
-I ./include/ ^
-L ./lib/SDL2/ ^
src/Application.cpp ^
src/Color.cpp ^
src/Curve.cpp ^
src/Ellipse.cpp ^
src/GeometricObject.cpp ^
src/main.cpp ^
src/Point.cpp ^
src/SdlGraphics.cpp ^
src/SdlPainter.cpp ^
src/Size.cpp ^
-o bin\Curves.exe ^
-lmingw32 ^
-lSDL2main ^
-lSDL2
cls
bin\Curves.exe
pause