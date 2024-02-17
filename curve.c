// 二次贝塞尔曲线函数
void drawQuadraticBezier(int x0, int y0, int x1, int y1, int x2, int y2, uint16_t color)
{
  float t;
  int x, y;

  // 绘制曲线
  for (t = 0.0; t < 1.0; t += 0.01)
  {
    x = (1 - t) * (1 - t) * x0 + 2 * (1 - t) * t * x1 + t * t * x2;
    y = (1 - t) * (1 - t) * y0 + 2 * (1 - t) * t * y1 + t * t * y2;
    tft.drawPixel(x, y, color);
  }
}

// 绘制曲线函数
void drawCurve_B(int x0, int y0, int spacingX, int *pointsY, int numPoints, uint16_t color)
{
  int x1, y1, x2, y2;

  // 在 x 轴上以固定间距绘制曲线段
  for (int i = 0; i < numPoints - 2; i++)
  {
    // 设置控制点和结束点
    x1 = x0 + spacingX;
    y1 = pointsY[i];
    x2 = x1 + spacingX;
    y2 = pointsY[i + 1];

    // 绘制曲线段
    drawQuadraticBezier(x0, y0, x1, y1, x2, y2, color);

    // 更新起始点
    x0 = x2;
    y0 = y2;
  }
}
