#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main () {


  ifstream my_input_file("datensumme.txt"); // create and open input file

  if (my_input_file.is_open()) {

    int sum;
    int count = 0;
    int sum_all = 0;



    while (count < 234){
      my_input_file >> sum;

      sum_all = sum + sum_all; //sum of all the sums in datensumme
      count++; //increment counter
    }

    int mean = sum_all/count; //mean of total sum of all values in datensumme

    cout << mean << endl; //prints mean

    my_input_file.close(); //closes input file

    ifstream my_input_file("datensumme.txt"); //re-open input file

    int n = 0; //new counter
    int variance_sum = 0; // to sum all (a-a_bar)^2
    int variance_diff_sq = 0; // (a - a_bar)^2

    while (n<234){

      my_input_file >> sum; //store numbers into variable sum
      variance_diff_sq = (sum - mean)*(sum - mean); // (a- a_bar)^2
      variance_sum += variance_diff_sq; //sum (a-a_bar)^2
      n++;
    }

    int variance = variance_sum/n; //compute variance
    cout  << variance << endl; //prints variance

    int st_dev = sqrt(variance); //computes standard deviation

    cout  << st_dev <<endl; //prints standard deviation

    my_input_file.close(); //close input file

  }

   else {
     cout << "file not open" <<endl;
     return 0;
   }

}
