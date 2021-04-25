#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
        /*	
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here
        
        Student(string fName, string lName, int idt, vector<int> scores)
            :Person(fName, lName, idt)
        {        
            this->testScores = scores;
        }
        /*	
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here
        char calculate()
        {
            int sum = 0;
            int avg = 0;
            for (int num:testScores){
                sum += num;
            }
            if (testScores.size() != 0)
                avg = sum/testScores.size();
                
            if (avg >= 90 && avg <= 100)
                return 'O';
            else if (avg >= 80 && avg < 90)
                return 'E';
            else if (avg >= 70 && avg < 80)
                return 'A';
            else if (avg >= 55 && avg < 70)
                return 'P';
            else if (avg >= 40 && avg < 55)
                return 'D';
            else
                return 'T';
        }
};

int main() {