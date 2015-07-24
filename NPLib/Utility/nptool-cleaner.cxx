#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<dlfcn.h>
#include<dirent.h>
#include"NPDetectorFactory.h"
int main(int argc , char** argv){
  // Go to npl
  string path = getenv("NPTOOL");
  path += "/NPLib/";
  string cd = "cd " + path;
  int return_value = system(cd.c_str());
  
  if(return_value!=0){
    std::cout << "Fail to access NPLib directory " << return_value << std::endl;
    exit(1);
  }

  string answer;
  bool check = true;

  std::cout << "*********************************" << std::endl;
  std::cout << "You are about to clean NPLib" << std::endl;
  std::cout << "the folder will be revert to pre cmake stage" << std::endl;
  
  while(check){
    std::cout << "Do you want to proceed ? (y/n)" << std::endl;
    std::cin >> answer;
    if(answer =="n" || answer =="N")
      return 0;

    else if(answer =="y" || answer =="Y"){
      std::cout << "Proceed" << std::endl;
      check = false;
    }
    else{
    std::cout << "Reply by y (yes) or n (no)" << std::endl;
    }
  }

  std::string command,command2;
  // Dict     
  command = "ls ./*/*Dict* > /dev/null 2>/dev/null";
  return_value=system(command.c_str());             
  if(!return_value){
    command2 = "rm ./*/*Dict* > /dev/null 2>/dev/null";
    return_value=system(command2.c_str());   
  }  
   // DetectorClassList
  command = "ls ./DetectorClassList.txt > /dev/null 2>/dev/null";
  return_value=system(command.c_str());             
  if(!return_value){
    command2 = "rm ./DetectorClassList.txt > /dev/null 2>/dev/null";
    return_value=system(command2.c_str());   
  }
  
  // pcm 
  command = "ls ./*/*.pcm > /dev/null 2>/dev/null";
  return_value=system(command.c_str());             
  if(!return_value){
    command2 = "rm ./*/*.pcm > /dev/null 2>/dev/null";
    return_value=system(command2.c_str());   
  }
 
  // rootmap 
  command = "ls ./*/*.rootmap > /dev/null 2>/dev/null";
  return_value=system(command.c_str());             
  if(!return_value){
    command2 = "rm ./*/*.rootmap > /dev/null 2>/dev/null";
    return_value=system(command2.c_str());   
  }
  
   // Makefile 
  command = "ls ./*/Makefile > /dev/null 2>/dev/null";
  return_value=system(command.c_str());             
  if(!return_value){
    command2 = "rm ./*/Makefile > /dev/null 2>/dev/null";
    return_value=system(command2.c_str());   
  }
   // ninja
  command = "ls ./*.ninja > /dev/null 2>/dev/null";
  return_value=system(command.c_str());             
  if(!return_value){
    command2 = "rm ./*.ninja > /dev/null 2>/dev/null";
    return_value=system(command2.c_str());   
  }
   // lib 
  command = "ls ./lib/*> /dev/null 2>/dev/null";
  return_value=system(command.c_str());             
  if(!return_value){
    command2 = "rm ./lib/* > /dev/null 2>/dev/null";
    return_value=system(command2.c_str());   
  }
   // include
  command = "ls ./include/* > /dev/null 2>/dev/null";
  return_value=system(command.c_str());             
  if(!return_value){
    command2 = "rm ./include/* > /dev/null 2>/dev/null";
    return_value=system(command2.c_str());   
  }
   // CMakeFiles
  command = "ls ./*/CMakeFiles > /dev/null 2>/dev/null";
  return_value=system(command.c_str());             
  if(!return_value){
    command2 = "rm -Rf ./*/CMakeFiles > /dev/null 2>/dev/null";
    return_value=system(command2.c_str());   
    command2 = "rm -Rf ./CMakeFiles > /dev/null 2>/dev/null";
    return_value=system(command2.c_str());   

  }
  
  // CMakeCache
  command = "ls ./CMakeCache.txt > /dev/null 2>/dev/null";
  return_value=system(command.c_str());             
  if(!return_value){
    command2 = "rm ./CMakeCache.txt > /dev/null 2>/dev/null";
    return_value=system(command2.c_str());   
  }

  // liblist 
  command = "ls ./liblist > /dev/null 2>/dev/null";
  return_value=system(command.c_str());             
  if(!return_value){
    command2 = "rm ./liblist > /dev/null 2>/dev/null";
    return_value=system(command2.c_str());   
  }

  // install manifest 
  command = "ls ./install_manifest > /dev/null 2>/dev/null";
  return_value=system(command.c_str());             
  if(!return_value){
    command2 = "rm ./install_manifest > /dev/null 2>/dev/null";
    return_value=system(command2.c_str());   
  }
   // cmake
  command = "ls ./*/cmake_install.cmake > /dev/null 2>/dev/null";
  return_value=system(command.c_str());             
  if(!return_value){
    command2 = "rm ./*/cmake_install.cmake > /dev/null 2>/dev/null";
    return_value=system(command2.c_str());   
  }
   // so 
  command = "ls ./*/*.so > /dev/null 2>/dev/null";
  return_value=system(command.c_str());             
  if(!return_value){
    command2 = "rm ./*/*.so > /dev/null 2>/dev/null";
    return_value=system(command2.c_str());   
  }
   // dylib
  command = "ls ./*/*.dylib > /dev/null 2>/dev/null";
  return_value=system(command.c_str());             
  if(!return_value){
    command2 = "rm ./*/*.dylib > /dev/null 2>/dev/null";
    return_value=system(command2.c_str());   
  }
    //bin 
  command = "ls ./bin/* > /dev/null 2>/dev/null";
  return_value=system(command.c_str());             
  if(!return_value){
    command2 = "rm ./bin/* > /dev/null 2>/dev/null";
    return_value=system(command2.c_str());   
  }
  
  return 0;
}