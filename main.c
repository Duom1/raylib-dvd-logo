#include <raylib.h>
#include <stdio.h>

int main() {
  Vector2 screen = {1200, 800},
          cube_position = {(float)screen.x / 2 - 20, (float)screen.y / 2 - 20},
          cube_size = {100, 100}, cube_velocity = {300.0f, 300.0f};
  /* Image dvd_image = LoadImage("./linux.png"); */
  /* Texture2D dvd_logo = LoadTextureFromImage(dvd_image); */
  float dt;
  char info[500];
  int current_fps, xo = 100, x = xo;
  InitWindow(screen.x, screen.y, "title");
  SetTargetFPS(500);

  while (!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(WHITE);
    DrawRectangle(cube_position.x, cube_position.y, cube_size.x, cube_size.y,
                  RED);
    /* DrawTexture(dvd_logo, cube_position.x, cube_position.y, RAYWHITE); */
    EndDrawing();

    if (IsKeyPressed(KEY_F1))
      SetTargetFPS(30);
    if (IsKeyPressed(KEY_F2))
      SetTargetFPS(120);
    if (IsKeyPressed(KEY_F3))
      SetTargetFPS(500);

    dt = GetFrameTime();
    if (cube_position.y >= screen.y - cube_size.y || cube_position.y <= 0)
      cube_velocity.y *= -1;
    if (cube_position.x >= screen.x - cube_size.x || cube_position.x <= 0)
      cube_velocity.x *= -1;
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
    x++;
  }
  CloseWindow();
  return 0;
}
