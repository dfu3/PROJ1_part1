#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ( int argc, char* argv[] )
{

    for (int a=1; a < argc; a++)
    {
        string currArg = argv[a];

        if(argv[a][0] == '-') //flag
        {
            int pos = currArg.find('=');
            if( pos == -1)
                cout << "Argument " << currArg << " is not recognized" << endl;
            else
            {
                string flag = currArg.substr(1, pos-1);
                //cout << "flag: " << flag << endl;
                if(flag == "findchar")
                    if(currArg.substr(pos, -1).size() != 1)
                        cout << "Argument " << currArg << " is poorly formed" << endl;
                if(flag == "findword")
                    if(currArg.substr(pos, -1).size() < 1) //TODO: this doesnt work
                        cout << "Argument " << currArg << " is poorly formed" << endl;
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
                    for (int i=0; i < line.size(); i++)
                    {
                        if(isspace(line[i]))
                            words++;

                        chars++;
                    }

                }

                chars+= lines;
                cout << lines << ' ' << words << ' ' << chars << ' ' << currArg << endl;

            }

        }

    }

}