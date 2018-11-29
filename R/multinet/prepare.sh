mkdir src
cd src
cp -r ../../../C++/include .
mkdir multinet
cp -r ../../../C++/src/* multinet
cp -r ../../../C++/ext/eclat .
cp -r ../../../C++/ext/infomap .
#find * | grep cpp | sed 's/\//_/g' > f2
#paste -d" " f1 f2 > f3
#chmod +x f3
#./f3
#rm -rf multinet
#rm f?
cp ../C++/* .

# build Makevars
printf "SOURCES=" > sources
ls | grep "\.cpp$" >> sources
find multinet/* | grep "\.cpp$" >> sources
find infomap/* | grep "\.cpp$" >> sources
find eclat/* | grep "\.c$" >> sources
printf "OBJECTS=" > objects
ls | grep "\.cpp$" | sed 's/cpp$/o/g' >> objects
find multinet/* | grep "\.cpp$" | sed 's/cpp$/o/g' >> objects
find infomap/* | grep "\.cpp$" | sed 's/cpp$/o/g' >> objects
find eclat/* | grep "\.c$" | sed 's/c$/o/g' >> objects
printf "\n" >> Makevars
tr '\n' ' ' < sources >> Makevars
printf "\n" >> Makevars
tr '\n' ' ' < objects >> Makevars
printf "\n" >> Makevars.win
tr '\n' ' ' < sources >> Makevars.win
printf "\n" >> Makevars.win
tr '\n' ' ' < objects >> Makevars.win
rm sources
rm objects
# copy external libraries
mkdir lib
cp -r ../../../C++/ext/eigen3 lib
cp -r ../../../C++/ext/infomap lib
# cp -r ../../C++/ext/spectra lib
# cp -r ../../multinet/lib/dlib/dlib lib
# copying the .h files from the eclat library
mkdir lib/eclat
find ../../../C++/ext/eclat* | grep "\\.h$" | sed 's/^/cp /g' | sed 's/$/ lib\/eclat/g' > f
chmod +x f
./f
rm f
#cp -r ../../multinet/lib/spectra/* .
