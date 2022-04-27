#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector <int64_t> rozklad(int64_t n)
{
	vector <int64_t> res;

	if(-1 <= n && n <= 1) return res.push_back(n), res;
	if(n < 0) res.push_back(-1);
	
	while(n % 2 == 0) res.push_back(2), n>>=1;
	if(n < 0) n *= (-1); // nie mozna od razu bo INT64_MIN == -INT64_MAX-1

	int64_t sq = sqrt(n);
	for(int64_t i = 3; i <= sq; i+=2)
			while(n % i == 0) res.push_back(i), n/=i, sq = sqrt(n);
	
	if(n != 1) res.push_back(n);
	return res;
}

int main(int argc, char *argv[])
{
	if(argc == 1) return cerr << "Użycie: ./faktoryzacja <ciąg liczb>\n", 0;
	
	for(int i = 1; i < argc; i++)
	{
		try
		{
			int64_t x = stoll(argv[i]);
			cout << x << " = ";

			auto v = rozklad(x);
			for(auto j : v) cout << j << "*";
			cout << "\b \n";
		} 
		catch(invalid_argument &e) 
		{
			cerr << "Niepoprawny argument: " << argv[i] << "\n";
		}
		catch(out_of_range &e)
		{
			cerr << "Liczba poza przedzialem: " << argv[i] << "\n";
		}
	}
}
