

#include <iostream>
#include <fstream> //class declarations for streams

using namespace std;


int main ()
{

//initialise variables to be used to read from daten.txt
  int var_one;
  int var_two;

/*
ifstream my_input_file; //  an input file stream object
ofstream my_output_file; // an output file stream object

my_input_file.open("input_data"); // open the file named "input_data"
my_output_file.open("output_data"); // open the file named "output_data"
*/

  ifstream my_input_file("daten.txt"); // create and open input file in one line instead of those above
  ofstream my_output_file("datensumme.txt"); //create and open output file

  if (my_input_file.is_open()) {

    // can continue, file opened correctly
    int n = 0; //initialise counter
    int sum; //initialise variable to store sum of two input numbers

    while (n<234){     //loop over file 234 times for each number pair

      my_input_file >> var_one >> var_two; //insert numbers from file into two variables, var_one and var_two
      cout  <<  var_one   << ' ' <<  var_two  << endl; //print number pair in terminal
      sum = var_one + var_two; //add the number pair and assign value to previously initialised variable sum
      my_output_file << sum << endl; //saves sums in output file
      cout <<  sum << endl; //prints sum in terminal
      n++; //increment counter by one
    }


    my_input_file.close(); // close the file associated with this input stream
    my_output_file.close(); //close the file associated with the output stream

  }

  else {
    cout<< "file not open"<<endl;
    return 0;
  }

}
