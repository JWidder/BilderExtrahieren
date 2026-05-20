cmake -S . -B build -DOpenCV_DIR="C:/opencv/build/x64/vc16/lib"
cmake --build build --config Debug
cd build
ctest -C Debug -V
cd ..
