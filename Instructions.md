
# WIB project	

 > author:tassosblackg | email:soylis.k@gmail.com*


*OpenCV* is required! 
I used OpenCV **3.1.0**

--------------------------------------------------------------------------------------------------
# Install OpenCV
------------------
To install see: https://docs.opencv.org/2.4/doc/tutorials/introduction/linux_install/linux_install.html

and this:https://www.pyimagesearch.com/2016/10/24/ubuntu-16-04-how-to-install-opencv/ 
	
	|possible error if you use the above link to solve check this: https://github.com/opencv/opencv/issues/6050

__________________________________________________________________________________________________________________

# Run 
-------

* Steps to run classification and detection of ball

   1) You need a folder with imgs for negative training  (negativeImg) 	
 
   2) You need as many positive imgs by croping the obj (showing the obj you want to recognize) that's /BallImages

* Starting to build necessary components

   3)
   ```
   cd  /files
   ```
   
      > read --README.md
 
   4) follow steps of  */files/README.md* file to create *bg.txt* and *ball.info* file

        > bg.txt will be used for creating samples and training..so is important!

   5) cd back to the main project folder (/W.I.B)
   	| cd ../
 
------------------------------------------------------------------------------------------
# IMPORTANT :
-------------


*Run steps (6->8) only if you want to **retrain** the classifier with your datashet/*

  First make sure to delete the existing directory */data*
  
  	|rm -rf /data

  Delete also *ball.info,ball.vec,bg.txt*
  
  	| rm   *ball.info,ball.vec,bg.txt*

____________________________________________________________________________________________


* Creating samples utility __[Creating training set]___	

   6) 
   ```
   opencv_createsamples  -info ball.ifo  -num 40 -w 16 -h 16 -vec ball.vec 
   ```
 
        arguments:
	----------
	
	   -**num**, *is the number of positive samples you have in the ball.info file.*
	
	  -**w** & -**h**, *the wanted size of useful object.*
	
	  -**vec**, *is the binary file that will be used for opencv_traincascade utility.*

> Notice: Alternative you can run, *opencv_createsamples  -vec ball.vec -w 16 -h 16 , to see the created sample use keyboard arrows to change between images*

* opencv_traincascade
   
   7) 
   ```
   mkdir data
   ```
   8)  
   ```
   opencv_traincascade -data data -vec ball.vec -bg bg.txt -numPos 30 -numNeg 80 -numStages 5 -w 16 -h 16 -featureType LBP 
   ```	
	
	arguments:
	-----------
	
	  -**data**, *is the folder where training-cascade .xml files are stored*
	
	  -**bg**, *is the background file with images' path*
	
	  -**numPos**, *is the number of positive images to use for training per stage (GENERAL_RULE : numPos < num) 
	
	     |where num, see creating_samples
	
	  -**numNeg**, *is the nuber of negative images are stored in bg.txt*
	
	  -**numStage**, *is the number of stages that we want our cascade to have*
	
	  -**w** & -**h**, *are the same as before*
	
	  -**featureType**, *is the type of cascade we want LBP or Haar*


* Build detect ball (see /src , wib.cpp, src/README.md)

   Last but not least..
      
      9) 
      
      ```
      *cd  /src
      ```
        >  read README.md and build the .cpp code*
      
     10)
     ```
     ./wib img_file_to_detect
     ```

-----------------------------------------------------------------------------------------------------------------

For more information about OpenCV cascade classifier check :https://docs.opencv.org/2.4.13/doc/user_guide/ug_traincascade.html
