# cub3D

cub3D is a project inspired by the world-famous Wolfenstein 3D game, the first FPS ever. This project enables you to explore ray-casting to create a dynamic view inside a maze, aiming to replicate the first-person perspective.

---

## Features
- **First-Person Perspective**: Provides a realistic 3D graphical representation of a maze from a first-person viewpoint.
- **Ray-Casting**: Utilizes ray-casting principles to render 3D scenes.
- **MiniLibX Integration**: Uses the MiniLibX library for graphical rendering.
- **Wall Textures**: Displays different textures for walls based on their orientation (North, South, East, West).
- **Floor and Ceiling Colors**: Allows setting different colors for the floor and ceiling.
- **Movement Controls**:
  - Arrow keys for looking left and right.
  - W, A, S, and D keys for moving through the maze.
  - ESC key to close the window and quit the program.
  - Red cross on the window frame to close the window and quit the program.
- **Scene Description File**: Takes a scene description file with the `.cub` extension as input, defining the map and textures.

### Map Specifications
- **Characters**:
  - `0` for empty space
  - `1` for wall
  - `N`, `S`, `E`, `W` for player’s start position and orientation
- **Closed Map**: The map must be closed/surrounded by walls.
- **Element Identifiers**:
  - `NO` for North texture
  - `SO` for South texture
  - `WE` for West texture
  - `EA` for East texture
  - `F` for floor color (R,G,B)
  - `C` for ceiling color (R,G,B)

---

## Bonus Features
- **Wall Collisions**: Implement wall collisions to prevent walking through walls.
- **Minimap System**: Display a minimap for better navigation.
- **Doors**: Include doors that can open and close.
- **Animated Sprites**: Add animated sprites within the game.
- **Mouse Rotation**: Allow the point of view to be rotated with the mouse.

---


## Compilation

To compile cub3D, use the provided Makefile. The Makefile includes the following rules:
- `all`: Compile the source files.
- `clean`: Remove object files.
- `fclean`: Remove all generated files.
- `re`: Recompile the project.
- `bonus`: Compile bonus features (if applicable).

---

## Programming Languages:
<p align="left">
  <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="C" width="40" height="40"/>
</p>

---

## Authors

- [hasabir](https://github.com/hasabir)
- [kadjane](https://github.com/Adjane-khaoula)

---

## Acknowledgments

- Inspired by [Wolfenstein 3D](http://users.atw.hu/wolf3d/)
- [42 School](https://42.fr/)

---
