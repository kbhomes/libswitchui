# libswitchui

Create user interfaces that look like the Nintendo Switch official software. Based on libnx and SDL2.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Building from source

#### Prerequisites

Ensure that [devKitPro and libnx are properly installed][libnx-setup]. Use devKitPro's `pacman` (or `dkp-pacman`) to install the following dependencies:

- devkitA64
- libnx
- switch-sdl2
- switch-sdl2_gfx
- switch-sdl2_image
- switch-sdl2_ttf
- switch-zlib

#### Installing

Ensure that `$DEVKITPRO` is appropriately set in the environment. 

- Run `make`
- Run `make dist`
- Copy `dist/include` and `dist/lib` to some location and add appropriate compiler and linker flags
    - For example: `-Ipath/to/include -Lpath/to/lib -lswitchui -lsdl2 -lsdl2_gfx -lsdl2_ttf -lsdl2_image -ljpeg -lpng -lfreetype -lbz2 -lz -lm -lnx`
    
### Examples

After building the library using `make` and `make dist`, you can go to the `examples` directory and run `make` there to build example applications. The examples are works-in-progress. 

- `settings`: this example partially emulates the Nintendo Switch system settings applet

## Authors

* **Sajid Anwar** - [kbhomes](https://github.com/kbhomes)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

[libnx-setup]: http://switchbrew.org/index.php?title=Setting_up_Development_Environment
