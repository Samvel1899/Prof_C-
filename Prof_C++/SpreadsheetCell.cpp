#include <iostream>
#include <sstream>
#include "SpreadsheetCell.h"

using namespace std;


class SpreadsheetCell
{
public:
	SpreadsheetCell();
	SpreadsheetCell(double initialValue);
	SpreadsheetCell(const string& initialValue);
	SpreadsheetCell(const SpreadsheetCell& src);
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
	~SpreadsheetCell() {};

	void setValue(double inValue);
	double getValue();

	void setString(string inString);
	string getString();

protected:
	string doubleToString(double inValue);
	double stringToDouble(string inString);

	double mValue;

	string mString;

};


int main() {

	//--------------------------------------------

	SpreadsheetCell myCell;
	myCell.setValue(6);
	cout << "Cell 1: " << myCell.getValue() << "\n\n";

	//--------------------------------------------

	SpreadsheetCell* myCellp = new SpreadsheetCell(30);

	SpreadsheetCell* anotherCellp;
	anotherCellp = new SpreadsheetCell(20);

	myCellp->setValue(3.7);
	//anotherCell.setValue(myCell.getValue());
	cout << "Cell 1: " << myCellp->getValue() << " , " << myCellp->getString() << endl;
	cout << "Cell 2: " << anotherCellp->getValue() << endl;

	delete myCellp;
	delete anotherCellp;

	//--------------------------------------------

	SpreadsheetCell aThirdCell("test");
	SpreadsheetCell aFourthCell(4.4);
	SpreadsheetCell* aThirdCellp = new SpreadsheetCell("32");

	cout << endl;
	cout << "aThirdCell: " << aThirdCell.getValue() << endl;
	cout << "aFourthCell: " << aFourthCell.getValue() << endl;
	cout << "aThirdCellp: " << aThirdCellp->getValue() << endl;

	delete aThirdCellp;

	//--------------------------------------------

	cout << endl;

	SpreadsheetCell myCell2;
	string name = "First heading";
	myCell2.setString(name);
	cout << "Text: " << myCell2.getValue() << "\n";

	//--------------------------------------------

	cout << endl;

	SpreadsheetCell myCell3(20);
	SpreadsheetCell anotherCell(myCell3);
	cout << "Text: " << myCell3.getValue() << "\n";

	//--------------------------------------------

	cout << endl;

	SpreadsheetCell myCell4(5);

	if (myCell4.getValue() == 5)
	{
		SpreadsheetCell anotherCell2(6);
	}
	cout << "Object myCell4: " << myCell4.getValue() << "\n";

	//--------------------------------------------

	cout << endl;

	SpreadsheetCell* cellPtr1 = new SpreadsheetCell(5);
	SpreadsheetCell* cellPtr2 = new SpreadsheetCell(6);

	cout << "celPtr1: " << cellPtr1->getValue() << "\n";

	delete cellPtr1;
	delete cellPtr2;

	//--------------------------------------------

	return 0;
}



SpreadsheetCell::SpreadsheetCell()
{
	mValue = 0;
	mString = "";
}

SpreadsheetCell::SpreadsheetCell(double initialValue)
{
	setValue(initialValue);
}

SpreadsheetCell::SpreadsheetCell(const string& initialValue)
{
	setString(initialValue);
}

SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src) : mValue(src.mValue), mString(src.mString) {}

SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
	if (this == &rhs)
	{
		return (*this);
	}
	return (*this);
}

void SpreadsheetCell::setValue(double inValue)
{
	mValue = inValue;
	mString = doubleToString(mValue);
}

double SpreadsheetCell::getValue()
{
	return (mValue);
}

void SpreadsheetCell::setString(string inString)
{
	mString = inString;
	mValue = stringToDouble(mString);
}

string SpreadsheetCell::getString()
{
	return (mString);
}

string SpreadsheetCell::doubleToString(double inValue)
{
	ostringstream ostr;
	ostr << inValue;
	return (ostr.str());
}

double SpreadsheetCell::stringToDouble(string inString)
{
	double temp;

	istringstream istr(inString);

	istr >> temp;
	if (istr.fail() || !istr.eof())
	{
		return 0;
	}
	return (temp);
}
