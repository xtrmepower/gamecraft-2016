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

----
## Development
###State Machine
The View class is the base class for the state machine that runs the game. The following functions should be overloaded:

* `view_loop()` controls the final returning state of the current state. You may want to call the base function `standardStateLoop()` and return a `ViewMode` enum that indicates the next state that the program should go to when `view_loop` exits.
* `draw()` performs the step that renders all components of the current scene onto the RenderWindow. Inside `draw()`, call `window->clear()`, then `window->draw()` to put a `Renderable` object into the scene, and then `window->display()` to flush the scene buffer.
* `processX()` describes what to do with each user interface event. For example, if the up arrow is pressed, you may want to edit `processKeypress()` translate the vertical position of the player avatar  upwards, etc.
* Note that at least one reachable event must set the `exit_loop` flag to `true` in order for the state to be broken out of. Otherwise, the program will be stuck in that state.
* Not all `processX()` functions need to be overridden, just the ones you need. The ones that are not overridden will simply do nothing.
* `update()` applies the changes accumulated between framerates. The frames refresh at 60 FPS, but the program can poll for events at a much faster rate. `update()` must be implemented for anything that continuously changes in the background.