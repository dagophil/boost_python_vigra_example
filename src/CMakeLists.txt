#----------------------------
# ADD MODULES
#----------------------------
add_library(
    _foo SHARED foo_python.cxx
)

#----------------------------
# LINK LIBRARIES
#----------------------------
target_link_libraries(_foo
    ${Boost_PYTHON_LIBRARIES}
    ${VIGRA_IMPEX_LIBRARY}
    ${VIGRA_NUMPY_CORE_LIBRARY}
    ${VIGRA_NUMPY_IMPEX_LIBRARY}
)

#----------------------------
# RENAME LIBRARIES
#----------------------------
set_target_properties(_foo PROPERTIES PREFIX "")

