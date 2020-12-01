#include <iostream>
#include <zooanimal.cpp>
using namespace std;
enum scale {ounces, kilograms};

class ZooAnimal  {
    private:
      char *name;
      int cageNumber;
      int weightDate;
      int weight;
      ZooAnimal *mother;
    public:
      void Create (char*, int, int, int); // create function
      void Destroy (); // destroy function
      void changeWeight (int pounds);
      void changeWeightDate (int today);
      char* reptName ();
      int reptWeight ();
      void reptWeight (scale which);
      inline int reptWeightDate ();
      int daysSinceLastWeighed (int today);
      void isMotherOf (ZooAnimal&); //p2, ex 3
     // void Create (char *, int, int, int); //problem 1
};
void ZooAnimal::Create (char *n, int cage, int weightD, int weightW){
    this->name  = n;
    cageNumber = cage;
    weightDate = weightD;
    weight = weightW;

//    cout<<endl<<"Enjoy name: "<<name<<endl;
}
//************************ Pb2 ************************
void ZooAnimal::Destroy () {
 delete [] name;
}

// -------- member function to return the animal's name
char* ZooAnimal::reptName () {
 return name;
}

// -------- member function to return the number of days
// -------- since the animal was last weighed
int ZooAnimal::daysSinceLastWeighed(int today) {
 int startday, thisday;
 thisday = today/100*30 + today - today/100*100;
 startday = weightDate/100*30 + weightDate - weightDate/100*100;
 if (thisday < startday)
     thisday += 360;
 return (thisday-startday);
}

//************************ Part 2, ex 1 ************************
int ZooAnimal::reptWeightDate(){ //ex 2.1
    return weightDate;
}

//************************ Part 2, ex 2 ************************
void ZooAnimal::changeWeightDate(int today){  //ex 2.2
    this->weightDate = today;
}

//************************ Part 2, ex 3 ************************
void ZooAnimal::isMotherOf(ZooAnimal &childObj){
    childObj.mother = this;}

//************************ MAIN ************************
int main() {
    cout << "zoo" << endl;

    ZooAnimal bozo;
    bozo.Create ("Bozo", 408, 1027, 400);

    cout << "This animal's name is " << bozo.reptName () << endl;

    bozo.Destroy ();

    return 0;
}
