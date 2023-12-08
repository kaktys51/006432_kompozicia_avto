#include <iostream>
#include <string>

using std::cout;
using std::cin;

class Engine
{
protected:
	int hpower;
public:
	Engine() { std::cout << "Default engine created!" << std::endl; }
	Engine(int hp) : hpower(hp) { std::cout << "Engine created!" << std::endl; }
	Engine(Engine &a): hpower(a.hpower) { std::cout << "Engine copied!" << std::endl; }
	~Engine(){ std::cout << "Engine deleted!" << std::endl; }
	int getStats() { return hpower; }
	void setHP() 
	{ 
		cout << "Enter new engine stat:" << std::endl;
		cin >> hpower;

	}
	void setHP(int nhpower) { hpower = nhpower; }
};

class Carcase
{
protected:
	std::string color;
public:
	Carcase() { std::cout << "Default carcase created!" << std::endl; }
	Carcase(std::string col) : color(col) { std::cout << "Carcase created!" << std::endl; }
	Carcase(Carcase& a) : color(a.color) { std::cout << "Carcase copied!" << std::endl; }
	~Carcase() { std::cout << "Carcase deleted!" << std::endl; }
	std::string getStats() { return color; }
	void setCarcase() 
	{
		cout << "Enter new color:" << std::endl;
		std::getline(cin, color);
	}
	void setCarcase(std::string ncolor) { color = ncolor; }
};

class Wheels
{
protected:
	std::string name;
public:
	Wheels() { std::cout << "Default wheels created!" << std::endl; }
	Wheels(std::string nme) : name(nme) { std::cout << "Wheels created!" << std::endl; }
	Wheels(Wheels& a) : name(a.name) { std::cout << "Wheels copied!" << std::endl; }
	~Wheels() { std::cout << "Wheels deleted!" << std::endl; }
	std::string getStats() { return name; }
	void setWheels()
	{
		cout << "Enter new wheels name:" << std::endl;
		std::getline(cin, name);
	}
	void setWheels(std::string nwheels) { name = nwheels; }
};

class Car
{
private:
	std::string model;
	Engine engpart;
	Carcase paintjob;
	Wheels whls;
public:
	Car() { std::cout << "\nDefault car created!\n" << std::endl; }
	Car(std::string mdl, int hp, std::string clr, std::string whname):model(mdl), engpart(hp), paintjob(clr), whls(whname) { std::cout << "\nCustom car created!\n" << std::endl; }
	Car(Car& cpy): model(cpy.model), engpart(cpy.engpart), paintjob(cpy.paintjob), whls(cpy.whls) {}
	std::string getModel() { return model; }

	void setEngine() { engpart.setHP(); }
	void setEngine(int hp) { engpart.setHP(hp); }

	void setPaint() { paintjob.setCarcase(); }
	void setPaint(std::string paint) { paintjob.setCarcase(paint); }

	void setWheels() { whls.setWheels(); }
	void setWheels(std::string wls) { whls.setWheels(wls); }

	void printStats()
	{
		cout << std::endl;
		cout << "Car model: " << getModel() << std::endl;
		cout << "Engine power: " << engpart.getStats() <<" hp" << std::endl;
		cout << "Carcase color: " << paintjob.getStats() << std::endl;
		cout << "Wheels type: " << whls.getStats() << std::endl;
		cout << std::endl;
	}
};

int main()
{
	Car honda;

	Car mazda("Mazda", 195, "red", "Standart");
	mazda.printStats();

	Car mazda1(mazda);
	mazda1.setWheels("Fancy");
	mazda1.setPaint("Green");

	mazda1.printStats();
	return 0;
}
