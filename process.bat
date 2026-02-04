mkdir build
cd build 
cmake .. 
cmake --build .
cd Debug
video_extractor ..\..\Images\Bilder.mp4 test
cd ..
cd ..

