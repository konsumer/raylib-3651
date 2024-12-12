#include "raylib.h"

int main(void) {
  InitWindow(320, 240, "rasylib joytest");
  SetTargetFPS(60);

  // This map came from SDL
  const char** mappings = {"0300d71f7e0500000920000001006803,DK Switch Controller,a:b0,b:b1,back:b8,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,dpup:h0.1,guide:b9,leftshoulder:b4,leftstick:b6,lefttrigger:a2,leftx:a0,lefty:a1,rightshoulder:b5,rightstick:b7,righttrigger:a5,rightx:a3,righty:a4,start:b10,x:b2,y:b3,platform:Mac OS X,"};
  int mapstatus = SetGamepadMappings(mappings);
  TraceLog(LOG_INFO, "JS: mapping: %d", mapstatus);


  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    char* gpText = "No gampepad";

    for (int gamepad=0; gamepad < 5; gamepad++) {
      if (IsGamepadAvailable(gamepad)) {
        gpText = (char*)TextFormat("GP%d: %s", gamepad, GetGamepadName(gamepad));
        for (int gamepadButton = GAMEPAD_BUTTON_UNKNOWN; gamepadButton <= GAMEPAD_BUTTON_RIGHT_THUMB; gamepadButton++) {
          if (IsGamepadButtonDown(gamepad, gamepadButton)) {
            DrawCircle((gamepadButton*17) + 9, 120, 8, RED);
          } else {
            DrawCircle((gamepadButton*17) + 9, 120, 8, BLUE);          }
        }
      }
    }

    DrawText(gpText, 10, 10, 10, WHITE);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
