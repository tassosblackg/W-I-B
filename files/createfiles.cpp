/* createfiles.cpp
**This program read files from directories
**concatanate directory path and file's name
** and write out every single path to a .txt file
**|--these .txt files are neccessary for opencv_createsamples utility
**|author:soylisK |email:soylis.k@gmail.com|
**/

#include <fstream>
#include <string>
#include <dirent.h>
#include <iostream>

using namespace std;

/*path and dir to negative set of images*/
string path1 = "../../negativeImg";
string dir_name1="negativeImg"; //folder where negative img files are stored

/*path, directory to positive set of images*/
string path2="../../BallImages";
string dir_name2="BallImages"; //directory where positive img files are stored

/*files' names*/
string name1="bg.txt";
string name2="ball.info";

/*this is temporary solution*///will be improved to read from user
string width="60";
string height="60";

void createtxt(string txt_name,string path,string dir_name);

int main(int argc, char const *argv[]) {
  cout<<"starting creating bg.txt and ball.txt"<<endl;
  createtxt(name1,path1,dir_name1);
  createtxt(name2,path2,dir_name2);
  cout<<"Completed."<<endl;
  return 0;
}


/*function to read files from directory and write path to .txt file*/
void createtxt(string txt_name,string path,string dir_name)
{
 string str="../../"+txt_name; 
 /*remove previous records of .txt*/
  if( (remove( str.c_str() ) != 0 )  )
    cout<< "Error deleting file.File doesn't exists.No problem\n" <<endl;
  else
    cout<< "File successfully deleted.\n" <<endl;
  /**********************************************/



  DIR *d;
  struct dirent *dir;
  d=opendir(path.c_str());

  if(d)
  {

    fstream myfile;
    while ( (dir=readdir(d))!=NULL )
    {
      string line= dir_name+"/"+(dir->d_name) ; //concat directory-name with file's namespace
      if(dir_name.compare(dir_name2)==0) //only for positive images .txt files
      {
        line=line +" 1 0 0 "+ width+" "+height; //line in file |img_path ,numberOfImgObj,width,height|
      }
      string img_name =(dir->d_name);
      //cout<<"(* " <<img_name <<")" <<endl;
      if( (img_name.compare(".")!=0) && (img_name.compare("..")!=0) ) //ignore some filenames that aren't images
      {

	       string file_p=	"../../"+txt_name; //where to save .txt files (BallRecognition Main folder)
	       myfile.open (file_p.c_str(),fstream::in | fstream::out | fstream::app);
         myfile<< line <<"\n";
         myfile.close();
      }

    }
    cout<<"File " <<txt_name  <<" created.." <<endl;
  }
  else
    cout<<"Couldn't open dir.. " <<path << endl;
}
