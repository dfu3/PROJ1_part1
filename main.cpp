#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <typeinfo>
using namespace std;

int main ( int argc, char* argv[] )
{

    for (int a=1; a < argc; a++)
    {
        string currArg = argv[a];

        if(argv[a][0] == '-') //flag
        {

            int pos = currArg.find('=');

            string flag = currArg.substr(1, 8);
            //cout << "flag: " << flag << endl;

            if(flag == "findchar")
            {
                if((pos == -1) || currArg.substr(pos, -1).size() != 1)
                    cout << "Argument " << currArg << " is poorly formed" << endl;
            }
            else if(flag == "findword")
            {
                if((pos == -1) || currArg.substr(pos, -1).size() < 1)
                    cout << "Argument " << currArg << " is poorly formed" << endl;
            }
            else
            {
                cout << "Argument " << currArg << " is not recognized" << endl;
            }

        }
        else //file
        {
            ifstream the_file( currArg, ios::in );
            int lines = 0;
            int words = 0;
            int chars = 0;

            if ( !the_file.is_open() )
                cout << "File " << currArg << " is not found" << endl;

            else
            {
                string line;

                while( getline(the_file, line))
                {
                    lines++;
                    stringstream ss;
                    ss.str(line);
                    string word;

                    for (int i = 0; ss >> word; i++)
                        words++;

                    chars+= line.size();

                }

                chars+= lines;
                //cout << lines << ' ' << words << ' ' << chars << ' ' << currArg << endl;
                cout << setw(12) << right << lines << setw(12) << right << words << setw(12) << right << chars << ' ' << left << currArg << endl;

            }

        }

    }

}