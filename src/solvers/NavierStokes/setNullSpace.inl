/***************************************************************************//**
* The null space for the Poisson system in a flow with no immersed boundary
* is the constant vector of size equal to the number of pressure variables. 
* Such a null space can be specified and automatically handled by PETSc by 
* passing PETSC_TRUE as the second parameter in the function MatNullSpaceCreate.
*/
template <PetscInt dim>
PetscErrorCode NavierStokesSolver<dim>::setNullSpace()
{
	PetscErrorCode ierr;
	MatNullSpace   nsp;

	ierr = MatNullSpaceCreate(PETSC_COMM_WORLD, PETSC_TRUE, 0, NULL, &nsp); CHKERRQ(ierr);
	ierr = KSPSetNullSpace(ksp2, nsp);
	ierr = MatNullSpaceDestroy(&nsp);

	return 0;
}