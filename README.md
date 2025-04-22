miniRT
miniRT is a raytracing project developed as part of the 42 school curriculum. It renders 3D scenes described in .rt files, supporting spheres, planes, cylinders, ambient lighting, and diffuse lighting. Built in C with the MLX42 library, the project adheres to 42 Norminette standards, is optimized for performance, and features a lightweight garbage collector for memory management.
Features

Scene Parsing: Reads .rt files to configure cameras, lights, and objects (spheres, planes, cylinders).
Raytracing: Implements ray-object intersections for accurate rendering.
Lighting: Supports ambient and diffuse lighting with customizable ratios and colors.
Rendering: Displays scenes at 800x600 resolution using MLX42.
Memory Management: Uses a garbage collector to prevent leaks.
Performance: Optimized with normalized vectors, single-pass rendering, and compiler flags (-O3, -ffast-math).

Requirements

Compiler: gcc or clang
Libraries: MLX42, GLFW (for Linux/macOS)
OS: Linux or macOS
Dependencies: make, libm (math library)

Installation

Clone the Repository:
git clone https://github.com/7ARZAN/miniRT-42network.git
cd miniRT-42network


Install MLX42 and GLFW:

macOS:
Place libmlx42.a and libglfw3.a in /Users/$USER/Library/lib/.
Place MLX42 headers in /Users/$USER/Library/includes/.


Linux:sudo apt-get install libglfw3-dev libx11-dev libxext-dev

Download MLX42 and link it as needed.


Build the Project:
make



Usage
Run the program with a .rt scene file:
./miniRT scene.rt

Scene File Format
The .rt file specifies the scene with the following elements:

A (Ambient): A <ratio> <R,G,B> (e.g., A 0.2 255,255,255)
C (Camera): C <x,y,z> <dir_x,dir_y,dir_z> <fov> (e.g., C 0,0,10 0,0,-1 60)
L (Light): L <x,y,z> <ratio> <R,G,B> (e.g., L 0,5,5 0.8 255,255,255)
sp (Sphere): sp <x,y,z> <diameter> <R,G,B> (e.g., sp 0,0,0 2 255,0,0)
pl (Plane): pl <x,y,z> <dir_x,dir_y,dir_z> <R,G,B> (e.g., pl 0,-1,0 0,1,0 0,255,0)
cy (Cylinder): cy <x,y,z> <dir_x,dir_y,dir_z> <diameter> <height> <R,G,B> (e.g., cy 2,0,0 0,1,0 1 2 0,0,255)

Example scene.rt:
A 0.2 255,255,255
C 0,0,10 0,0,-1 60
L 0,5,5 0.8 255,255,255
sp 0,0,0 2 255,0,0
pl 0,-1,0 0,1,0 0,255,0
cy 2,0,0 0,1,0 1 2 0,0,255

Directory Structure
.
├── Makefile
├── include
│   ├── minirt.h
│   └── structs.h
├── lib
│   ├── allocation.c
│   ├── gb_collector.c
│   ├── gnl.c
│   ├── ohmysplit.c
│   └── utils.c
├── main.c
├── parsing
│   ├── basic_check.c
│   ├── parser.c
│   ├── ps_elmnts.c
│   └── ps_objects.c
├── raytracing
│   ├── raytracing.c
│   └── raytracing_utils.c
├── render
│   └── render.c
└── vectors
    ├── vctr.c
    └── vec.c

Key Files

minirt.h: Main header with function prototypes and constants.
structs.h: Defines data structures (scene, objects, vectors, etc.).
main.c: Program entry point, initializes scene and rendering.
parser.c, ps_elmnts.c, ps_objects.c: Parse .rt files.
raytracing.c, raytracing_utils.c: Implement ray-object intersections and lighting.
render.c: Handles MLX42 rendering.
allocation.c, gb_collector.c: Manage memory with garbage collector.
utils.c, gnl.c, ohmysplit.c: Utility functions for strings and parsing.

Contributing
Contributions are welcome! To contribute:

Fork the repository.
Create a feature branch (git checkout -b feature/your-feature).
Commit changes (git commit -m "Add your feature").
Push to the branch (git push origin feature/your-feature).
Open a pull request.

Please ensure code follows 42 Norminette and includes tests for new features.
Limitations

No support for shadows, specular lighting, or anti-aliasing (can be added).
Fixed 800x600 resolution (configurable in minirt.h).
Simplified gnl.c and ohmysplit.c (replace with 42 versions if needed).

License
This project is licensed under the MIT License. See LICENSE for details.
Acknowledgments

42 School for the project inspiration.
MLX42 developers for the rendering library.
Contributors and testers.

For issues or suggestions, open an issue on GitHub or contact [your email].

