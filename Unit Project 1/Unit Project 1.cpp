#include <iostream>
#include <string>
#include <math.h>
#include <cmath>

using namespace std;

// Variables
float tax = 1.13;
float window = 9;
float door = 16;
float payHour = 22.50;



//caculation of total room size (including obstacles)
float totalSize(float Length, float Width, float Height)
{
	return (((Width * Height) + (Length * Height) * 2) + Length * Width);
}


// Windows and Door obstacle caculation
float obstacle(float obs_window, float obs_door)
{
	return (obs_window * window) + (obs_door * door);
}


// cost of materials 
float materialCost(float area)
{
	return area * 3;
}


// caculation of cost 
float timePay(float area)
{
	return (area / 66.0);
}


//helping 
float timeHours(float hour)
{
	return floor(hour);
}


// time caculation in minutes
int timeMin(float Minute)
{
	return (Minute - floor(Minute)) * 60;
}


//time caculation in hours
float paint(float hours)
{
	return hours * payHour;
}



int main()
{
	//varibles 
	float room, Length, Width, Height;

	//obstacle variables
	float window, doors;

	//hours caculaiton
	float hours;

	//painting area
	float paintArea;

	// room size caculaion
	cout << "how big is your room (in feet): \n";
	cout << "Length: ";
	cin >> Length;
	cout << "Width: ";
	cin >> Width;
	cout << "Height: ";
	cin >> Height;

	//total room caculation
	room = (totalSize(Length, Width, Height));

	// Obstacle caculation
	cout << "how many windows do you have?: \n";
	cin >> window;
	cout << "how many doors do you have?: \n";
	cin >> door;

	system("cls");

	//total area to paint
	paintArea = room - (obstacle(window, door));

	// total hours to paint
	hours = (timePay(paintArea));

	//output of total room size including obstacles
	cout << "total room size is " << room << " square feet.\n" << endl;

	//total obstacle size
	cout << "total obstacle sizes are " << (obstacle(window, door)) << " square feet.\n" << endl;

	//paintable area (not including obstacles) 
	cout << "Paintable surface area are " << paintArea << " square feet.\n" << endl;

	//before tax of material cost
	cout << "The subtotal cost of material (pre tax) " << materialCost(paintArea) << "$\n" << endl;

	//after tax of material cost
	cout << "The Total cost of material (post tax)" << materialCost(paintArea) * tax << "$\n" << endl;

	//hours it will take to paint
	cout << "The total hour it will take to paint " << paintArea << " square feet is " << timeHours(hours) << " hours and " << timeMin(hours) << " Minutes. \n" << endl;

	//total cost for the hours
	cout << "The Total cost for " << timeHours(hours) << " hours and " << timeMin(hours) << " Minutes is " << paint(hours) << "$\n" << endl;

	//Press enter to continue...
	system("pause");
	system("cls");

	//Subtotal before tax
	cout << "Subtotal: " << materialCost(paintArea) + paint(hours) << "$ \n" << endl;

	//Tax 
	cout << "Tax: " << ((materialCost(paintArea) + paint(hours))) * 0.13 << "$ \n" << endl;

	//Grandtotal including tax
	cout << "Grand Total: " << (materialCost(paintArea) + paint(hours)) * tax << "$ \n" << endl;
}



//Paint costs $3 per square foot.
// X	Deduct 9 square feet per window, and 16 square feet per door.
//pre-tax and post 13% tax

//Calculate the number of hours it will take to paint, 66 square feet per hour.
//It cost $22.50 per hour (taxes included).
