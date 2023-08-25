/*
Student Name: Gia Bach Nhu
Student Number: 7547821
Lab 2
Task 2
*/
#include <iostream>
#include <fstream>
using namespace std;

void read_word_by_word(string filename) {
   fstream file;
   string word;
   file.open(filename.c_str());

   if (!file.is_open()) {
       cout << "Error opening file." << endl;
       return;
   }

   int line_number = 1; // Initialize line number

   while (file >> word) {
      cout << line_number << ": " << word << endl;
      line_number++;
   }

   file.close();
}

int main() {
   string name;
   cout << "Enter filename: ";
   cin >> name;
   read_word_by_word(name);
   return 0;
}
