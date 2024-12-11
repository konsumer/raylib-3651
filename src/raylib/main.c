#include "raylib.h"

int main(void) {
  InitWindow(320, 240, "rasylib joytest");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    char* gpText = "No gampepad";

    for (int gamepad=0; gamepad < 5; gamepad++) {
      if (IsGamepadAvailable(gamepad)) {
        gpText = TextFormat("GP%d: %s", gamepad, GetGamepadName(gamepad));
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
