#include "CLAID.hpp"
#include "Utilities/ArgumentParser.hpp"

int main(int argc, char** argv) 
{
    ArgumentParser parser(argc, argv);

    std::string configPath = "";
    parser.add_argument<std::string>("path", configPath, "");

    if(configPath == "")
    {
        printf("Error, no path to XML configuration specified.\n"
        "Please use ./MyApplication -path path/to/xml/file.\n");
        exit(0);
    }

    CLAID_RUNTIME->loadFromXML(configPath);
    CLAID_RUNTIME->start();
}