//assignment 4 -- Structural Improvements
// Cameron Bennett 19cmb13 20204518 

// Header file

using namespace std;
#include <string>
#pragma once

//highest parent class SHAPE
class Shape {
private:
    int length;
    int width;
    string outlineColor;
public:
    //constructors
    Shape(); //default constructor
    Shape(Shape& shape); // copying constructor
    Shape(const int length, const int width, const string outlineColor); // usual constructor
    //constructors
    //-----------
    //accessors
    int getLength(); //length accessor
    int getWidth();  //width accessor
    string getOutlineColor();   //outline color accessor
    //accessors
    //-----------

    virtual void draw() = 0; // draw function
    virtual ~Shape(); // destructor
    Shape& operator=(const Shape& shape); // operator overload
};

//Class for Fillable, to be extended
class Fillable {
private:
    string color;
public:
    //constructors
    Fillable(); // default constructor
    Fillable(const string color); // constructor
    //constructors
    //------------
    //accessor
    string getColor();
    //accessor
    virtual ~Fillable(); //destructor
};

//text fill class
class Text {
private:
    string text;
public:
    // constructors
    Text(); // default constructor
    Text(const string text);
    //constructors
    //------------
    //accessor
    string getText();
    virtual ~Text(); // destructor

};

//------------------------------------------------------------------------------------------------------------
//SHAPE CLASSES
//extending the above 3


//square class
class Square : public Shape {
public:
    //constructors
    Square(); //default constructor
    Square(const int length, const int width, const string outlineColor); // usual constructor
    virtual void draw(); // overide virtual function
    virtual ~Square(); // destructor
};

//circle class
class Circle : public Shape {
public:
    //constructors
    Circle(); // default constructor
    Circle(int length, int width, string outlineColor);
    virtual void draw(); // overide virtual function
    virtual ~Circle(); // destructor
};

//filled square class, extends square and fillable
class FilledSquare : public Square, public Fillable {
public:
    //constructors
    FilledSquare(); // default constructors
    FilledSquare(const int length, const int width, const string outlineColor, const string color); //usual constructor
    virtual void draw(); // overridden virtual draw function for a filled square
    virtual ~FilledSquare(); //destructor
};

//filled circle class, extends circle and fillable
class FilledCircle : public Circle, public Fillable {
public:
    //constructors
    FilledCircle(); // default constructor
    FilledCircle(int length, int width, string outlineColor, string color); // usual constructor
    virtual void draw(); // overriden virtual draw function for a filled circle
    virtual ~FilledCircle(); //destructor
};
//filled square with text class, extends square, fillable, and text
class FilledTextSquare : public Square, public Fillable, public Text {
public:
    //constructors
    FilledTextSquare(); // default constructor
    FilledTextSquare(const int length, const int width, const string outlineColor, const string color, const string text); // usual constructor
    virtual void draw(); // overriden virtual draw function for a filled text square
    virtual ~FilledTextSquare(); //destructor
};

//class for Arc, extends shape

class Arc : public Shape {
public: 
    //constructors
    Arc(); // default constructor
    Arc(int length, int width, string outlineColor); // usual constructor
    virtual void draw(); // overriden virtual function draw for arc class
    virtual ~Arc();  //destructor

};