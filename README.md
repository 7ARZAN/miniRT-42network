# miniRT - Raytracing Engine

**miniRT** is a raytracing project developed as part of the 42 school curriculum. Written in C and powered by the MLX42 library, it renders 3D scenes from `.rt` configuration files, supporting geometric primitives (spheres, planes, cylinders), ambient and diffuse lighting, and a robust scene parser. The project is optimized for performance, adheres to 42 Norminette coding standards, and includes a custom garbage collector for efficient memory management. This project demonstrates proficiency in computer graphics, low-level programming, and algorithm design.

## Features
- **Scene Parsing**: Parses `.rt` files to configure cameras, lights, and objects (spheres, planes, cylinders).
- **Raytracing**: Implements accurate ray-object intersection algorithms for rendering 3D scenes.
- **Lighting**: Supports ambient and diffuse lighting with customizable intensity and RGB colors.
- **Rendering**: Displays scenes at 800x600 resolution using MLX42, with optimized single-pass rendering.
- **Memory Management**: Features a lightweight garbage collector to prevent memory leaks.
- **Performance**: Optimized with normalized vectors, efficient math operations, and compiler flags (`-O3`, `-ffast-math`).

## Requirements
- **Compiler**: GCC or Clang
- **Libraries**: MLX42, GLFW, libm (math library)
- **Operating Systems**: macOS or Linux
- **Dependencies**: `make`, CMake (for MLX42), Homebrew (for macOS GLFW installation)

## Installation

### 1. Clone the Repository
```bash
git clone https://github.com/7ARZAN/miniRT-42network.git
cd miniRT-42network
```

### 2. Install Dependencies
#### macOS
- **Install Homebrew** (if not already installed):
  ```bash
  /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
  ```
- **Install GLFW**:
  ```bash
  brew install glfw
  ```
- **Install MLX42**:
  ```bash
  git clone https://github.com/codam-coding-college/MLX42.git lib/MLX42
  cd lib/MLX42
  cmake -B build
  cmake --build build -j4
  cd ../..
  mkdir -p include/MLX42
  cp -r lib/MLX42/include/MLX42/* include/MLX42/
  ```

#### Linux
- Install GLFW and dependencies:
  ```bash
  sudo apt-get update
  sudo apt-get install libglfw3-dev libx11-dev libxext-dev
  ```
- Install MLX42 (same steps as macOS, starting from `git clone https://github.com/codam-coding-college/MLX42.git`).

### 3. Build the Project
```bash
make
```

## Usage
Run the program with a `.rt` scene file:
```bash
./miniRT scene.rt
```

### Scene File Format
The `.rt` file defines the scene with the following elements:
- **A (Ambient)**: `A <ratio> <R,G,B>` (e.g., `A 0.2 255,255,255`)
- **C (Camera)**: `C <x,y,z> <dir_x,dir_y,dir_z> <fov>` (e.g., `C 0,0,10 0,0,-1 60`)
- **L (Light)**: `L <x,y,z> <ratio> <R,G,B>` (e.g., `L 0,5,5 0.8 255,255,255`)
- **sp (Sphere)**: `sp <x,y,z> <diameter> <R,G,B>` (e.g., `sp 0,0,0 2 255,0,0`)
- **pl (Plane)**: `pl <x,y,z> <dir_x,dir_y,dir_z> <R,G,B>` (e.g., `pl 0,-1,0 0,1,0 0,255,0`)
- **cy (Cylinder)**: `cy <x,y,z> <dir_x,dir_y,dir_z> <diameter> <height> <R,G,B>` (e.g., `cy 2,0,0 0,1,0 1 2 0,0,255`)

**Example `scene.rt`**:
```
A 0.2 255,255,255
C 0,0,10 0,0,-1 60
L 0,5,5 0.8 255,255,255
sp 0,0,0 2 255,0,0
pl 0,-1,0 0,1,0 0,255,0
cy 2,0,0 0,1,0 1 2 0,0,255
```

## Directory Structure
```
miniRT-42network/
├── Makefile
├── include/
│   ├── minirt.h
│   └── structs.h
├── lib/
│   ├── allocation.c
│   ├── gb_collector.c
│   ├── gnl.c
│   ├── ohmysplit.c
│   └── utils.c
├── main.c
├── parsing/
│   ├── basic_check.c
│   ├── parser.c
│   ├── ps_elmnts.c
│   └── ps_objects.c
├── raytracing/
│   ├── raytracing.c
│   └── raytracing_utils.c
├── render/
│   └── render.c
└── vectors/
    ├── vctr.c
    └── vec.c
```

### Key Files
- **minirt.h**: Defines function prototypes and project constants.
- **structs.h**: Specifies data structures for scenes, objects, vectors, and more.
- **main.c**: Entry point, initializing the scene and rendering pipeline.
- **parser.c, ps_elmnts.c, ps_objects.c**: Handle parsing of `.rt` files for scene configuration.
- **raytracing.c, raytracing_utils.c**: Implement ray-object intersections and lighting calculations.
- **render.c**: Manages rendering with MLX42.
- **allocation.c, gb_collector.c**: Provide memory management with a custom garbage collector.
- **utils.c, gnl.c, ohmysplit.c**: Utility functions for string manipulation and file parsing.

## Technical Highlights
- **Raytracing Algorithms**: Implements precise intersection calculations for spheres, planes, and cylinders, using normalized vectors for efficiency.
- **Lighting Model**: Combines ambient and diffuse lighting with customizable ratios, ensuring realistic scene illumination.
- **Memory Efficiency**: Custom garbage collector minimizes memory leaks, crucial for handling complex scenes.
- **Performance Optimization**: Leverages `-O3` and `-ffast-math` compiler flags, single-pass rendering, and vector normalization to reduce computation overhead.
- **Code Quality**: Adheres to 42 Norminette standards, ensuring clean, maintainable code.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a feature branch: `git checkout -b feature/your-feature`.
3. Commit changes: `git commit -m "Add your feature"`.
4. Push to the branch: `git push origin feature/your-feature`.
5. Open a pull request.

Please ensure code complies with 42 Norminette and includes tests for new features.

## Limitations
- No support for shadows, specular lighting, or anti-aliasing (potential extensions).
- Fixed 800x600 resolution (configurable in `minirt.h`).
- Simplified utility functions (`gnl.c`, `ohmysplit.c`) may need replacement with 42’s official versions for stricter environments.

## License
This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.

## Acknowledgments
- **42 School**: For inspiring this project as part of the curriculum.
- **MLX42 Developers**: For providing a robust rendering library.
- **Contributors**: Thanks to all testers and peers for feedback.

For issues, suggestions, or questions, please open an issue on [GitHub](https://github.com/7ARZAN/miniRT-42network) or contact [elakhfif@proton.me].
