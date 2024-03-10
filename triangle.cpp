#include "triangle.hpp"

// Getters

/**
 * @brief Get the value of side_a
 *
 * @return The value of side_a
 */
double triangle::get_side_a()
{
    // Return the value of side_a
    return side_a;
}

/**
 * Get the value of side B for the triangle.
 * @return the value of side B
 * @throws None
 */
double triangle::get_side_b()
{
    return side_b;
}

/**
 * Get the value of side_c.
 * @return the value of side_c
 * @throws None
 */
double triangle::get_side_c()
{
    return side_c;
}

/**
 * Get the value of angle A in the triangle.
 * @return the value of angle A
 */
double triangle::get_angle_A()
{
    return angle_A;
}

/**
 * Get the value of angle B in the triangle.
 * @return the value of angle B
 * @throws None
 */
double triangle::get_angle_B()
{
    return angle_B;
}

/**
 * Get the value of angle C in the triangle.
 * @return the value of angle C
 */
double triangle::get_angle_C()
{
    return angle_C;
}

// Setters

/**
 * Set the value of side_a
 * @param[in] aSide_a The value of side_a to be set
 */
void triangle::set_side_a(double aSide_a)
{
    side_a = aSide_a;
}

/**
 * Set the value of side_b for the triangle.
 * @param aSide_b the value to set for side_b
 * @return void
 * @throws ErrorType if the input value is invalid
 */
void triangle::set_side_b(double aSide_b)
{
    side_b = aSide_b;
}

/**
 * Set the value of side c for the triangle.
 * @param aSide_c the value to set for side c
 * @return void
 * @throws ErrorType if the provided value is invalid
 */
void triangle::set_side_c(double aSide_c)
{
    side_c = aSide_c;
}

/**
 * Set the value of angle A for the triangle.
 * @param aAngle_A the new value for angle A
 * @return void
 * @throws ErrorType if the provided angle value is invalid
 */
void triangle::set_angle_A(double aAngle_A)
{
    angle_A = aAngle_A;
}

/**
 * Set the value of angle B in the triangle.
 * @param aAngle_B the new value for angle B
 * @return void
 * @throws ErrorType N/A
 */
void triangle::set_angle_B(double aAngle_B)
{
    angle_B = aAngle_B;
}

/**
 * Set the value of angle C in the triangle.
 * @param aAngle_C the new value of angle C
 * @return void
 * @throws ErrorType (if any)
 */
void triangle::set_angle_C(double aAngle_C)
{
    angle_C = aAngle_C;
}

/**
 * Check if the angles form a valid triangle.
 * @return true if the angles form a valid triangle, false otherwise
 */
bool triangle::isTriangle() const
{
    return (angle_A + angle_B + angle_C == 180);
}
