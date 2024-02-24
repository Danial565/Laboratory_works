#include <iostream>


class sphere {
private:
    float d_r;
public:
    sphere(float r)
    {
        setR(r);
    }
    void setR(float r)
    {
        if (r < 0)
        {
            throw std::exception("Negative radius");
        }
        d_r = r;
    }
    float getR()
    {
        return d_r;
    }
    float SurfaceArea()
    {
        return  acos(-1) * 4 * pow(d_r, 2);
    }
    float Volume()
    {
        return  (acos(-1) * pow(d_r, 3) * 4) / 3;
    }


};


int main()
{
    int r;
    std::cin >> r;
    try
    {
        sphere s(r);
        s.setR(r);
        std::cout << "surface area of the sphere: " << s.SurfaceArea() << std::endl;
        std::cout << "sphere volume: " << s.Volume() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
   
}

