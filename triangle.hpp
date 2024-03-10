
class triangle
{
private:
    double side_a, side_b, side_c;
    double angle_A, angle_B, angle_C;
public:
    // getters
    double get_side_a();
    double get_side_b();
    double get_side_c();
    double get_angle_A();
    double get_angle_B();
    double get_angle_C();

    // setters
    void set_side_a(double);
    void set_side_b(double);
    void set_side_c(double);
    void set_angle_A(double);
    void set_angle_B(double);
    void set_angle_C(double);

    //isTriangle
    bool isTriangle() const;
};


