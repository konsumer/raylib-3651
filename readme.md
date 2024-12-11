This is mean to test [raylib#3651](https://github.com/raysan5/raylib/issues/3651).

Essentially, on 1 controller I have ([PXN-P50S](https://www.e-pxn.com/products/gaming-controller/pxn-p50s)), on Mac Sonoma (on an M1) it does not read buttons. All these targets work fine with an official PS5 controller.

### building

You will need cmake & ninja installed.

```bash
# start local webserver for SDL, GLFW, raylib-sdl, raylib-glfw
npm start

# build
```

### results

- [Normal Web](https://hardwaretester.com/gamepad) and [Raylib Web](https://www.raylib.com/examples/core/loader.html?name=core_input_gamepad) work fine.
- [Web GLFW](http://konsumer.js.org/raylib-3651/) and [Web SDL](http://konsumer.js.org/raylib-3651/sdl.html) works fine
- Bare GLFW works for 4 seconds after initially pairing, but then stops reading buttons
- Bare SDL2: TBD
- Raylib with `PLATFORM_DESKTOP_GLFW` - same problem as GLFW
- Raylib with `PLATFORM_DESKTOP_SDL`: TBD
