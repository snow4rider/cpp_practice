#include <cstdint>

/**
 * @brief Computes the maximum of two unsigned 8-bit integers.
 *
 * @param[in] a The first unsigned 8-bit integer.
 * @param[in] b The second unsigned 8-bit integer.
 * @return The maximum of `a` and `b`.
 */
constexpr uint8_t
max (uint8_t a, uint8_t b)
{
  return a > b ? a : b;
}

/**
 * @brief Computes the maximum of three unsigned 8-bit integers.
 *
 * @param[in] a The first unsigned 8-bit integer.
 * @param[in] b The second unsigned 8-bit integer.
 * @param[in] c The third unsigned 8-bit integer.
 * @return The maximum of `a`, `b`, and `c`.
 */
constexpr uint8_t
max (uint8_t a, uint8_t b, uint8_t c)
{
  return max (max (a, b), max (a, c));
}

/**
 * @brief Computes the minimum of two unsigned 8-bit integers.
 *
 * @param[in] a The first unsigned 8-bit integer.
 * @param[in] b The second unsigned 8-bit integer.
 * @return The minimum of `a` and `b`.
 */
constexpr uint8_t
min (uint8_t a, uint8_t b)
{
  return a < b ? a : b;
}

/**
 * @brief Computes the minimum of three unsigned 8-bit integers.
 *
 * @param[in] a The first unsigned 8-bit integer.
 * @param[in] b The second unsigned 8-bit integer.
 * @param[in] c The third unsigned 8-bit integer.
 * @return The minimum of `a`, `b`, and `c`.
 */
constexpr uint8_t
min (uint8_t a, uint8_t b, uint8_t c)
{
  return min (min (a, b), min (a, c));
}

/**
 * @brief Computes the modulo of two floating-point numbers.
 *
 * This function calculates the remainder of the division of the dividend
 * by the divisor. The result is the floating-point equivalent of the modulo
 * operation for integers, where the divisor is multiplied by the fractional
 * part of the division.
 *
 * @param[in] dividend The dividend in the division operation.
 * @param[in] divisor The divisor in the division operation.
 * @return The remainder of the division operation as a floating-point number.
 */
constexpr float
modulo (float dividend, float divisor)
{
  const auto quotient = dividend / divisor;
  return divisor * (quotient - static_cast<uint8_t> (quotient));
}

struct Color
{
  float H, S, V;
};

/**
 * @brief Converts RGB color values to HSV.
 *
 * This function takes in RGB color values and computes the equivalent
 * HSV (Hue, Saturation, Value) color representation.
 *
 * @param[in] r The red component of the color (0-255).
 * @param[in] g The green component of the color (0-255).
 * @param[in] b The blue component of the color (0-255).
 * @return A Color struct containing the HSV representation:
 * - H: Hue in degrees (0-360).
 * - S: Saturation as a fraction (0-1).
 * - V: Value as a fraction (0-1).
 */
constexpr Color
rgb_to_hsv (uint8_t r, uint8_t g, uint8_t b)
{
  Color c{};
  const auto c_max = max (r, g, b);
  c.V = c_max / 255.0f;

  const auto c_min = min (r, g, b);
  const auto delta = c.V - c_min / 255.0f;
  c.S = c_max == 0 ? 0 : delta / c.V;

  if (c_max == c_min)
    {
      c.H = 0;
      return c;
    }

  if (c_max == r)
    {
      c.H = (g / 255.0f - b / 255.0f) / delta;
    }
  else if (c_max == g)
    {
      c.H = (b / 255.0f - r / 255.0f) / delta + 2.0f;
    }
  else if (c_max == b)
    {
      c.H = (r / 255.0f - g / 255.0f) / delta + 4.0f;
    }
  c.H *= 60.0f;
  c.H = c.H >= 0.0f ? c.H : c.H + 360.0f;
  c.H = modulo (c.H, 360.0f);
  return c;
}

/**
 * @brief The main entry point of the program.
 *
 * This function demonstrates the use of the rgb_to_hsv function by converting
 * the RGB values of black, white, red, green, and blue to their HSV
 * representations. The results are left unprinted.
 */
int
main ()
{
  auto black = rgb_to_hsv (0, 0, 0);
  auto white = rgb_to_hsv (255, 255, 255);
  auto red = rgb_to_hsv (255, 0, 0);
  auto green = rgb_to_hsv (0, 255, 0);
  auto blue = rgb_to_hsv (0, 0, 255);
  // TODO: Print these, output.
}