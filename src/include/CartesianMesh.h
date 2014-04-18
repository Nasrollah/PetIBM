#if !defined(CARTESIAN_MESH_H)
#define CARTESIAN_MESH_H

#include <string>
#include <vector>

#include <petscsys.h>

template <PetscInt dim>
class CartesianMesh
{
public:
	PetscInt               nx, ny, nz;
	std::vector<PetscReal> x, y, z;
	std::vector<PetscReal> dx, dy, dz;
    
	CartesianMesh(std::string fileName);
};

#endif