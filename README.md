*This project has been created as part of the 42 curriculum by aoneil, abisiani.*

# cub3D
#### A RayCaster with miniLibX

<br>

## Description

cub3D is a ray-casting project written in C using MiniLibX. It renders a
first-person 3D view from a `.cub` scene file.


## Instructions
Build the project:

```sh
make
```

Run it with a .cub scene file (detailed below):

```sh
./cub3D maps/valid/subject_map.cub
```

Clean build files:

```sh
make clean
make fclean
make re
```


## Scene file format (.cub)

A `.cub` file describes a level. It has two parts: first six **configuration elements**, then a **map**, which must come last.

The map must be composed of only 6 possible characters:
- 0 for an empty space
- 1 for a wall
- N,S,E or W for the player’s start position and spawning orientation

For example:
```
NO textures/wolfenstein/grey_stone_1.xpm
SO textures/wolfenstein/grey_stone_2.xpm
WE textures/wolfenstein/grey_stone_3.xpm
EA textures/wolfenstein/grey_stone_4.xpm

F 220,100,0
C 225,30,0

        1111111111111
        1000000000001
111111111011000001111
100000000011000001
11110111111111N01
11111111 11111111
```

### Elements

| Identifier | Meaning | Value |
|------------|---------|-------|
| `NO` | North wall texture | Path to a texture file |
| `SO` | South wall texture | Path to a texture file |
| `WE` | West wall texture | Path to a texture file |
| `EA` | East wall texture | Path to a texture file |
| `F` | Floor colour | `R,G,B` |
| `C` | Ceiling colour | `R,G,B` |

- Each identifier appears exactly once.
- They can come in any order, with optional blank lines between.
- Each line contains in order: its identifier, a space or a tab, the value (see the table).
- A texture config specifies one path and the file must exist and load as an image.
- A colour is three whole numbers from 0 to 255, separated by commas, e.g. `220,100,0`.

### Map

| Character | Meaning |
|-----------|---------|
| `1` | Wall |
| `0` | Empty floor |
| `N` `E` `S` `W` | Player start, facing north, east, south or west |
| space | Outside the map |

- The map is the last thing in the file.
- There is exactly one player start.
- There are no blank lines inside the map.
- Rows can have different lengths, and the map can be any shape, but:
- The map must be closed by walls: no empty floor (`0`) or player cell may touch a space or the edge of the map.


## Resources
- [Markdown guide](https://www.markdownguide.org/cheat-sheet/)
- [minilibx docs](https://harm-smits.github.io/42docs/libs/minilibx)
- [minilibx intro guide](https://gontjarow.github.io/MiniLibX/)
- [Lode's Computer Graphics Tutorial: Raycasting](https://lodev.org/cgtutor/raycasting.html)
- [Example maps and textures for testing](https://github.com/mcombeau/cub3D/tree/main/maps)


### AI usage
AI was used for:
- Writing stub README
- Collating MiniLibX documentation
- Tracking progress for project management
