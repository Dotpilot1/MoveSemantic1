#include "MoveSemantic.h"

Barber::Barber():name{nullptr}
{
}

Barber::Barber(char* customer):name{customer}
{
	
}

Barber::~Barber()
{
	delete[]name;
}


Barber::Barber( Barber& customer)
{
    if (&customer == this)
        delete name;

	name = customer.name;
	customer.name = nullptr;
}

Barber::Barber( Barber&& customer)
{
    if (&customer == this)
        delete name;

    name = customer.name;
    customer.name = NULL;
}

Barber& Barber::operator=( Barber& guest)
{

	
}

Barber& Barber::operator=( char* name_)
{
	
}

Barber& Barber::operator=( Barber&& B)
{
	
}

void Barber::setName(char* name_)
{
	name = name_;
}

char* Barber::getName() const
{
	return name;
}

bool Barber::operator==(const Barber& guest) const
{
	return false;
}

istream& operator>>(istream& input, Barber& customer)
{
	
}

ostream& operator<<(ostream& output, const Barber& customer)
{
	
}


A(A&& other)
    : mData(NULL)
    , mLength(0)
{
    std::cout << "A(A&&). length = "
        << other.mLength << ". Moving resource.\n";

    // Gelen veri i�aret�isinden ilgili adresi ve boyutu al
    mData = other.mData;
    mLength = other.mLength;

    // Kaynak i�aret�i taraf�ndan adreslenen kayna�� sal�ver.
    // Bunu yapmaz isek bellek birden fazla say�da bo�alt�lmaya �al���l�r
    other.mData = NULL;
    other.mLength = 0;
}

// Ta��ma atanma operat�r�
A& operator=(A&& other)
{
    std::cout << "operator=(A&&). length = "
        << other.mLength << "." << std::endl;

    if (this != &other)
    {
        // Mevcut verileri bo�alt
        delete[] mData;

        // Gelen veri i�aret�isinden ilgili adresi ve boyutu al
        mData = other.mData;
        mLength = other.mLength;

        // Kaynak i�aret�i taraf�ndan adreslenen kayna�� sal�ver.
        // Bunu yapmaz isek bellek birden fazla say�da bo�alt�lmaya �al���l�r
        other.mData = NULL;
        other.mLength = 0;
    }
    return *this;
}
