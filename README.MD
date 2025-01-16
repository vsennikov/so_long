# so_long

`so_long` is a simple 2D game developed as part of the 42 curriculum. The objective of the game is to navigate through a maze, collect items, and reach the exit.

## Features

- 2D graphics using the MiniLibX library
- Keyboard controls for movement
- Collectible items
- Exit to complete the level

## Installation

To run this program, you need to use MiniLibX, a simple X-Window (X11R6) programming API in C designed for students. You can find more information and download it from the following link: [MiniLibX](https://github.com/42Paris/minilibx-linux).

1. Clone the repository:
	```sh
	git clone https://github.com/vsennikov/so_long.git
	```
2. Navigate to the project directory:
	```sh
	cd so_long
	```
3. Compile the project:
	```sh
	make
	```

## Usage

Run the game with the following command:
```sh
./so_long maps/map.ber
```

## Controls

- `W` - Move up
- `A` - Move left
- `S` - Move down
- `D` - Move right
- `ESC` - Exit the game

## Maps

Maps should be in the `.ber` format. You can create your own maps or use the provided ones in the `maps` directory.
