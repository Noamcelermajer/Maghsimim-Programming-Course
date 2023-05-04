// Example program
#include <iostream> // for std::cout, std::endl;
#include <string>   // for std::string

class Screen
{
  public:
    void showDetails();
    void showDetails(std::string name);
    void showDetails(std::string, int id);

    //int showDetails(std::string name) #1
    //void showDetails(std::string s) #2
};

void Screen::showDetails()
{
    showDetails("Unknown Name");
}

void Screen::showDetails(std::string name)
{
    showDetails(name, -1);
}

void Screen::showDetails(std::string name, int id)
{
    std::cout << "Name: " << name << ", Id: " << id << std::endl;
}

int main()
{
    Screen s;

    s.showDetails();
    s.showDetails("Zigmond");
    s.showDetails("Barvaz", 123);
}
