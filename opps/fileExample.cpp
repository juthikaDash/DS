#include<iostream>
#include<filesystem>
#include<fstream>
#include<string>
//namespace fs = std::filesystem;
using namespace std;
namespace fs = std::filesystem;

void readfile()
{

    fs::path filePath = "example.txt";

    if (fs::exists(filePath)) {
        std::ifstream file(filePath);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::cout << line << std::endl;
            }
            file.close();
        } else {
            std::cout << "Unable to open file" << std::endl;
        }
    } else {
        std::cout << "File does not exist" << std::endl;
    }
}

void writefile(){
    fs::path filePath = "output.txt";

    std::ofstream file(filePath);
    if (file.is_open()) {
        file << "This is a line.\n";
        file << "This is another line.\n";
        file.close();
        std::cout << "Successfully wrote to " << filePath << std::endl;
    } else {
        std::cout << "Unable to open file for writing" << std::endl;
    }
}
int main(){
    //create dir
    fs::path path ="./test" ;
    if(fs::create_directories(path)){
        cout<< "'dir create : ["<< path << "]"<<endl;
    }
    //create file
    fs::path filepath = path/"test.txt";
    std::ofstream file(filepath);
    if(file.is_open()){
        file << "hello , filesystem";
        file.close();
        cout<<"file created"<<endl;
    }

    //check if file exist
    if(fs::exists(filepath)){
        cout<<"file exit"<<endl;
    }

    //filesize
    cout<< "File size : "<<fs::file_size(filepath)<<endl;

    //rename
    fs::path newfilepath = path/"rename.txt";
    fs::rename(filepath, newfilepath);
    cout<<"file path renamed"<<endl;

    //copy
    fs::path copypath = path/"copy5.txt";
    if(!fs::exists(copypath)){
        fs::copy_file(newfilepath,copypath);
    }
    cout<<"copy created"<<endl;
    //show the files
    cout<<"Files in path :"<<path<<endl;
    for(const auto& f : fs::directory_iterator(path))
    {
        cout<<"\t"<<f.path().filename()<<endl;
    }
    //delete
    fs::remove(path);
    cout<<"removed the copied file:"<<path<<endl;

    

    return 0;
}