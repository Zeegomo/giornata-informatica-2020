// Reads file GEN and outputs to ../input/ all inputs file

#include <bits/stdc++.h>

using namespace std;

const string input_path = "../input/input";
const string output_path = "../output/output";
const string ext = ".txt";

bool debug = 0;

string pad(int n, int digits) {
  string x = to_string(n);
  // we dont need to pad
  return x;
  while(x.length() < digits) x = "0" + x;
  return x;
}

string get_input_file_path(int i){
  return input_path + pad(i, 2) + ext;
}
string get_output_file_path(int i){
  return output_path + pad(i, 2) + ext;
}

const string sol_path = "../sol/";

int main(int argc, char** argv) {
  string sol_file = sol_path + "soluzione";

  // First param is different sol
  if(argc >= 2) sol_file = sol_path + (argv[1]);

  // Second param is debug mode
  if(argc >= 3 && argv[2][0] == 'D')
    debug = 1;

  ifstream gen("GEN");

  string line = "";
  int line_cnt = 0;
  int cont = 0;

  while(getline(gen, line)){
    // debug print
    if(debug) cout << "Line " << (line_cnt++) << ": " << line << '\n';

    if(line.empty() || line[0] == '#'){
      if(debug) cout << "Skip!\n";
      continue;
    }


    istringstream iss(line);
    // just check to count number of tasks
    int n, w, seed;
    if(!(iss >> seed)) break;
    // print input
    string input_file = get_input_file_path(cont);
    string output_file = get_output_file_path(cont);
    cont++;

    // debug print
    if(debug) cout << "Solving for " << input_file << " ..." << endl;

    // run solutionasd
    string sys_cmd = sol_file + " < " + input_file + " > " + output_file;
    system(sys_cmd.c_str());

    // debug print
    if(debug) cout << "File: " << output_file << " finished!\n" << endl;
  }

}