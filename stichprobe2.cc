#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main () {

/*

Compute mean of every 9 numbers of datensumme and store in mittelwerte

*/

  ifstream my_input_file("datensumme.txt"); // create and open input file
  ofstream output_file_one("mittelwerte.txt");


  if (my_input_file.is_open()) {

    int sum;
    int i = 0;
    int sum_all = 0;


    while (i < 234){
      my_input_file >> sum;
      sum_all = sum + sum_all; //sum of all the sums in datensumme

      if ((i+1)%9==0){
        //my_input_file >> sum;
        //sum_all = sum + sum_all; //sum of all the sums in datensumme
        int mean = sum_all/(i);
        output_file_one<< mean<< endl;

      }
      i++; //increment counter
    }

    my_input_file.close(); //closes input file
    output_file_one.close();


/*

Compute Variance of every 9 numbers and output into varianzen

*/


    ifstream input_file_one("datensumme.txt"); //open input file with all the sums
    ifstream input_file_two("mittelwerte.txt"); //open input file with all the means
    ofstream output_file_two("varianzen.txt");

    int j = 0; //new counter
    int k = 0;
    int mean_mittelwerte;
    int variance_sum = 0; // to sum all (a-a_bar)^2
    int variance_diff_sq = 0; // (a - a_bar)^2

    while (j<26) {

      input_file_two >> mean_mittelwerte;

      while (k<234) {
        input_file_one >> sum;
        variance_diff_sq = pow(sum - mean_mittelwerte,2); // (a- a_bar)^2
        variance_sum = variance_sum + variance_diff_sq; //sum (a-a_bar)^2
        int variance = variance_sum/(k+1);

        if ((k+1)%9==0){
          //variance_diff_sq = pow(sum - mean_mittelwerte,2); // (a- a_bar)^2
          //variance_sum = variance_sum + variance_diff_sq; //sum (a-a_bar)^2
          //int variance = variance_sum/(n+1);
          output_file_two << variance << endl;
        }
        k++;
      }
      j++;
    }

    input_file_one.close();
    input_file_two.close();
    output_file_two.close();


/*

compute mean of 26 variances and sum_means

*/

    ifstream input_file_three ("varianzen.txt");
    ifstream input_file_four ("mittelwerte.txt");

    int sum_means;
    int sum_all_means;
    int sum_variances;
    int sum_all_variances;
    int l=0;

    while (l<26) {

      input_file_four >> sum_means;
      input_file_three >> sum_variances;

      sum_all_means += sum_means;
      sum_all_variances += sum_variances;

      l++;
    }


    //cout<<sum_all_means<<endl;
    //cout << sum_all_variances<<endl;

    int mittelwerte_mean = sum_all_means/26;
    int varianzen_mean = sum_all_variances/26;

    //cout << mittelwerte_mean << endl;
    //cout << varianzen_mean << endl;


  }

   else {
     cout << "file not open" <<endl;
     return 0;
   }

}
