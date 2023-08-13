# Matrix library

Repository that contains the **MARSVIN** library that contains usefull containers and operations for linear algebra.

Contains :

* Matrix container.
* Vector container.
* Forward substitution.
* Backward substitution.
* Gauss elimination.
* Matrix inverse calculation.
* Solution of A\*x = b.

Documentation of classes and examples: [Link](./documentation/main.md)

## How to build library

1. Clone repository
2. Run bash script
```
bash build-code.sh
```

## How to use it as a submodule

1. Add repository as submodule

```
git submodule add git@github.com:MarsvinTech/marsvin-library-cpp.git
```

2. Initiate submodule
```
git submodule update --init --recursive
```

3. In CMakeListst.txt : Add marsvin subdirectory.
```
add_subdirectory(${PATH_TO_MARSVIN_DIRECTORY}/marsvin-library-cpp)
```

4. In CMakeListst.txt : Link marsvin library to your target
```
target_link_libraries(${YOUR_TARGET_NAME} marsvin)
```

5. Include header file in your code:
```
#include "marsvin.hpp"
```

## How to build Doxygen documentation

Documentation HTML files are created using Doxygen.
The documentation is generated into **docs/output-dir** directory.

1. Go to docs directory and run doxygen

```
cd docs
doxygen
```

