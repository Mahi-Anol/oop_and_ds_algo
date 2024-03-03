#include<iostream>
#include<iomanip>
using namespace std;

class instrument{

    private:
    string name;
    string colour;
    int Size;
    static int n_obj;
    const int value;

    public:

    instrument():value(10000){};

    instrument(string,string,int,int);

    void display(void) const
    {
        cout<<"Instrument Number = "<<n_obj<<endl;
        cout<<"Name = "<<name<<endl;
        cout<<"colour= "<<colour<<endl;
        cout<<"Size = "<<Size<<endl;
        cout<<"Value = "<<value<<endl;
        cout<<endl<<endl<<endl;
    }
};

int instrument::n_obj=0;

instrument::instrument(string name,string colour,int Size,int value):name(name),colour(colour),Size(Size),value(value)
{
}


int main(void)
{
  cout<<"He welcome to oop"<<endl;
  cout<<"Lets try encapsulation"<<endl;
  cout<<setw(20)<<"******"<<endl;
  cout<<endl<<endl;

  instrument b("Guitar","Red",3,50000);
  b.display();

  instrument c,d,e;

  e.display();

  return 0;
}
