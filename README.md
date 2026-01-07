
# Terminal Chicken Farm Simulation

## Project Description

This project is an experimental, terminal-based simulation application developed in C++. It utilizes the `ncurses` library to render a graphical interface within the command line. The application simulates a basic chicken farm environment where entities (chickens) possess state-based behaviors, primarily focusing on locating and consuming food sources.

The software is currently in the development phase. It implements the Model-View-Controller (MVC) architectural pattern to ensure a separation of concerns between the simulation logic, the user interface, and user input handling.

## Features

* **MVC Architecture:** Clean separation of data (Models), rendering (View), and logic (Controller).
* **State Machine Logic:** Chickens operate on a defined state machine (`STANDING`, `WALKING`, `TOFOOD`) to determine behavior.
* **Pathfinding:** Implementation of Euclidean distance logic for entities to identify and move toward the nearest food source.
* **Interactive Controls:** Support for keyboard and mouse inputs to interact with the simulation dynamically.
* **Dynamic Rendering:** Real-time updates of entity positions and window resizing capabilities.

## Prerequisites

To build and run this project, the following dependencies are required:

* **C++ Compiler:** A compiler supporting standard C++ (e.g., `g++`).
* **Make:** GNU Make build automation tool.
* **Ncurses Library:** The `libncurses` development library must be installed on the system.
* *Debian/Ubuntu:* `sudo apt-get install libncurses5-dev libncursesw5-dev`
* *macOS:* `brew install ncurses`



## Installation

The project includes a `Makefile` to streamline the compilation process.

1. **Clone the repository** (if applicable) or navigate to the project root directory.
2. **Compile the source code** using the following command:
```bash
make

```


Or explicitly:
```bash
make all

```


3. **Clean build artifacts** (Optional):
To remove object files and the executable, use:
```bash
make clean

```



## Usage

Once compiled, the application can be executed directly from the terminal.

### Running the Application

Execute the binary created by the makefile:

```bash
./chickens

```

Alternatively, you can build and run in a single step:

```bash
make run

```

### Controls

The simulation is controlled via the following inputs:

* **`a` Key:** Adds a new chicken entity to the screen at a default starting position.
* **Left Mouse Click:** Places a food unit (`:::`) at the cursor's location.
* **`q` Key:** Terminates the application and closes the window.

## Project Structure

The codebase is organized into specific directories reflecting the MVC pattern:

```text
.
Makefile             # Build configuration
├── src
│   ├── main.cpp         # Entry point and initialization
│   ├── controller
│   │   ├── controller.cpp
│   │   └── controller.hpp
│   ├── models
│   │   ├── models.cpp
│   │   └── models.hpp
│   └── view
│       ├── view.cpp
│       └── view.hpp

```

## Technical Details

### Models

The logic layer defines the `Chicken` and `Food` structures. The `Chicken` entity maintains a reference to the food vector to calculate the distance to the nearest target. Movement is updated per frame based on the calculated trajectory toward the target coordinates.

### View

The view layer manages the `ncurses` window (`stdscr` and `mainWindow`). It iterates through the vectors of entities provided by the controller and renders their ASCII representations ("C" for chickens, ":::" for food) at the correct coordinates.

### Controller

The controller acts as the central loop. It processes user input (keyboard and mouse events), triggers the update of model states (position and behavior), and instructs the view to re-render the scene.

## License

This project is licensed under the MIT License.

---
