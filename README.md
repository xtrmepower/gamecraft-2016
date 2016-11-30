#Game Jam 2016
----
## Gameplay Instructions
((To be added))

----
## Dependencies
* [SFML 2.4](https://github.com/SFML/SFML)

----
## Build instructions
You will need CMake 3.0.2 or later.

### Repository layout
* `src` for all source and header files written by us.
* `data` for stuff like images, sounds, and fonts.
* `thirdarty` for any other misc third party files we use.

### Windows
Clone the repository, create and `cd` into the build directory, `cmake .. -G "Visual Studio 14 2015 Win64"  && start gamecraft.sln`.

On Windows, it's a good idea to alias the long cmake command. This is because each time you want to add a source or header file, you should `touch` it in the `src` directory, then run the cmake command in the build directory to make Visual Studio detect the new files.

### Linux
Clone the repository, create and `cd` into the build directory, `cmake .. && make`.
