#!/bin/sh 

touch main.cc                          #//this creates a file called main.cc in same repo.     
 
cat Shawn_861152954.txt > main.cc       #//this moves the stuff from the txt file to main.cc
 
                                       #//note: must run this file first in order to create the main.cc 
#cat >> main.cc << EOF 
#int main(int argc, const char** argv) 
#   {}

echo "int main(int argc, cont char*** argv)" >> main.cc 
echo "    {}" >> main.cc  

                                           
