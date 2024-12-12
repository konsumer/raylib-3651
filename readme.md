This is mean to test [raylib#3651](https://github.com/raysan5/raylib/issues/3651).

Essentially, on 1 controller I have ([PXN-P50S](https://www.e-pxn.com/products/gaming-controller/pxn-p50s)), on Mac Sonoma (on an M1) it does not read buttons. All these targets work fine with an official PS5 controller.

Here are the things I test here:

- plain glfw - does not register buttons, but picks up name, fine with PS5 controller. weirdly works correctly for 4 seconds after paring.
- raylib-glfw - same problems
- raylib-sdl - works fine

### building

You will need cmake & ninja installed (mac: `brew install cmake ninja`)

```bash
# build jstest_glfw: a plain GLFW test
cmake -G Ninja -B build && cmake --build build --target jstest_glfw && jstest_glfw

# build jstest_raylib_glfw: a raylib GLFW test
cmake -G Ninja -B build -DPLATFORM=Desktop && cmake --build build --target jstest_raylib_glfw && ./jstest_raylib_glfw

# build jstest_raylib_sdl: a raylib SDL test
cmake -G Ninja -B build -DPLATFORM=SDL && cmake --build build --target jstest_raylib_sdl && ./jstest_raylib_sdl
```