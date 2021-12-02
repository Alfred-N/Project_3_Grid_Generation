# Project 3 - Grid Generation
Project 3 for SF2565 Program Construction in C++ for Scientific Computing
### Description
This project consists of a C++ implementation for the generation of structured boundary-fitted grids that can be used for solving PDEs in any two-dimensional coordinate representation 
![equation](https://latex.codecogs.com/gif.latex?%5Cleft%20%5B%5Cxi%2C%20%5Ceta%20%5Cright%20%5D%20%5Csimeq%20I%20%5Ctimes%20I)
 that is isomorphic to the unit square. The implementation works for any boundary curves so long as they inherit from the abstract class `Curvebase` and implement the purely virtual functions `xp()`, `dyp()`, `dxp()` and `dyp()`

![borderless_50](https://user-images.githubusercontent.com/47230525/144439127-8b132923-2325-426d-849a-1780b43cedab.png)

### Usage
The main() function is located in the `main.cpp` file. Examples of boundary curves are given in `ExpCurve.cpp`, `TestCurve.cpp`, `HorizontalLine.cpp` and `VerticalLine.cpp`.
