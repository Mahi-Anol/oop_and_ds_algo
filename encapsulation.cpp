#include<iostream>
#include<iomanip>
using namespace std;

class instrument{

    private:
    string name;
    string colour;
    int Size;
    static int n_obj;

    public:

    instrument(){
        (*this).name="Not declared";
        this->colour="Not declared";
        this->Size=-1;
        n_obj++;
        };

    instrument(string name,string colour,int Size){
        this->name=name;
        this->colour=colour;
        this->Size=Size;
        n_obj++;
    };

    void display(void) const
    {
        Size=4;
        cout<<"Instrument Number = "<<n_obj<<endl;
        cout<<"Name = "<<name<<endl;
        cout<<"colour= "<<colour<<endl;
        cout<<"Size = "<<Size<<endl;
        cout<<endl<<endl<<endl;
    }
};

int instrument::n_obj=0;


int main(void)
{
  cout<<"He welcome to oop"<<endl;
  cout<<"Lets try encapsulation"<<endl;
  cout<<setw(20)<<"******"<<endl;
  cout<<endl<<endl;

  instrument b("Guitar","Red",3);
  b.display();

  instrument c,d,e;

  e.display();

  return 0;
}
