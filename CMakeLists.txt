cmake_minimum_required(VERSION 2.6)

project(foo_project)
set(CMAKE_MODULE_PATH config)
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

#------------------------
# VIGRA
#------------------------
INCLUDE(VigraFindPackage)
VIGRA_FIND_PACKAGE(Vigra)
VIGRA_FIND_PACKAGE(HDF5)

#------------------------
# BOOST
#------------------------
find_package(Boost 1.47 REQUIRED)
find_package(Boost COMPONENTS python REQUIRED)
add_definitions(-DWITH_BOOST)
include_directories(${Boost_INCLUDE_DIR})

#------------------------
# PYTHON LIB
#------------------------
find_package(PythonLibs REQUIRED)
include_directories(
    ${PYTHON_INCLUDE_DIRS}
    ${PYTHON_NUMPY_INCLUDE_DIR}
    ${Boost_INCLUDE_DIR}
    ${Boost_PYTHON_INCLUDE_DIR}
)

#------------------------
# ADD SUBMODULES
#------------------------
add_subdirectory(src)

