void initializePixelArray() {

  for (int row = 0; row < NUM_ROWS; row ++) {
    for (int col = 0; col < NUM_COLS; col ++) {

      // initialize all pixels to -1
      pixelArray[row][col] = -1;

      // top row assignment
      if (row == 0) {
        if (col != 0 || col != NUM_COLS - 1) {
          pixelArray[row][col] = topRow;
          topRow --;
        }
      }

      // left col assignment
      if (col == 0) {
        if (row != 0 || row != NUM_ROWS - 1) {
          pixelArray[row][col] = leftCol;
          leftCol ++;
      }

      // bottom row assignment
      if (row == NUM_ROWS - 1) {
        if (col != 0 || col != NUM_COLS - 1) {
          pixelArray[row][col] = bottomRow;
          bottomRow ++;
        }
      }

      // left col assignment
      if (col == NUM_COLS - 1) {
        if (row != 0 || row != NUM_ROWS - 1) {
          pixelArray[row][col] = rightCol;
          rightCol --;
        }
      }

      if (col != NUM_COLS - 1) {
        Serial.print(pixelArray[row][col]);
        Serial.print("   ");
      } else {
        Serial.println(pixelArray[row][col]);
      }
    }
  }
}

void runLED(float temp, float humidity) {
  uint8_t start_r = 3;
  uint8_t start_g = 244;
  uint8_t start_b = 252;
  uint8_t end_r = 252;
  uint8_t end_g = 90;
  uint8_t end_b = 3;


  //calculate color based on temp
  uint8_t red = map(temp, 0, 41, start_r, end_r);
  uint8_t green = map(temp, 0, 41, start_g, end_g);
  uint8_t blue = map(temp, 0, 41, start_b, end_b);

  //calculate height based on humidity
  int pixel_h = map(humidity, 50, 150, 0, NUM_ROWS - 1);
  Serial.print("Color: ");
  Serial.print("red: "); Serial.print(red);
  Serial.print(", green: "); Serial.print(green);
  Serial.print(", blue: "); Serial.println(blue);
  Serial.print("Pixel_h: "); Serial.println(pixel_h);

  pixels.clear();
  for (int row = NUM_ROWS - 1; row >= 0; row --) {
    for (int col = 0; col < NUM_COLS; col ++) {
      if (NUM_ROWS - 1 - row <= pixel_h && pixelArray[row][col] != -1) {
        if (pixelArray[row][col] % 2 == 0) {
          pixels.setPixelColor(pixelArray[row][col], red, blue, green, 50);
        }
      }
    }
  }

  pixels.show();

}

void lerp(float x, float x0, float x1, float y0, float y1) {
  //clamp x within x0 and
}
