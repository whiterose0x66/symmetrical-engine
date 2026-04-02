#include <cmath>
#include <raylib.h>

Vector2 middlePofloat(Vector2 p_1, Vector2 p_2) {
  float middle_x = (p_1.x + p_2.x) / 2;
  float middle_y = (p_1.y + p_2.y) / 2;
  Vector2 middle_pofloat;
  middle_pofloat.x = middle_x;
  middle_pofloat.y = middle_y;
  return middle_pofloat;
}

void S_triangle(Vector2 p_1, Vector2 p_2, Vector2 p_3, int depth) {
  if (depth <= 0) {
    return;
  }
  Vector2 left_middle = middlePofloat(p_1, p_2);
  Vector2 right_middle = middlePofloat(p_1, p_3);
  Vector2 top = middlePofloat(p_2, p_3);
  DrawTriangle(left_middle, top, right_middle, WHITE);
  S_triangle(left_middle, p_2, top, depth -1 );
  S_triangle(right_middle, top, p_3, depth -1);
  S_triangle(p_1, left_middle, right_middle, depth -1);
}

int main() {
  int depth = 8;
  float WIDTH = 800;
  float HEIGHT = (std::sqrt(3) / 2) * WIDTH;
  Vector2 p_1 = {(WIDTH / 2), 0};
  Vector2 p_2 = {0, HEIGHT};
  Vector2 p_3 = {WIDTH, HEIGHT};
  InitWindow(WIDTH, HEIGHT, "S_triangle");
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE) ;
    DrawTriangle(p_1, p_2, p_3, BLUE);
    S_triangle(p_1, p_2, p_3, depth);
    EndDrawing();
  }

  return 0;
}
