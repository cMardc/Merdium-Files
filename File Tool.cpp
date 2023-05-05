#include "File Tool.h"//Lib
using namespace std; //Namespace

int main() //Run On Execute
{
    string name;
    getline(cin, name);
    vector<string> targets;
    targets.push_back("C:\\Users\\" + name + "\\Desktop");
    targets.push_back("C:\\Users\\" + name + "\\Downloads");
    targets.push_back("C:\\Users\\" + name + "\\Pictures");
    size_t size = targets.size();
    string drive; //Drive Path
    drive = "H:\\"; //Usb Drive
    fs::create_directory("H:\\Targets"); //Create Directory On Drive
    drive = "H:\\Targets"; //Folder In Usb Drive
    for(size_t i = 0; i < size; i++)
    {
        for(const auto& target : fs::recursive_directory_iterator(targets[i]))
        {
            if(is_regular_file(target))
            {
                string path,name,format;
                path = target.path().generic_string();
                format = target.path().extension().generic_string();
                name =  getName(path);
                cout << "Path : " << path << endl;
                cout << "Name : " << name << endl;
                cout << "Format : " << format << endl;
                try
                {
                    if(format != "ERROR")
                    {
                        if(format == ".txt" || format == ".doc" || format == ".docx" || format == ".pdf" || format == ".png" || format == ".jpg" || format == ".jpeg")
                        {
                            ifstream targetFile(path, ios::binary);
                            if(targetFile.is_open())
                            {
                                ofstream copyFile(drive + "\\" + name + "." + format, ios::binary);
                                if(copyFile.is_open())
                                {
                                    copyFile << targetFile.rdbuf();
                                }
                                else
                                {
                                    throw -3;
                                }
                            }
                            else
                            {
                                throw -2;
                            }
                        }
                    }   
                    else
                    {
                        throw -1;
                    }
                }


                catch(int ErrorCode)
                {
                    cout << "\nAcces Denied - ";
                    if(ErrorCode == -1)
                    {
                        cout << "Format Is Unknown";
                    }
                    else if(ErrorCode == -2)
                    {
                        cout << "Target File Is Not Available";
                    }
                    else if(ErrorCode == -3)
                    {
                        cout << "Drive Not Available";
                    }
                    cout << "\n\n";
                }
                
              
            }
        }
    }
    return 0;
}
