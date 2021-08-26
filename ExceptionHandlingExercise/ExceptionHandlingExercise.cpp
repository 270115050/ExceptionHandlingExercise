// ExceptionHandlingExercise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


class HardDrive {
private:
    string filename;
    int availStorage;
    static int count;
public:
    HardDrive(string n, int s) {
        filename = n;
        availStorage = s;
    }

    void storeData(string data) {
        availStorage = 2;
        
        if (count > availStorage)
            throw "Drive is FULL\n\n";//this will terminate the function
        else if (count == 1) {
            cout << "Storage is almost full\nAvailable storage: ";
            throw count - availStorage;//this will terminate the function
        }
           
        cout << "Storing data: " << data << endl;
        count++;
    }
};

int HardDrive::count = 1;

int main() {
    HardDrive hd("C: Drive", 2);
    try {//try storing data 
        hd.storeData("MyHusbandoCollection");
        hd.storeData("LeviCompilation");
        hd.storeData("DontOpen");
    }
    //we can have different catch depending what is thrown
    catch (const char* txtException) {//if storage is full
        cout << "Exception: " << txtException << endl;
    } 
    catch (int numException) {//if storage is almost full
        cout << "Exception: " << numException << endl;
    }
    //This is a default exception for example if you thrown a double this will execute
    //Also default handler needs to be at the bottom or the default handler will execute everytime
    //anything below wont run and it will also give you syntax error.
    catch (...) {//this is thrown if the int catch block is commented out
        cout << "Default Exception thrown";
    }

    return 0;
}




