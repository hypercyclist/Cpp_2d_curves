#ifndef COLOR_H
#define COLOR_H

class Color
{
    private:
        int r;
        int g;
        int b;
    public:
        Color(int _r, int _g, int _b);
        ~Color();

        void update();
        
        void setColorRgb(int _r, int _g, int _b);

        int getR() const;
        void setR(int _r);

        int getG() const;
        void setG(int _g);

        int getB() const;
        void setB(int _b);
};

#endif
