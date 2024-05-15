include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_CONTACT ozhogin.m@gmail.com})

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "State for C++")
set(CPACK_RESOURCE_FILE_README ${CMAKE_CURRENT_SOURCE_DIR}/README.md)

set(CPACK_RPM_PACKAGE_NAME "staate")
set(CPACK_RPM_PACKAGE_LICENSE "MIT")
set(CPACK_RPM_PACKAGE_GROUP "state")
set(CPACK_RPM_PACKAGE_RELEASE 1)

set(CPACK_DEBIAN_PACKAGE_NAME "libstate-dev")
set(CPACK_DEBIAN_PACKAGE_PREDEPENDS "cmake >= 3.10")
set(CPACK_DEBIAN_PACKAGE_RELEASE 1)

include(CPack)