template <>
PetscErrorCode NavierStokesSolver<2>::writeFluxes()
{
	PetscErrorCode  ierr;
	Vec             qxGlobal, qyGlobal;
	std::string     savePointDir, fileName;
	PetscViewer     viewer;
	
	// create output folder
	std::stringstream ss;
	ss << caseFolder << "/" << std::setfill('0') << std::setw(7) << timeStep;
	savePointDir = ss.str();
	
	mkdir(savePointDir.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	
	ierr = DMCompositeGetAccess(qPack, q, &qxGlobal, &qyGlobal); CHKERRQ(ierr);
	
	// print qx to file
	ss.str("");
	ss.clear();
	ss << savePointDir << "/qx.dat";
	fileName = ss.str();
	ierr = PetscViewerBinaryOpen(PETSC_COMM_WORLD, fileName.c_str(), FILE_MODE_WRITE, &viewer); CHKERRQ(ierr);
	ierr = VecView(qxGlobal, viewer); CHKERRQ(ierr);
	ierr = PetscViewerDestroy(&viewer); CHKERRQ(ierr);

	// print qy to file
	ss.str("");
	ss.clear();
	ss << savePointDir << "/qy.dat";
	fileName = ss.str();
	ierr = PetscViewerBinaryOpen(PETSC_COMM_WORLD, fileName.c_str(), FILE_MODE_WRITE, &viewer); CHKERRQ(ierr);
	ierr = VecView(qyGlobal, viewer); CHKERRQ(ierr);
	ierr = PetscViewerDestroy(&viewer); CHKERRQ(ierr);

	ierr = PetscPrintf(PETSC_COMM_WORLD, "Data written to folder %s.\n", savePointDir.c_str()); CHKERRQ(ierr);
	
	ierr = DMCompositeRestoreAccess(qPack, q, &qxGlobal, &qyGlobal); CHKERRQ(ierr);

	return 0;
}

template <>
PetscErrorCode NavierStokesSolver<3>::writeFluxes()
{
	PetscErrorCode  ierr;
	Vec             qxGlobal, qyGlobal, qzGlobal;
	std::string     savePointDir, fileName;
	PetscViewer     viewer;

	// create output folder
	std::stringstream ss;
	ss << caseFolder << "/" << std::setfill('0') << std::setw(7) << timeStep;
	savePointDir = ss.str();
	
	mkdir(savePointDir.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	
	ierr = DMCompositeGetAccess(qPack, q, &qxGlobal, &qyGlobal, &qzGlobal); CHKERRQ(ierr);
	
	// print qx to file
	ss.str("");
	ss.clear();
	ss << savePointDir << "/qx.dat";
	fileName = ss.str();
	ierr = PetscViewerBinaryOpen(PETSC_COMM_WORLD, fileName.c_str(), FILE_MODE_WRITE, &viewer); CHKERRQ(ierr);
	ierr = VecView(qxGlobal, viewer); CHKERRQ(ierr);
	ierr = PetscViewerDestroy(&viewer); CHKERRQ(ierr);

	// print qy to file
	ss.str("");
	ss.clear();
	ss << savePointDir << "/qy.dat";
	fileName = ss.str();
	ierr = PetscViewerBinaryOpen(PETSC_COMM_WORLD, fileName.c_str(), FILE_MODE_WRITE, &viewer); CHKERRQ(ierr);
	ierr = VecView(qyGlobal, viewer); CHKERRQ(ierr);
	ierr = PetscViewerDestroy(&viewer); CHKERRQ(ierr);

	// print qz to file
	ss.str("");
	ss.clear();
	ss << savePointDir << "/qz.dat";
	fileName = ss.str();
	ierr = PetscViewerBinaryOpen(PETSC_COMM_WORLD, fileName.c_str(), FILE_MODE_WRITE, &viewer); CHKERRQ(ierr);
	ierr = VecView(qzGlobal, viewer); CHKERRQ(ierr);
	ierr = PetscViewerDestroy(&viewer); CHKERRQ(ierr);

	ierr = PetscPrintf(PETSC_COMM_WORLD, "Data written to folder %s.\n", savePointDir.c_str()); CHKERRQ(ierr);
	
	ierr = DMCompositeRestoreAccess(qPack, q, &qxGlobal, &qyGlobal, &qzGlobal); CHKERRQ(ierr);

	return 0;
}