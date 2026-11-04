#include <iostream>
#include <string>
using namespace std;

class Processor 
{
public:
    string model;
    int cores;
    Processor(string m, int c) : model(m), cores(c) {}
};

class RAM 
{
public:
    int size;
    int frequency;
    RAM(int s, int f) : size(s), frequency(f) {}
};

class SSD 
{
public:
    int capacity;
    int speed;
    SSD(int c, int s) : capacity(c), speed(s) {}
};

class Screen 
{
public:
    double diagonal;
    string resolution;
    Screen(double d, string r) : diagonal(d), resolution(r) {}
};

class Keyboard 
{
public:
    int keys;
    bool backlight;
    Keyboard(int k, bool b): keys(k), backlight(b) {}
};

class Battery 
{
private:
    int charge;
public:
    int capacity;
    Battery(int c, int ch) : charge(ch), capacity(c) {}

    int getCharge()
    {
        return charge;
    }
};

class GraphicsCard 
{
public:
    string model;
    int memory;
    GraphicsCard(string m, int mem) : model(m), memory(mem) {}
};

class Laptop 
{
private:
    string brand;
    string model;

    Processor processor;
    RAM ram;
    SSD ssd;
    Screen screen;
    Battery battery;

    Keyboard& keyboard; 
    GraphicsCard graphics;

public:
    Laptop(string b, string m, Keyboard& k) : brand(b),
          model(m),
          processor("Intel Core i5", 6),
          ram(16, 3200),
          ssd(512, 3500),
          screen(15.6, "1920x1080"),
          battery(5000, 85),
          keyboard(k),
          graphics("NVIDIA RTX 3050", 4) {}

    void showInfo() 
    {
        cout << "Laptop: " << brand << " " << model << endl;
        cout << "Processor: " << processor.model << endl;
        cout << "Cores: " << processor.cores << endl;
        cout << "RAM: " << ram.size << " GB" << endl;
        cout << "SSD: " << ssd.capacity << " GB" << endl;
        cout << "Screen: " << screen.diagonal << " inches" << endl;
        cout << "Keyboard keys: " << keyboard.keys << endl;
        cout << "Graphics: " << graphics.model << endl;
        cout << "Battery charge: " << battery.getCharge() << "%" << endl;
    }

    void turnOn() 
    {
        if (battery.getCharge() > 0)
        {    cout << "Laptop is ON!" << endl;}
        else
        {    cout << "Battery is empty!" << endl;}
    }
};

int main() 
{
    Keyboard keyboard(104, true);

    Laptop laptop("ASUS", "TUF Gaming", keyboard);

    laptop.showInfo();
    laptop.turnOn();

    return 0;
}