/** Kevin Griffin
 *  Lab ex-7
 *  Cartesian to polar/polat to cart calculator
 *
 */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h>
#include <cmath>
#include <conio.h>
using namespace std;




int main(void)
{
    /** local variable declarations*/
    void cart_polar(void);
    void polar_cart(void);
    char displaymenu(void);
    /**< variable declarations */
    char choice;
    /** Do while loop to select which function to use*/
    do
    {
        choice = displaymenu();

            switch (choice)
        {
            case 'p' :  cart_polar();
                        break;

            case 'c' :  polar_cart();
                        break;

            case 'q' :  system("cls");
                        cout << "Goodbye" << endl;
                        break;

            default :   cout << "invalid selection" << endl;
                        break;
        }
    }
    while (choice != 'q');

    return 0;
}
/** Menu display to prompt the user to select a calculator*/
char displaymenu(void)
{
    char choice;

    system("cls");
/** menu options for the user*/
    cout << "Coordinate Conversion \n \n";
    cout << "press p for cart_polar conversion \n";
    cout << "press c for polar_cart conversion \n";
    cout << "Press q to quit \n \n ";
    /** returns the users choice*/
    choice = getchar();

    return choice;
}
/** Cart to polar conversion function*/
void cart_polar(void)
{
    /** variable declaratins*/
    double real, imag, mag, angle;
    double *mag_ptr, *angle_ptr;
    /**clears the screen*/
    system("cls");
    /** Cart to pol calculation variables*/
    void cart_polarCalculation(double, double, double *, double *);
    /**tells the user the selected Calculator is*/
    cout << "Cartesian to Polar Conversion\n\n" << endl;
    /** initialising pointers*/
    mag_ptr = &mag;
    angle_ptr = &angle;

    /** prompts the users to enter real value*/
    cout << "Enter real value"<< endl;
    cin >> real;
    /** prompts the users to enter real value*/
    cout << "Enter imaginary part:\t" << endl;
    cin >> imag;
    /**Calls the calculating function*/
    cart_polarCalculation(real, imag, mag_ptr, angle_ptr);

    /**Displays the results for mag and angle*/
     cout << mag << " < " << angle << endl;
    /**prompts the user to hit enter to return to the main menu*/
     cout << "Press Enter to Continue";
     /** holds the program until any key is hit*/
     getch();

    return;
}
/** cart to polar calculator function*/
void cart_polarCalculation(double rVal, double iVal, double *mPtr, double *aPtr)
{
    *mPtr = sqrt(pow(rVal, 2) + pow(iVal, 2));
    *aPtr = 180 * atan2(iVal, rVal) / M_PI;

return ;
}


/**Polar to cart function*/
void polar_cart(void)
{
    /**local variable decalrations*/
    double real, imag, mag, angle;
    double *real_ptr, *imag_ptr;
    /**clears the screen*/
    system("cls");
    /**calls the calculator function*/
    void polar_cartCalculation(double, double, double *, double *);
    /**Informs the user of the type of calculator selected*/
    cout << "Polar to Cartesian Conversion\n\n" << endl;
    /**initalises the pointers*/
    real_ptr = &real;
    imag_ptr = &imag;
    /**prompts the user to enter a value for magnitude*/
    cout << "Enter magnitude value: "<< endl;
    cin >> mag;
    /**prompts the user to enter a value for magnitude*/
    cout << "Enter an angle value in degrees: "<< endl;
    cin >> angle;

    polar_cartCalculation(mag, angle, real_ptr, imag_ptr);
    /**Displays the results for real and imag*/
    cout << real << ", " << imag << endl;
    /**prompts the user to hit enter to return to the main menu*/
    cout << "Press Enter to Continue";
    /** holds the program until any key is hit*/
    getch();

    return;
}

/** polar to cartesian calculator function*/
void polar_cartCalculation(double magnitude, double angle, double *xPtr, double *yPtr)
{
    *xPtr = magnitude * cos(angle / 180.0 * M_PI);
    *yPtr = magnitude * sin(angle / 180.0 * M_PI);

    return;
}
