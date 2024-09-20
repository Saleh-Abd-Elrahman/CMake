find_package(Doxygen REQUIRED)
set(DOXYGEN_INPUT_DIR ${PROJECT_SOURCE_DIR}/src) # Location of the source code
set(DOXYGEN_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/doxygen) # Location of the
set(DOXYGEN_INDEX_FILE ${DOXYGEN_OUTPUT_DIR}/xml/index.xml) # The main file
set(DOXYFILE_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in) # The template Doxyfile
set(DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile) # The output Doxyfile
configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)
# Doxygen won't create this for us
file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIR})
# Only regenerate Doxygen when some public headers change
get_target_property(PUBLIC_HEADER_DIR my_executable_1 INTERFACE_INCLUDE_DIRECTORIES)
file(GLOB_RECURSE PUBLIC_HEADERS ${PUBLIC_HEADER_DIR}/*.h)
add_custom_command(OUTPUT ${DOXYGEN_INDEX_FILE}
DEPENDS ${PUBLIC_HEADERS}
COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
MAIN_DEPENDENCY ${DOXYFILE_OUT} ${DOXYFILE_IN}
COMMENT "Generating docs"
VERBATIM)

set(SPHINX_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/source) # Location of the Sphinx

set(SPHINX_BUILD ${CMAKE_CURRENT_BINARY_DIR}/sphinx) # Location of the

add_custom_target(Sphinx ALL COMMAND sphinx-build -b html -Dbreathe_projects.${PROJECT_NAME}=${DOXYGEN_OUTPUT_DIR}/xml
${SPHINX_SOURCE} ${SPHINX_BUILD}
WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
COMMENT "Generating documentation with Sphinx")