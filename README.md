# Finite Element Method (FEM) Heat Transfer Simulation

### Numerical simulation of transient heat transfer in 2D using the Finite Element Method (FEM), including real world engineering analysis of heat propagation in different brick structures.

## Project Overview

This project implements a 2D transient heat simulation using the finite Element Method (FEM), with a focus on realistic physical modeling. Key aspects include:
- **Realistic physical simulation**: models heat transfer in heterogeneous materials (e.g., bricks with air cavities)  
- **Time-dependent FEM implementation**: solves transient heat conduction using configurable time steps and material properties  
- **Numerical methods from scratch**: includes Gauss quadrature integration
- **Engineering applicability**: supports boundary conditions, material variation, and outputs suitable for visualization in ParaView  

<br>

The solver computes temperature distribution over time by solving the following system:

$$
\left([H] + \frac{[C]}{\Delta \tau}\right) \cdot \{t_1\} - \frac{[C]}{\Delta \tau} \cdot \{t_0\} + \{P\} = 0
$$

Where the individual expressions are calculated as follows:

$$
[H] = \int_V k \left(
\frac{\partial N}{\partial x} \frac{\partial N^T}{\partial x}
+
\frac{\partial N}{\partial y} \frac{\partial N^T}{\partial y}
\right) dV
+
\int_S \alpha N N^T \, dS
$$

$$
\{P\} = - \int_S \alpha \{N\}t_\infty\, dS
$$

$$
[C] = \int_V c \rho \{N\} \{N\}^T \, dV
$$

The equations used in this project involve the following symbols:
- **[H]** – global stiffness matrix, representing the conductive properties of the elements  
- **[C]** – global capacity matrix, representing the heat storage in the elements  
- **$\{t_0\}$, $\{t_1\}$** – vectors of nodal temperatures at the current ($t_0$) and next ($t_1$) time steps
- **{P}** – global load vector, representing heat fluxes or sources applied to the system  
- **Δτ** – time step of the transient simulation  
- **k** – thermal conductivity of the material  
- **c** – specific heat capacity of the material  
- **ρ** – density of the material  
- **N** – matrix of shape functions for the FEM elements  
- **$\frac{\partial N}{\partial x}, \frac{\partial N}{\partial y}$** – derivatives of shape functions with respect to spatial coordinates  
- **α** – convection coefficient at the boundary  
- **$t_∞$** – ambient temperature outside the domain  
- **V** – volume of the domain (for volume integrals)  
- **S** – surface area of the boundary (for surface integrals)  

<br>

The implementation includes:
- Custom FEM grid handling (nodes & elements)
- Numerical integration using Gauss quadrature
- Assembly of global matrices (H, C, P)
- Time-dependent simulation
- Configurable simulation parameters:
  - time step
  - total simulation time
  - conductivity
  - density
  - specific heat
- Boundary conditions (convection)
- Export for visualization (ParaView)

## Core Structure

- `main.cpp` – simulation loop and time stepping
- `Grid.h` – core FEM logic (matrix assembly, calculations)
- `Structs.h` – data structures (nodes, elements, system)
- `GaussP.h` – Gauss-Legendre integration points
- `GaussQuad.h` – numerical integration utilities
- `FileGenerator.h` – output generation for visualization

## Example Results

### Key observations:
- Mesh density significantly affects accuracy
- Time step must be carefully chosen to avoid non-physical results
- Different mesh geometries lead to different heat distributions

<br>

Below is a visualization of the mesh structure (nodes and elements) used in the simulations. The corresponding temperature distributions are presented at selected time steps:
- 50 seconds for the first two meshes
- 20 seconds for the third mesh

#### Test1_4_4:
<div align="center">
    <img src="./readme_img/Test1_4_4_grid.png" width="25%">
    <img src="./readme_img/Test1_4_4_vis.png" width="25%">
</div>

#### Test2_4_4_MixGrid:
<div align="center">
    <img src="./readme_img/Test2_4_4_grid.png" width="25%">
    <img src="./readme_img/Test2_4_4_vis.png" width="25%">
</div>

#### Test3_31_31_Square:
<div align="center">
    <img src="./readme_img/Test3_31_31_grid.png" width="25%">
    <img src="./readme_img/Test3_31_31_vis.png" width="25%">
</div>

<br>

To analyze heat propagation, the simulation results were visualized using ParaView.

## Engineering Case Study: Heat Transfer in Bricks

The project includes a real-world simulation of heat transfer in different brick structures:

- Solid brick
- Brick with small air cavities
- Brick with large air cavities

### Key findings:
- Air cavities improve insulation between surfaces
- Solid bricks heat up more slowly on the heated side
- Differences between cavity layouts are relatively small (within numerical error range)

This demonstrates how FEM can be used in **material engineering and construction analysis**.

Below are representative snapshots of temperature distribution over time for different brick configurations.

#### Small cavities (time 60, 1000, 2000 seconds):
<div align="center">
    <img src="./readme_img/small_cavities_1.png" width="25%">
    <img src="./readme_img/small_cavities_2.png" width="25%">
    <img src="./readme_img/small_cavities_3.png" width="25%">
</div>
<div align="center">
    <img src="./readme_img/small_cavities_chart.png" width="50%">
</div>

#### Large cavities (time 60, 1000, 2000 seconds):
<div align="center">
    <img src="./readme_img/large_cavities_1.png" width="25%">
    <img src="./readme_img/large_cavities_2.png" width="25%">
    <img src="./readme_img/large_cavities_3.png" width="25%">
</div>

<div align="center">
    <img src="./readme_img/large_cavities_chart.png" width="50%">
</div>

#### Solid (time 60, 1000, 2000 seconds):
<div align="center">
    <img src="./readme_img/solid_1.png" width="25%">
    <img src="./readme_img/solid_2.png" width="25%">
    <img src="./readme_img/solid_3.png" width="25%">
</div>

<div align="center">
    <img src="./readme_img/solid_chart.png" width="50%">
</div>

## Additional Resources

More information can be found in the report (Polish version):
[Report(PDF)](./MES%20-%20Sprawozdanie%20-%20Marcin%20Janiczek.pdf)

For a more detailed view of heat propagation, full simulation animations are available:
[Watch visualization videos](./Videos/)