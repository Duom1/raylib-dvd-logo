#include <raylib.h>
#include <stdio.h>

int main() {
  Vector2 screen = {1200, 800},
          cube_position = {(float)screen.x / 2 - 20, (float)screen.y / 2 - 20},
          cube_size = {100, 200}, cube_velocity = {400.0f, 400.0f};
  float dt;
  char info[500];
  int current_fps, xo = 100, x = xo;

  InitWindow(screen.x, screen.y, "title");
  Image dvd_image = LoadImage("./dvd_logo.png");
  ImageResize(&dvd_image, cube_size.y, cube_size.x);
  Texture2D dvd_logo = LoadTextureFromImage(dvd_image);
  UnloadImage(dvd_image);
  SetTargetFPS(9999999);

  while (!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(WHITE);
    DrawTexture(dvd_logo, cube_position.x, cube_position.y, WHITE);
    EndDrawing();

    if (IsKeyPressed(KEY_F1))
      SetTargetFPS(30);
    if (IsKeyPressed(KEY_F2))
      SetTargetFPS(120);
    if (IsKeyPressed(KEY_F3))
      SetTargetFPS(500);
    if (IsKeyPressed(KEY_F4))
      SetTargetFPS(9999999);

    dt = GetFrameTime();
    if (cube_position.y >= screen.y - cube_size.x) {
      cube_velocity.y *= -1;
      cube_position.y = screen.y - cube_size.x;
    }
    if (cube_position.y <= 0) {
      cube_velocity.y *= -1;
      cube_position.y = 0;
    }
    if (cube_position.x >= screen.x - cube_size.y) {
      cube_velocity.x *= -1;
      cube_position.x = screen.x - cube_size.y;
    }
    if (cube_position.x <= 0) {
      cube_velocity.x *= -1;
      cube_position.x = 0;
    }
    cube_position.x += cube_velocity.x * dt;
    cube_position.y += cube_velocity.y * dt;

    if (x % xo == 0) {
      x = 0;
      current_fps = GetFPS();
      sprintf(info,
              "fps: %d | x:%0.2f y:%0.2f | velocity x:%0.2f y:%0.2f | dt=%f",
              current_fps, cube_position.x, cube_position.y, cube_velocity.x,
              cube_velocity.y, dt);
      SetWindowTitle(info);
    }
    x += 0.5 * dt;
  }
  UnloadTexture(dvd_logo);
  CloseWindow();
  return 0;
}
