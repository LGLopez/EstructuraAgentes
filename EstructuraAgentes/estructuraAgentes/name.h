#ifndef NAME_H_INCLUDED
#define NAME_H_INCLUDED

#include <iostream>
#include <string>

class Name{
private:
    std::string firstName;
    std::string lastName;

public:
    Name();
    Name(const std::string& , const std::string&);
    Name(const Name&);

    std::string getFirstName() const;
    std::string getLastName() const;

    std::string toString() const;

    void setFirstName(const std::string&);
    void setLastName(const std::string&);

    Name& operator = (const Name&);

    bool operator == (const Name&) const;
    bool operator != (const Name&) const;
    bool operator >= (const Name&) const;
    bool operator > (const Name&) const;
    bool operator <= (const Name&) const;
    bool operator < (const Name&) const;

    friend std::ostream& operator << (std::ostream&, Name&);
    friend std::istream& operator >> (std::istream&, Name&);
};



#endif // NAME_H_INCLUDED
