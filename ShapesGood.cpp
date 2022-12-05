//CMPE 320 Assignment 4 Cameron Bennett
//19cmb13 20204518
//cpp file


#include <iostream>
using namespace std;
#include <string>
#include "./ShapesGood.h"
//------------------------SHAPE CONSTRUCTORS-----------------------------
Shape::Shape() : length(0), width(0), outlineColor("none") {}
Shape::Shape(const int len, const int wid, const string olc ) : length(len), width(wid), outlineColor(olc) {}
//-----------------------SHAPE DESTRUCTOR-------------------------------
Shape::~Shape() {}
//-----------------------SHAPE ACCESSORS--------------------------------
int Shape::getLength() { return length; }
int Shape::getWidth() { return width; }
string Shape::getOutlineColor() { return outlineColor; }
//-----------------------SHAPE COPY CONSTRUCTOR-------------------------
Shape::Shape(Shape& shape){
    this->length = shape.getLength();
    this->width = shape.getWidth();
    this->outlineColor = shape.getOutlineColor();
}
//----------------------SHAPE OPERATOR OVERLOAD-------------------------
Shape& Shape::operator=(const Shape&){
    this->length = getLength();
    this->width = getWidth();
    return *this;
}
//------------------------------END OF SHAPE----------------------------


//------------------------------FILLABLE CLASS--------------------------
//------------------------------FILLABLE CONSTRUCTORS-------------------
Fillable::Fillable() : color("none") {} 
Fillable::Fillable(const string fillColor) : color(fillColor) {}
//------------------------------FILLABLE ACCESSORS---------------------
string Fillable::getColor() {return color;}
//------------------------------FILLABLE VIRTUAl FUNC-------------------
Fillable::~Fillable(){} //destructor
//-------------------------------END OF FILLABLE------------------------

//-------------------------------TEXT CLASS-----------------------------
//-------------------------------TEXT CONSTRUCTORS----------------------
Text::Text() : text("\0") {}
Text::Text(string text) : text(text) {}
//-------------------------------TEXT ACCESSORS-------------------------
string Text::getText(){return text;}
//-------------------------------TEXT VIRTUAL FUNCS---------------------
Text::~Text(){}
//------------------------------END OF TEXT CLASS-----------------------

//-----------------------------SQUARE CLASS ----------------------------
//-----------------------------EXTENDS SHAPE ---------------------------
Square::Square() : Shape(0,0,"none") {}
Square::Square(const int length, const int width, const string ocl) : Shape(length, width, ocl) {}
void Square::draw(){ cout << "\nDrawing a " + getOutlineColor() + " square."; }
Square::~Square() {}
//-----------------------------END OF SQUARE CLASS-----------------------

//----------------------------CIRCLE CLASS-------------------------------
//----------------------------EXTENDS SHAPE------------------------------
Circle::Circle() : Shape(0,0,"none") {}
Circle::Circle(int length, int width, string ocl) : Shape(length, width, ocl) { }
void Circle::draw() { cout << "\nDrawing a " + getOutlineColor() + " circle.";}
Circle::~Circle() {}
//----------------------------END OF CIRCLE CLASS------------------------

//----------------------------FILLED SQUARE CLASS------------------------
//----------------------------EXTENDS SQUARE AND FILLED------------------
FilledSquare::FilledSquare() : Square(0, 0, "none"), Fillable("none") {}
FilledSquare::FilledSquare(const int length, const int width, const string ocl, const string fillColor) : Square(length, width, ocl), Fillable(fillColor) {}
void FilledSquare::draw() {
    cout << "\nDrawing a " << getOutlineColor() << " square. With " << getColor() << " fill.";
}
FilledSquare::~FilledSquare() {}
//---------------------------END OF FILLED SQUARE------------------------

//---------------------------FILLED CIRCLE CLASS-------------------------
FilledCircle::FilledCircle() : Circle(0,0,"none"), Fillable("none") {}
FilledCircle::FilledCircle(int length, int width, string ocl, string fillColor) : Circle(length, width, ocl), Fillable(fillColor) {}
void FilledCircle::draw(){ 
    cout << "\nDrawing a " << getOutlineColor() << " circle. With " << getColor() << " fill.";
}
FilledCircle::~FilledCircle() {}
//--------------------------END OF FILLEC CIRCLE-------------------------


//--------------------------FILLED TEXT SQUARE---------------------------
//--------------------------EXTENDS SQUARE, FILLED, AND TEXT-------------
FilledTextSquare::FilledTextSquare() : Square(0,0,"none"), Fillable("none"), Text("none") {}
FilledTextSquare::FilledTextSquare(const int length, 
                                   const int width, 
                                   const string ocl, 
                                   const string fillColor, 
                                   const string text) : Square(length, width, ocl), 
                                                        Fillable(fillColor), 
                                                        Text(text) {}
void FilledTextSquare::draw() { 
    cout << "\nDrawing a " << getOutlineColor() << " Square. With " << getColor() << " fill."  << " Containing the text: \"" << getText() << "\".";
}
FilledTextSquare::~FilledTextSquare() {}
//-----------------------END OF FILLED TEXT SQUARE-------------------------

//-----------------------ARC CLASS-----------------------------------------
//----------------------EXTENDS SHAPE--------------------------------------
Arc::Arc() : Shape(0,0,"none") {}
Arc::Arc(int length, int width, string ocl) : Shape(length, width, ocl) {}
void Arc::draw() {
    cout << "\nDrawing a " << getOutlineColor() << " arc.";
}
Arc::~Arc() {}
//-----------------------END OF ARC-------------------------------------------