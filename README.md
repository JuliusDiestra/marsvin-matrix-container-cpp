# marsvin-library-cpp
------------------------------------------------------------------------------

Repository that contains the **MARSVIN** library that contains a matrix class.

Current implementations:

* Matrix Class template using std::vector.
* Matrix Class contains operator to access elements and addition, multiplication and subtraction.
* Numerical differentiation: First, Second derivative, Gradient and Jacobian.

.... More coming soon  ... or maybe not too soon.

The **MARSVIN** library depends only on standard libraries and a lot of coffee.
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

6. Use the marsvin matrix class to play around.

## How to build documentation

Documentation HTML files are created using Doxygen.
The documentation is generated into **docs/output-dir** directory.

1. Go to docs directory and run doxygen

```
cd docs
doxygen
```

