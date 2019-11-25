# Gmock Testing of PID Controller
[![Build Status](https://travis-ci.org/vamshibogoju/enpm808x_pid_pair2.svg?branch=master)](https://travis-ci.org/vamshibogoju/enpm808x_pid_pair2)
[![Coverage Status](https://coveralls.io/repos/github/vamshibogoju/enpm808x_pid_pair2/badge.svg?branch=master)](https://coveralls.io/github/vamshibogoju/enpm808x_pid_pair2?branch=master)
---

## Overview

This project depicts the implementation of Gmock testing using:

- cmake
- googletest
- gmock

## Google Mock Testing 

A virtual "PIdControl" class is created to test the mocking framework interfaces in C++ using gmock. The virtual methods are inherited by the PID class where virtual computePID function is re-defined.  

In the ```PidMock.h``` file located in test folder all the methods used in gmocks are defined and are given below:
```
class PidMock : public PIdControl {
 public:
  MOCK_METHOD2(computePID, float(float,float));
  
  MOCK_METHOD1(setKP, bool(float kp));
  
  MOCK_METHOD1(setKI, bool(float ki));
  
  MOCK_METHOD1(setKD, bool(float kd));
};
```
In the ```test.cpp``` file, all the tests are implemented with inline comments for reference.

## cmake changes 
To use gmock make the following changes 

- Base cmake add the following line ```add_subdirectory(vendor/googletest)```
- test/cmake: Include the following lines at the end of the cmake
```
target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include PUBLIC ../vendor/googletest/googlemock/include ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(cpp-test PUBLIC gtest PUBLIC gmock)
```
## Standard install via command-line
```
git clone --recursive https://github.com/vamshibogoju/enpm808x_pid_pair2
cd <path to repository>
git checkout GMock_Extra_Credit_vamshi
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage (for assignments beginning in Week 4)
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/vamshibogoju/enpm808x_pid_pair2
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of cpp-boilerplate

```
cd ~/workspace
mkdir -p enpm808x_pid_pair2-eclipse
cd enpm808x_pid_pair2-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../enpm808x_pid_pair2/
```

## Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "boilerplate-eclipse" directory created previously as root directory -> Finish

# Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


## Build

To build the project, in Eclipse, unfold boilerplate-eclipse project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

## Run

1. In Eclipse, right click on the boilerplate-eclipse in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)



    It is possible to manage version control through Eclipse and the git plugin, but it typically requires creating another project. If you're interested in this, try it out yourself and contact me on Canvas.
