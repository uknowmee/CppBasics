//
// Created by Michał on 22.04.2021.
//

#ifndef LAB_6_FIGURE_H
#define LAB_6_FIGURE_H
using namespace std;

class Figure {
    string type;
    class Point2D {
    public:
        int x_ob;
        int y_ob;

        Point2D();
        Point2D(int _x, int _y);

        double getPtX() const { return x_ob; };
        double getPtY() const { return y_ob; };

        void setPtXY(int x, int y);
    };
    Point2D coord;

public:
    Figure();
    Figure(const Figure &f);
    virtual ~Figure() = default;

    void getType() { cout << type; }
    virtual string getTyper() { return type; }
    void getCo() const { cout << "(" << coord.x_ob << " , " << coord.y_ob << ")"; }
    double getX() const { return this->coord.x_ob; }
    double getY() const { return this->coord.y_ob; }
    virtual double getArea() const { return 0; };
    virtual double getCircumference() { return 0; };

    void setXY(int _x, int _y);
    void setType(const char *n);

    bool operator<( const Figure &fig1) const;
};


#endif //LAB_6_FIGURE_H
