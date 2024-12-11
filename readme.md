This is mean to test [raylib#3651](https://github.com/raysan5/raylib/issues/3651).

Essentially, on 1 controller I have ([PXN-P50S](https://www.e-pxn.com/products/gaming-controller/pxn-p50s)), on Mac Sonoma (on an M1) it does not read buttons. All these targets work fine with an official PS5 controller.

### building

You will need cmake & ninja installed.

```bash
# start local webserver for SDL, GLFW, raylib-sdl, raylib-glfw
npm start

# build native demos
npm run build:native

# build seperate demos, if you want
npm run build:web-glfw
npm run build:web-sdl
npm run build:web-raylib-glfw
npm run build:web-raylib-sdl

npm run build:native-glfw
npm run build:native-sdl
npm run build:native-raylib-glfw
npm run build:native-raylib-sdl
```

### results

- [Plain Web](https://hardwaretester.com/gamepad) and [Raylib Web](https://www.raylib.com/examples/core/loader.html?name=core_input_gamepad) work fine.
- [Web](http://konsumer.js.org/raylib-3651/) has working `web-glfw`/`web-sdl`/`web-raylib-glfw`/`web-raylib-sdl`
- `native-glfw` works for 4 seconds after initially pairing, but then stops reading buttons
- `native-sdl`: TBD
- `web-raylib-glfw`/`web-raylib-sdl`: TBD
