mkdir tacs_project_build
cd tacs_project_build
cmake -G "Visual Studio 10" ..\tacs_project
cmake --build . --config Debug