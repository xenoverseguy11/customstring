#include <iostream>
#include <cstring>

class String
{
private:
    char* data;
    int length;

public:
    String(const char* source)
    {
        length = strlen(source) + 1;
        data = new char[length];
        for (int i = 0; i < length; i++)
        {
            data[i] = source[i];
        }
    }

    void copy(const String& source)
    {
        delete[] data;
        length = source.length;
        if (source.data)
        {
            data = new char[length];
            for (int i = 0; i < length; i++)
            {
                data[i] = source.data[i];
            }
        }
        else
        {
            data = nullptr;
        }
    }

    String(const String& source)
    {
        copy(source);
    }

    String& operator= (const String& source)
    {
        if (this != &source)
        {
            copy(source);
        }

        return *this;
    }
    
    ~String()
    {
        delete[] data;
    }

    friend std::ostream& operator<< (std::ostream& out, const String& string)
    {
        out << string.data;
        return out;
    }
};
