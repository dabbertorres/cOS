#ifndef COS_STRING_HPP
#define COS_STRING_HPP

namespace cos
{
	class String
	{
		public:
		/*	String();
			String(const char* s);
			String(const String& s);

			String& operator=(const char* s);
			String& operator=(const String& s);

			~String();

			// modifiers
			void clear();
			String& append(char c);
			String& append(const char* s);
			String& append(const String& s);
			String& insert(unsigned int pos, char c);
			String& insert(unsigned int pos, const char* s);
			String& insert(unsigned int pos, const String& s);
			String& erase(unsigned int pos);
			String& erase(unsigned int pos, unsigned int len);
			String& replace(unsigned int pos, char c);
			String& replace(unsigned int pos, unsigned int len, const char* s);
			String& replace(unsigned int pos, unsigned int len, const String& s);

			// operations
			// c/s = stuff to replace with
			// pos = position to start search at
			unsigned int find(char c, unsigned int pos) const;
			unsigned int find(const char* s, unsigned int pos) const;
			unsigned int find(const String& s, unsigned int pos) const;

			unsigned int rfind(char, unsigned int) const;
			unsigned int rfind(const char*, unsigned int) const;
			unsigned int rfind(const String&, unsigned int) const;

			String substr(unsigned int, unsigned int) const;

			// information
			unsigned int size() const;*/
			static unsigned int getLength(const char*);

			// accessors
			/*char& operator[](unsigned int);
			const char& operator[](unsigned int) const;

			// testers
			bool empty() const;

			// concatenation
			friend String operator+(char, const String&);
			friend String operator+(const String&, char);
			friend String operator+(const char*, const String&);
			friend String operator+(const String&, const char*);
			friend String operator+(const String&, const String&);

			// comparison operators
			friend bool operator==(const char*, const String&);
			friend bool operator==(const String&, const char*);
			friend bool operator==(const String&, const String&);

			friend bool operator!=(const char*, const String&);
			friend bool operator!=(const String&, const char*);
			friend bool operator!=(const String&, const String&);

		private:
			const char* getCstr() const;

			static constexpr unsigned int DEFAULT_LENGTH = 64;

			char* data;
			unsigned int dataLength;
			unsigned int length;*/
	};
}

#endif // COS_STRING_HPP
