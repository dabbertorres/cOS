#include "String.hpp"

namespace cos
{
	/*String::String()
	:	dataLength(DEFAULT_LENGTH),
		length(0)
	{
		data = static_cast<char*>(std::malloc(DEFAULT_LENGTH));
	}

	String::String(const char* s)
	{
		*this = s;
	}

	String::String(const String& s)
	{
		*this = s;
	}

	String& String::operator=(const char* s)
	{
		unsigned int lengthOfS = getLength(s);

		if(lengthOfS > dataLength)
		{
			std::free(data);
			data = static_cast<char*>(std::malloc(lengthOfS));
		}

		int i = 0;

		for(; s != '\0'; i++)
		{
			data[i] = s[i];
		}

		length = i;
	}

	String& String::operator=(const String& s)
	{
		*this = s.getCstr();
	}

	String::~String()
	{
		if(data)
			delete[] data;
	}

	// modifiers
	void String::clear()
	{
		length = 0;
	}

	String& String::append(char)
	{

	}

	String& String::append(const char*)
	{

	}

	String& String::append(const String&)
	{

	}

	String& String::insert(unsigned int, char)
	{

	}

	String& String::insert(unsigned int, const char*)
	{

	}

	String& String::insert(unsigned int, const String&)
	{

	}

	String& String::erase(unsigned int)
	{

	}

	String& String::erase(unsigned int, unsigned int)
	{

	}

	String& String::replace(unsigned int, char)
	{

	}

	String& String::replace(unsigned int, unsigned int, const char*)
	{

	}

	String& String::replace(unsigned int, unsigned int, const String&)
	{

	}

	// operations
	unsigned int String::find(char, unsigned int) const
	{

	}

	unsigned int String::find(const char*, unsigned int) const
	{

	}

	unsigned int String::find(const String&, unsigned int) const
	{

	}

	unsigned int String::rfind(char, unsigned int) const
	{

	}

	unsigned int String::rfind(const char*, unsigned int) const
	{

	}

	unsigned int String::rfind(const String&, unsigned int) const
	{

	}

	String String::substr(unsigned int, unsigned int) const
	{

	}

	// information
	unsigned int String::size() const
	{

	}*/

	unsigned int String::getLength(const char* s)
	{
		int len = 0;

		for(; s[len] != 0; ++len);

		return len;
	}

	// accessors
	/*char& String::operator[](unsigned int)
	{

	}

	const char& String::operator[](unsigned int) const
	{

	}

	// testers
	bool String::empty() const
	{

	}


	// concatenation
	String operator+(char, const String&)
	{

	}

	String operator+(const String&, char)
	{

	}

	String operator+(const char*, const String&)
	{

	}

	String operator+(const String&, const char*)
	{

	}

	String operator+(const String&, const String&)
	{

	}

	// comparison operators
	bool operator==(const char*, const String&)
	{

	}

	bool operator==(const String&, const char*)
	{

	}

	bool operator==(const String&, const String&)
	{

	}

	bool operator!=(const char*, const String&)
	{

	}

	bool operator!=(const String&, const char*)
	{

	}

	bool operator!=(const String&, const String&)
	{

	}

	const char* String::getCstr() const
	{
		return data;
	}*/
}
