# Install script for directory: C:/Users/buche/Documents/Git/BFH-CPVR/C++/CPP_Projects_WIN

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "./install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/buche/Documents/Git/BFH-CPVR/C++/CPP_Projects_WIN_build/CPP-01-D.00_HelloWorld/cmake_install.cmake")
  include("C:/Users/buche/Documents/Git/BFH-CPVR/C++/CPP_Projects_WIN_build/CPP-01-D.01_MainArguments/cmake_install.cmake")
  include("C:/Users/buche/Documents/Git/BFH-CPVR/C++/CPP_Projects_WIN_build/CPP-01-D.02_Pointers/cmake_install.cmake")
  include("C:/Users/buche/Documents/Git/BFH-CPVR/C++/CPP_Projects_WIN_build/CPP-01-D.03_References/cmake_install.cmake")
  include("C:/Users/buche/Documents/Git/BFH-CPVR/C++/CPP_Projects_WIN_build/CPP-01-D.04_FunctionCalls/cmake_install.cmake")
  include("C:/Users/buche/Documents/Git/BFH-CPVR/C++/CPP_Projects_WIN_build/CPP-01-D.05_Arrays/cmake_install.cmake")
  include("C:/Users/buche/Documents/Git/BFH-CPVR/C++/CPP_Projects_WIN_build/CPP-01-D.06_ScopeOperator/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/buche/Documents/Git/BFH-CPVR/C++/CPP_Projects_WIN_build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
