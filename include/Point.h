#ifndef POINT_H
#define POINT_H

class Point
{
    private:
        int x;
        int y;
    public:
        Point();
        Point(int _x, int _y);
        ~Point();
        int getX();
        void setX(int _x);
        int getY();
        void setY(int _y);

        Point& operator+=(const Point& rhs);
        const Point operator+(const Point& rhs) const;
};

#endif
