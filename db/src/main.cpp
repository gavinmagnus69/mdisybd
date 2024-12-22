#include <iostream>
#include "Builder/Builder.h"

int main(int argc, char** argv) {
    std::filesystem::path path = "/home/roman/Desktop/bsuir/mdisybd/db/config/Prod.yml";
    Builder().createApplication(path).Run();
}