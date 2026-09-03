# Resize-Image
It resizes every image in a given folder to a specific size in the command line

# Building the program
Make sure you have OpenCV library Install or else it wouldn't build!

After you have the program install:
1. go to the file directory in your command prompt `cd ~yourProgram`
2. Run the CMake command `cmake -S code -B build`
3. `cd build & make`

# How to use this program
1. Insert every images you need into a folder (make sure it contains only images)
2. run the program `./resize width height absolutePathToImgFolder absolutePathToDestFolder`
   more information about the command line below
/*
 * Purpose:      Resize every image in the given folder to a given size
 * 1st argument: width
 * 2nd argument: height
 * 3rd argument: absolute path to source folder (optional)
 * 4th argument: absolute path to destination  folder (optional)
 * Return:       in the given PATH or DEFAULT_DESTINATION
 */
